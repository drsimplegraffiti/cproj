#include "calculator.h"

#include <ctype.h>
#include <math.h>
#include <stdlib.h>

#define STACK_SIZE 100

double calculate(double a, char op, double b) {
    switch (op) {
        case '+':
            return a + b;

        case '-':
            return a - b;

        case '*':
            return a * b;

        case '/':
            return (b != 0) ? a / b : NAN;

            /* We use fmod() instead of % because your calculator uses double,
             * and C's % operator only works with integers. */
        case '%':
            return (b != 0) ? fmod(a, b) : NAN;

        default:
            return NAN;
    }
}

/* precedence() determines which arithmetic operation should be performed first
 * when evaluating an expression. */
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
        case '%':
            return 2;

        default:
            return 0;
    }
}

double evaluate_expression(const char *expr) {
    if (expr == NULL)
        return NAN;

    double num_stack[STACK_SIZE];
    char op_stack[STACK_SIZE];

    int num_top = -1;
    int op_top = -1;

    const char *p = expr;

    while (1) {
        // Skip whitespace.
        while (isspace((unsigned char)*p))
            p++;

        // Parse a number, including floating-point and signed numbers.
        char *end;
        double num = strtod(p, &end);

        if (end == p || num_top >= STACK_SIZE - 1)
            return NAN;

        num_stack[++num_top] = num;
        p = end;

        // Skip whitespace after the number.
        while (isspace((unsigned char)*p))
            p++;

        // Stop when we reach the end of the expression.
        if (*p == '\0')
            break;

        // Read the next operator.
        char op = *p++;

        if (op != '+' && op != '-' && op != '*' && op != '/' && op != '%')
            return NAN;

        // Evaluate operators with higher or equal precedence.
        while (op_top >= 0 && precedence(op_stack[op_top]) >= precedence(op)) {

            double b = num_stack[num_top--];
            double a = num_stack[num_top--];

            char current_op = op_stack[op_top--];

            if (current_op == '/' && b == 0)
                return NAN;

            num_stack[++num_top] = calculate(a, current_op, b);
        }

        if (op_top >= STACK_SIZE - 1)
            return NAN;

        op_stack[++op_top] = op;
    }

    // Evaluate remaining operators.
    while (op_top >= 0) {
        double b = num_stack[num_top--];
        double a = num_stack[num_top--];

        char op = op_stack[op_top--];

        if (op == '/' && b == 0)
            return NAN;

        num_stack[++num_top] = calculate(a, op, b);
    }

    return num_top == 0 ? num_stack[num_top] : NAN;
}
