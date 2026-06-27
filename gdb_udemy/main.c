#include <stdio.h>
#include <stdlib.h>

int main() {
  const int *ptr =
      (int *)malloc(sizeof(int) * 10); // int is 4 byte * 10 = 40 bytes
  printf("%d\n", *ptr);
  return 0;
}
