/*
 * Chapter 3 - Command-Line Calculator
 * Header: declares the arithmetic and expression-evaluation functions.
 */

#ifndef CALCULATOR_H
#define CALCULATOR_H

double calculate(double a, char op, double b);   /* apply one operator to two operands */
double evaluate_expression(const char* expr);    /* parse & evaluate a full expression string */

#endif
