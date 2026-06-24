#include <stdio.h>

int main() {
  /*
  =========================================================
  CONSTANT POINTERS
  =========================================================
  A constant pointer is a pointer whose address cannot change
  after initialization. However, the value at that address can
  be modified (if it is not const itself).
  =========================================================
  */

  int x = 10;
  int y = 20;

  // Declare a constant pointer to int
  int *const p = &x;

  printf("Initial value of x: %d\n", x);
  printf("Pointer p points to address: %p\n", (void *)p);
  printf("Value at pointer p: %d\n\n", *p);

  // You can change the value at the address p points to
  *p = 15;
  printf("After changing *p, x = %d\n", x);

  // But you cannot make p point to a different variable
  // p = &y;  // ❌ This will cause a compilation error

  printf("Pointer p still points to address: %p\n", (void *)p);

  /*
  =========================================================
  NOTES:
  =========================================================
  1) Syntax: int * const p = &x;
     - '*' before 'const' means pointer to int
     - 'const' after '*' means the pointer itself is constant

  2) You can change the value of x through p (*p = ...)

  3) You cannot change the pointer p to point somewhere else
     (p = &y) will fail to compile

  4) If you want the VALUE to be constant instead:
     const int *p2 = &x;
     - Here, the value pointed to is const, but pointer can change
  =========================================================
  */

  return 0;
}
