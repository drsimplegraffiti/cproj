// An enum variable can be initialized either with a name defined in the enum
// definition or directly with its integer value.

#include <stdio.h>

// Defining enum
enum direction { EAST, NORTH, WEST, SOUTH };

// Defining enum
enum enm { a = 3, b = 2, c };

int main() {

  // Creating enum variable
  enum direction dir = NORTH;
  printf("%d\n", dir);

  // This is valid too
  dir = 3;
  printf("%d", dir);

  // Creating enum variable
  enum enm v1 = a;
  enum enm v2 = b;
  enum enm v3 = c;
  printf("%d %d %d", v1, v2, v3);
  return 0;
}
