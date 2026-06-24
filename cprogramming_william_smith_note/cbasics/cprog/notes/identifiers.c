#include <stdio.h>

// function must not be hoisted i.e must be declared up before being called
int addNumbers(int a, int b) { return a + b; }

int main() {
  int result;
  int var_one = 89;
  int var_two = 90;

  result = var_one + var_two;
  printf("%d\n", result); // %d is the format specifier
                          //
  int func_result = addNumbers(3, 5);

  return 0;
}
