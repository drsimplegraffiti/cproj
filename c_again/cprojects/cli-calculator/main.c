#include "calculator.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

#define MAX_INPUT 100

int main() {

    /* double num1, num2, result; */
    /* char operator; */
    /* char choice; */

    /* do { */
    /*     printf("Enter expression: (e.g 3.5 * 2): "); */
    /*     if (scanf("%lf %c %lf", &num1, &operator, & num2) != 3) { */
    /*         printf("invalid input\n"); */
    /*         while (getchar() != '\n') */
    /*             ; // Clear input buffer */
    /*         /1* return 1; *1/ */
    /*         continue; */
    /*     } */

    /*     result = calculate(num1, operator, num2); */
    /*     printf("Result is %.2f\n", result); */

    /*     printf("Do you want to calculate another expression? (y/n) "); */
    /*     scanf(" %c", &choice); */

    /* } while (choice == 'y' || choice == 'Y'); */

    char input[MAX_INPUT];

    while (1) {
        printf("Enter expression or type 'exit' to quit: ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        // Remove the trailing newline.
        input[strcspn(input, "\n")] = '\0';

        // Check whether the user wants to exit.
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Evaluate the expression.
        double result = evaluate_expression(input);

        // Check for invalid results.
        if (isnan(result)) {
            printf("Error: Invalid expression or division by zero.\n");
            continue;
        }

        printf("Result: %.2f\n", result);
    }

    printf("Calculator closed.\n");

    return 0;
}

/* gcc -Wall -Wextra -Werror -std=c99 \ */
/*     -Iinclude main.c calculator.c \ */
/*     -lm -o main */
