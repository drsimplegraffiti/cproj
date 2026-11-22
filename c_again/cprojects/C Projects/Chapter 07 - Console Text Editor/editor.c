/*
 * Chapter 7 - Console-Based Text Editor
 * editor.c - minimal terminal text editor similar to nano.
 *
 * Features: raw-mode input, arrow-key navigation, insert/delete chars,
 * load/save files, ANSI escape screen control.
 *
 * Compile: gcc editor.c -o editor
 * Run:     ./editor [filename]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 256

static struct termios orig_termios;
static char* lines[MAX_LINES];
static int line_count = 0;
static int cursor_x = 0;
static int cursor_y = 0;

void disable_raw_mode(void) {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enable_raw_mode(void) {
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disable_raw_mode);
    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON | ISIG);
    raw.c_iflag &= ~(IXON | ICRNL);
    raw.c_oflag &= ~(OPOST);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int read_key(void) {
    char c;
    if (read(STDIN_FILENO, &c, 1) != 1) return 0;
    if (c == '\x1b') {
        char seq[2];
        if (read(STDIN_FILENO, &seq[0], 1) != 1) return '\x1b';
        if (read(STDIN_FILENO, &seq[1], 1) != 1) return '\x1b';
        if (seq[0] == '[') {
            switch (seq[1]) {
                case 'A': return 1002; /* UP */
                case 'B': return 1003; /* DOWN */
                case 'C': return 1001; /* RIGHT */
                case 'D': return 1000; /* LEFT */
            }
        }
        return '\x1b';
    }
    return (unsigned char)c;
}

void clear_screen(void) {
    write(STDOUT_FILENO, "\x1b[2J", 4);
    write(STDOUT_FILENO, "\x1b[H", 3);
}

void move_cursor(int x, int y) {
    char buf[32];
    int n = snprintf(buf, sizeof(buf), "\x1b[%d;%dH", y + 1, x + 1);
    write(STDOUT_FILENO, buf, n);
}

void load_file(const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) return;
    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, fp)) {
        if (line_count >= MAX_LINES) break;
        size_t len = strlen(buffer);
        lines[line_count] = malloc(len + 1);
        if (lines[line_count]) {
            strcpy(lines[line_count], buffer);
            line_count++;
        }
    }
    fclose(fp);
    if (line_count == 0) {
        lines[0] = strdup("");
        line_count = 1;
    }
}

void draw_rows(void) {
    for (int i = 0; i < line_count; i++) {
        write(STDOUT_FILENO, lines[i], strlen(lines[i]));
        if (i < line_count - 1) write(STDOUT_FILENO, "\r\n", 2);
    }
}

void insert_char(int row, int col, char c) {
    if (row < 0 || row >= line_count) return;
    int len = strlen(lines[row]);
    if (len + 1 >= MAX_LINE_LENGTH) return;
    for (int i = len; i >= col; i--) {
        lines[row][i + 1] = lines[row][i];
    }
    lines[row][col] = c;
    lines[row][len + 1] = '\0';
}

void delete_char(int row, int col) {
    if (row < 0 || row >= line_count) return;
    int len = strlen(lines[row]);
    if (col < 0 || col >= len) return;
    for (int i = col; i < len; i++) {
        lines[row][i] = lines[row][i + 1];
    }
}

void save_file(const char* filename) {
    FILE* fp = fopen(filename, "w");
    if (!fp) return;
    for (int i = 0; i < line_count; i++) {
        fputs(lines[i], fp);
    }
    fclose(fp);
    printf("\nFile saved: %s\n", filename);
}

void editor_loop(const char* filename) {
    while (1) {
        clear_screen();
        draw_rows();
        move_cursor(cursor_x, cursor_y);
        fflush(stdout);

        int c = read_key();

        if (c == 17) break;                 /* Ctrl + Q to quit */
        else if (c == 19) save_file(filename); /* Ctrl + S to save */
        else if (c == 1000) {               /* LEFT */
            if (cursor_x > 0) cursor_x--;
        } else if (c == 1001) {             /* RIGHT */
            if (cursor_x < (int)strlen(lines[cursor_y])) cursor_x++;
        } else if (c == 1002) {             /* UP */
            if (cursor_y > 0) cursor_y--;
        } else if (c == 1003) {             /* DOWN */
            if (cursor_y < line_count - 1) cursor_y++;
        } else if (c == 127 || c == 8) {    /* Backspace */
            if (cursor_x > 0) {
                delete_char(cursor_y, cursor_x - 1);
                cursor_x--;
            }
        } else if (c == 13 || c == 10) {    /* Enter - new line */
            (void)0;
        } else if (c >= 32 && c < 127) {    /* Printable char */
            insert_char(cursor_y, cursor_x, (char)c);
            cursor_x++;
        }
    }
}

int main(int argc, char* argv[]) {
    const char* filename = (argc > 1) ? argv[1] : "output.txt";

    enable_raw_mode();
    load_file(filename);
    editor_loop(filename);

    /* cleanup allocated lines */
    for (int i = 0; i < line_count; i++) {
        free(lines[i]);
    }

    printf("\nEditor exited.\n");
    return 0;
}
