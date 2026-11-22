/*
 * Chapter 3 - Command-Line Calculator
 * calculator.c - interactive CLI entry point.
 *
 * Usage: run, type expressions like "3 + 5 * 2 - 8 / 4", type "exit" to quit.
 */

#include <stdio.h>
#include <string.h>
#include "calculator.h"

#define MAX_INPUT 100

int main(void) {
    char input[MAX_INPUT];

    printf("Command-Line Calculator\n");
    printf("Type an expression (e.g., 3 + 5 * 2 - 8 / 4) or 'exit' to quit.\n");

    while (1) {
        printf("> ");
        if (!fgets(input, MAX_INPUT, stdin)) {
            break;
        }

        /* Strip trailing newline so string comparison works cleanly */
        input[strcspn(input, "\n")] = 0;

        if (strncmp(input, "exit", 4) == 0) {
            printf("Goodbye!\n");
            break;
        }

        if (strlen(input) == 0) {
            continue;
        }

        double result = evaluate_expression(input);
        printf("Result: %.2f\n", result);
    }

    return 0;
}
