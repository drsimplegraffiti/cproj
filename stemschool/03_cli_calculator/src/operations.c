#include "calculator.h"
#include <ctype.h>

double calculator(double a, char op, double b) {
  switch (op) {
  case '+':
    return a + b;

  case '-':
    return a - b;

  case '*':
    return a * b;

  case '/':
    return (b != 0) ? a / b : 0;

  default:
    return 0;
  }
}

int precedence(char op) {
  if (op == '+' || op == '-')
    return 1;
  if (op == '*' || op == '/')
    return 2;
  return 0;
}

double evaluate_expression(const char *expr) {
  double num_stack[100];
  char op_stack[100];
  int num_top = -1, op_top = -1;
  int i = 0;
  while (expr[i]) {
    if (isspace(expr[i])) {
      i++;
      continue;
    }
    if (isdigit(expr[i])) {
      double num = 0;
      while (isdigit(expr[i]) || expr[i] == '.') {
        if (expr[i] == '.') {
          i++; // handle floating point later
          continue;
        }
        num = num * 10 + (expr[i++] - '0');
      }
      num_stack[++num_top] = num;
    } else {
      char op = expr[i++];
      while (op_top >= 0 && precedence(op_stack[op_top]) >= precedence(op)) {
        double b = num_stack[num_top--];
        double a = num_stack[num_top--];
        char operator= op_stack[op_top--];
        num_stack[++num_top] = calculator(a, operator, b);
      }
      op_stack[++op_top] = op;
    }
  }
  while (op_top >= 0) {
    double b = num_stack[num_top--];
    double a = num_stack[num_top--];
    char operator= op_stack[op_top--];
    num_stack[++num_top] = calculator(a, operator, b);
  }
  return num_stack[num_top];
}

