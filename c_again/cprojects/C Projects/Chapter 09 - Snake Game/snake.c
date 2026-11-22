/*
 * Chapter 9 - Snake Game Using the Console
 * snake.c - real-time terminal Snake game.
 *
 * Compile: gcc snake.c -o snake
 * Run:     ./snake
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#define ROWS 20
#define COLS 40
#define MAX_SNAKE_LENGTH 100

typedef struct {
    int x, y;
} Point;

static Point snake[MAX_SNAKE_LENGTH];
static int snake_length = 5;
static Point food;
static int score = 0;
static int running = 1;

static int dir_x = 0;
static int dir_y = 1;

static struct termios orig_tio;

void restore_terminal(void) {
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_tio);
}

void enable_non_blocking_input(void) {
    struct termios ttystate;
    tcgetattr(STDIN_FILENO, &ttystate);
    orig_tio = ttystate;
    atexit(restore_terminal);
    ttystate.c_lflag &= ~ICANON;
    ttystate.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
}

char get_input(void) {
    char ch;
    if (read(STDIN_FILENO, &ch, 1) != -1) return ch;
    return 0;
}

char get_direction_input(void) {
    char ch = get_input();
    if (ch == '\033') {
        get_input(); /* skip '[' */
        ch = get_input();
        switch (ch) {
            case 'A': return 'U';
            case 'B': return 'D';
            case 'C': return 'R';
            case 'D': return 'L';
        }
    }
    return 0;
}

void init_game(void) {
    srand(time(NULL));
    snake_length = 5;
    score = 0;
    dir_x = 0; dir_y = 1;
    for (int i = 0; i < snake_length; i++) {
        snake[i].x = ROWS / 2;
        snake[i].y = COLS / 2 - i;
    }
    food.x = rand() % ROWS;
    food.y = rand() % COLS;
}

void draw_board(void) {
    printf("\x1b[2J\x1b[H"); /* clear screen, cursor home */
    printf("Score: %d  (Arrow keys to move, Ctrl+C to quit)\n\n", score);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int is_snake = 0;
            for (int k = 0; k < snake_length; k++) {
                if (snake[k].x == i && snake[k].y == j) {
                    is_snake = 1;
                    printf(k == 0 ? "O" : "o");
                    break;
                }
            }
            if (!is_snake) {
                if (food.x == i && food.y == j) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    fflush(stdout);
}

void move_snake(Point dir) {
    Point new_head = {snake[0].x + dir.x, snake[0].y + dir.y};

    /* Wall collision */
    if (new_head.x < 0 || new_head.x >= ROWS ||
        new_head.y < 0 || new_head.y >= COLS) {
        draw_board();
        printf("\nGame Over! Hit the wall. Final Score: %d\n", score);
        running = 0;
        return;
    }

    /* Self collision */
    for (int i = 0; i < snake_length; i++) {
        if (snake[i].x == new_head.x && snake[i].y == new_head.y) {
            draw_board();
            printf("\nGame Over! Hit yourself. Final Score: %d\n", score);
            running = 0;
            return;
        }
    }

    /* Shift body forward */
    for (int i = snake_length; i > 0; i--) {
        snake[i] = snake[i - 1];
    }
    snake[0] = new_head;

    if (new_head.x == food.x && new_head.y == food.y) {
        if (snake_length < MAX_SNAKE_LENGTH) snake_length++;
        score++;
        food.x = rand() % ROWS;
        food.y = rand() % COLS;
    }
}

void run_game(void) {
    enable_non_blocking_input();

    while (running) {
        char input = get_direction_input();
        if (input == 'U' && dir_x != 1)      { dir_x = -1; dir_y = 0; }
        else if (input == 'D' && dir_x != -1) { dir_x = 1;  dir_y = 0; }
        else if (input == 'L' && dir_y != 1)  { dir_x = 0;  dir_y = -1; }
        else if (input == 'R' && dir_y != -1) { dir_x = 0;  dir_y = 1; }

        Point dir = {dir_x, dir_y};
        move_snake(dir);
        draw_board();

        /* Speed increases with score */
        int delay = 150000 - score * 2000;
        if (delay < 40000) delay = 40000;
        usleep(delay);
    }
}

int main(void) {
    printf("=== Snake Game ===\n");
    printf("Use arrow keys to move. Eat * to grow.\n");
    printf("Press Enter to start...\n");
    getchar();

    init_game();
    run_game();

    printf("Thanks for playing!\n");
    return 0;
}
