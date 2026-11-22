#ifndef CALCULATOR_H
#define CALCULATOR_H

double calculate(double a, char op, double b);
double evaluate_expression(const char *expr);
int precedence(char op);
#endif
