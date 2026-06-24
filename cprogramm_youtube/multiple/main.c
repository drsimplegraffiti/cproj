#include "add.h"
#include <stdio.h>

int main() {

  int n1;
  int n2;
  char op;

  printf("Enter operator, num1, num2: ");

  scanf(" %c %d %d", &op, &n1, &n2);
  int res = add(n1, n2, op);
  printf("%d\n", res);
  return 0;
}

// gcc main.c add.c -o main && ./main
// breakdown:
// gcc main.c will produce main.o
// gcc add.c will produce add.o
// gcc main.c add.c -o main links them together
