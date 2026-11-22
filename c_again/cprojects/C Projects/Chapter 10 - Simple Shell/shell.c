/*
 * Chapter 10 - Simple Shell (Mini Command Line Interpreter)
 * shell.c - a basic shell supporting cd, exit, external commands,
 * I/O redirection (> <), and pipes (|).
 *
 * Compile: gcc shell.c -o shell
 * Run:     ./shell
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 100
#define MAX_LINE 4096

/* Handle > and < redirection before execvp */
void apply_redirection(char* args[]) {
    for (int i = 0; args[i]; i++) {
        if (strcmp(args[i], ">") == 0) {
            args[i] = NULL;
            if (!freopen(args[i + 1], "w", stdout)) {
                perror("freopen");
            }
            break;
        }
        if (strcmp(args[i], "<") == 0) {
            args[i] = NULL;
            if (!freopen(args[i + 1], "r", stdin)) {
                perror("freopen");
            }
            break;
        }
    }
}

int execute_command(char* args[]) {
    if (args[0] == NULL) return 1; /* empty command */

    /* Built-in: exit */
    if (strcmp(args[0], "exit") == 0) return 0;

    /* Built-in: cd */
    if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "cd: missing argument\n");
        } else if (chdir(args[1]) != 0) {
            perror("cd");
        }
        return 1;
    }

    /* Detect pipe */
    int has_pipe = 0;
    int pipe_pos = 0;
    for (int i = 0; args[i]; i++) {
        if (strcmp(args[i], "|") == 0) {
            has_pipe = 1;
            pipe_pos = i;
            args[i] = NULL;
            break;
        }
    }

    if (has_pipe) {
        int fd[2];
        if (pipe(fd) < 0) {
            perror("pipe");
            return 1;
        }

        pid_t p1 = fork();
        if (p1 == 0) {
            close(fd[0]);
            dup2(fd[1], STDOUT_FILENO);
            close(fd[1]);
            apply_redirection(args);
            execvp(args[0], args);
            perror("exec 1 failed");
            exit(1);
        }

        pid_t p2 = fork();
        if (p2 == 0) {
            close(fd[1]);
            dup2(fd[0], STDIN_FILENO);
            close(fd[0]);
            execvp(args[pipe_pos + 1], &args[pipe_pos + 1]);
            perror("exec 2 failed");
            exit(1);
        }

        close(fd[0]);
        close(fd[1]);
        wait(NULL);
        wait(NULL);
        return 1;
    }

    pid_t pid = fork();
    if (pid == 0) {
        apply_redirection(args);
        execvp(args[0], args);
        perror("exec failed");
        exit(1);
    } else if (pid < 0) {
        perror("fork");
    } else {
        wait(NULL);
    }

    return 1;
}

int main(void) {
    char line[MAX_LINE];
    char* args[MAX_ARGS];

    printf("=== MyShell ===\n");
    printf("Type commands (exit to quit). Supports |, >, <\n\n");

    while (1) {
        printf("MyShell> ");
        fflush(stdout);

        if (!fgets(line, sizeof(line), stdin)) break;
        /* Remove trailing newline */
        line[strcspn(line, "\n")] = '\0';
        if (strlen(line) == 0) continue;

        /* Tokenize */
        int argc = 0;
        char* token = strtok(line, " ");
        while (token != NULL && argc < MAX_ARGS - 1) {
            args[argc++] = token;
            token = strtok(NULL, " ");
        }
        args[argc] = NULL;

        int cont = execute_command(args);
        if (!cont) break;
    }

    printf("Goodbye!\n");
    return 0;
}
