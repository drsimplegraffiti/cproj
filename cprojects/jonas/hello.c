#include <stdio.h>
#include <stdlib.h>

int main() {

  int *ptr = (int *)malloc(5 * sizeof(int));
  if (ptr == NULL) {
    printf("memory allocation failed \n");
    exit(1);
  }

  ptr = (int *)realloc(ptr, 8 * sizeof(int));
  if (ptr == NULL) {
    printf("memory allocation failed \n");
    exit(1);
  }

  return 0;
}
