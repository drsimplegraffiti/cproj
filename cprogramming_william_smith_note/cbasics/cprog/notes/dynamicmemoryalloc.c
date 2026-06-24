#include <stdio.h>
#include <stdlib.h>

int main() {

  // Create an integer pointer
  // Heap Segment
  int *ptr = (int *)malloc(sizeof(int) * 10);
  printf("%p\n", ptr);
  return 0;
}
