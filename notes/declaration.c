#include <stdio.h>

int addNumbers(int a, int b); // declaration (prototype)

int main() {
  int x = addNumbers(3, 5);
  printf("%d\n", x);
  return 0;
}

int addNumbers(int a, int b) { // definition later
  return a + b;
}
