#include <stdio.h>

int main() {

  // pointer to pointer
  int m = 90;        // normal variable
  int *ptr = &m;     // pointer to int
  int **pptr = &ptr; //  pointer to pointer

  printf("%d\n", m);
  printf("*ptr: %d\n", *ptr);
  printf("**ptr %d\n", **pptr);
  return 0;
}
