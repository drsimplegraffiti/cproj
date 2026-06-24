#include <stdbool.h>
#include <stdio.h>

int main() {
  bool x = true;

  // Automatic type conversion from bool to int
  int y = x;

  // Manual type conversion from bool to int
  // explicit
  bool z = (bool)y;

  printf("x: %d\n", x);
  printf("y: %d\n", y);
  printf("z: %d", z);
  return 0;
}
