/*
 * Chapter 3 - Command-Line Calculator
 * operations.c - core arithmetic and a tiny operator-precedence parser
 * (shunting-yard style with two stacks).
 */

#include "calculator.h"
#include <ctype.h>

/* Apply operator op to operands a and b */
double calculate(double a, char op, double b) {
    switch (op) {
        case '+':
            return a + b; /* addition */
        case '-':
            return a - b; /* subtraction */
        case '*':
            return a * b; /* multiplication */
        case '/':
            return (b != 0) ? a / b : 0; /* guard divide-by-zero */
        case '%':
            return (b != 0) ? (int)a % (int)b : 0; /* guard divide-by-zero */
        default:
            return 0; /* unknown operator */
    }
}

/* Return operator priority (higher binds tighter) */
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1; /* low precedence */
    if (op == '*' || op == '/')
        return 2; /* high precedence */
    return 0;     /* anything else (note: '%' falls here) */
}

/* Evaluate an infix expression string and return the result */
double evaluate_expression(const char *expr) {
    double num_stack[100];         /* operand stack */
    char op_stack[100];            /* operator stack */
    int num_top = -1, op_top = -1; /* stack top indices (-1 = empty) */
    int i = 0;                     /* current position in expr */

    while (expr[i]) { /* scan until end of string */
        if (isspace((unsigned char)expr[i])) {
            i++; /* skip whitespace */
            continue;
        }
        if (isdigit((unsigned char)expr[i]) || expr[i] == '.') {
            double num = 0;         /* integer part */
            double frac = 0;        /* fractional digits as an integer */
            int decimal_places = 0; /* count of digits after the dot */
            int has_dot = 0;        /* seen a decimal point yet? */

            while (isdigit((unsigned char)expr[i]) || expr[i] == '.') {
                if (expr[i] == '.') {
                    has_dot = 1; /* switch to fractional digits */
                    i++;
                    continue;
                }
                if (!has_dot) {
                    num = num * 10 + (expr[i] - '0'); /* build integer part */
                } else {
                    decimal_places++; /* count fraction digit */
                    frac =
                        frac * 10 + (expr[i] - '0'); /* build fraction part */
                }
                i++;
            }

            if (has_dot) {
                double divisor = 1;
                for (int d = 0; d < decimal_places; d++)
                    divisor *= 10;     /* compute 10^decimal_places */
                num += frac / divisor; /* assemble fractional part */
            }

            num_stack[++num_top] = num; /* push number */
        } else {
            char op = expr[i++]; /* read operator and advance */
            /* Reduce higher-or-equal precedence operators already on the stack
             */
            while (op_top >= 0 &&
                   precedence(op_stack[op_top]) >= precedence(op)) {
                double b = num_stack[num_top--];   /* right operand */
                double a = num_stack[num_top--];   /* left operand */
                char operator= op_stack[op_top--]; /* pop operator */
                num_stack[++num_top] =
                    calculate(a, operator, b); /* push result */
            }
            op_stack[++op_top] = op; /* push current operator */
        }
    }

    /* Flush remaining operators */
    while (op_top >= 0) {
        double b = num_stack[num_top--];                  /* right operand */
        double a = num_stack[num_top--];                  /* left operand */
        char operator= op_stack[op_top--];                /* pop operator */
        num_stack[++num_top] = calculate(a, operator, b); /* push result */
    }

    return num_stack[num_top]; /* final result is the last value left */
}
