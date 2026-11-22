/*
 * Chapter 20 - Final Project: Modular Operating System Shell
 * main.c - entry point for the modular shell.
 *
 * Modules:
 *   - command processing  (commands.c / commands.h)
 *   - memory management   (memory.c / memory.h)
 *
 * Compile: gcc main.c commands.c memory.c -o shell
 * Run:     ./shell
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "commands.h"
#include "memory.h"

#define INPUT_SIZE 256

int main(void) {
    char input[INPUT_SIZE];

    printf("=== Modular OS Shell ===\n");
    printf("Type 'help' for available commands, 'exit' to quit.\n\n");

    while (1) {
        printf("shell> ");
        fflush(stdout);

        if (!fgets(input, sizeof(input), stdin)) break;
        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0) continue;

        if (strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        }

        if (strcmp(input, "help") == 0) {
            printf("Available commands:\n");
            printf("  help       - show this help\n");
            printf("  hello      - greeting\n");
            printf("  ls         - list current directory\n");
            printf("  alloc <n>  - allocate n bytes (demo)\n");
            printf("  exit       - quit shell\n");
            continue;
        }

        process_command(input);
    }

    return 0;
}
