/*
 * Chapter 8 - Multi-Player Tic-Tac-Toe Game
 * tictactoe.c - terminal Tic-Tac-Toe with scoreboard persistence.
 *
 * Compile: gcc tictactoe.c -o tictactoe
 * Run:     ./tictactoe
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 3
#define MAX_NAME 50

static char board[SIZE][SIZE];

void init_board(void) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = ' ';
}

void draw_board(void) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf("   ");
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("  -----------\n");
    }
    printf("\n");
}

int is_valid_move(int row, int col) {
    return row >= 0 && row < SIZE &&
           col >= 0 && col < SIZE &&
           board[row][col] == ' ';
}

void get_player_move(char player) {
    int row, col;
    while (1) {
        printf("Player %c, enter move (row column 1-3): ", player);
        if (scanf("%d %d", &row, &col) != 2) {
            while (getchar() != '\n');
            printf("Invalid input. Try again.\n");
            continue;
        }
        row--; col--;
        if (is_valid_move(row, col)) {
            board[row][col] = player;
            break;
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
}

char check_winner(void) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2] &&
            board[i][0] != ' ') return board[i][0];
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i] &&
            board[0][i] != ' ') return board[0][i];
    }
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2] &&
        board[0][0] != ' ') return board[0][0];
    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0] &&
        board[0][2] != ' ') return board[0][2];
    return ' ';
}

int is_draw(void) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ') return 0;
    return 1;
}

void update_scoreboard(const char* winner_name) {
    FILE* fp = fopen("scoreboard.txt", "r");
    char name[MAX_NAME];
    int score;
    int found = 0;
    FILE* temp = fopen("temp.txt", "w");

    if (fp) {
        while (fscanf(fp, "%49s %d", name, &score) == 2) {
            if (strcmp(name, winner_name) == 0) {
                fprintf(temp, "%s %d\n", name, score + 1);
                found = 1;
            } else {
                fprintf(temp, "%s %d\n", name, score);
            }
        }
        fclose(fp);
    }

    if (!found) {
        fprintf(temp, "%s 1\n", winner_name);
    }
    fclose(temp);

    remove("scoreboard.txt");
    rename("temp.txt", "scoreboard.txt");
}

void show_scoreboard(void) {
    FILE* fp = fopen("scoreboard.txt", "r");
    if (!fp) {
        printf("No scores recorded yet.\n");
        return;
    }
    char name[MAX_NAME];
    int score;
    printf("\n----- Scoreboard -----\n");
    while (fscanf(fp, "%49s %d", name, &score) == 2) {
        printf("%-20s %d wins\n", name, score);
    }
    printf("----------------------\n");
    fclose(fp);
}

void play_game(const char* playerX, const char* playerO) {
    init_board();
    char winner = ' ';
    int turn = 0;

    while (1) {
        draw_board();
        char current_player = (turn % 2 == 0) ? 'X' : 'O';
        get_player_move(current_player);
        winner = check_winner();
        if (winner != ' ') {
            draw_board();
            printf("Player %c wins!\n", winner);
            const char* winner_name = (winner == 'X') ? playerX : playerO;
            update_scoreboard(winner_name);
            break;
        }
        if (is_draw()) {
            draw_board();
            printf("It's a draw!\n");
            break;
        }
        turn++;
    }
}

int main(void) {
    char playerX[MAX_NAME] = "Player X";
    char playerO[MAX_NAME] = "Player O";
    int choice;

    printf("=== Multi-Player Tic-Tac-Toe ===\n");
    printf("Enter name for Player X: ");
    scanf("%49s", playerX);
    printf("Enter name for Player O: ");
    scanf("%49s", playerO);

    while (1) {
        printf("\n1. New Game\n");
        printf("2. View Scoreboard\n");
        printf("3. Quit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                play_game(playerX, playerO);
                break;
            case 2:
                show_scoreboard();
                break;
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
