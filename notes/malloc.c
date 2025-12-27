
// malloc()
//
// The malloc() (stands for memory allocation) function is used to allocate a
// single block of contiguous memory on the heap at runtime. The memory
// allocated by malloc() is uninitialized, meaning it contains garbage values.
//
// Assume that we want to create an array to store 5 integers. Since the size of
// int is 4 bytes, we need 5 * 4 bytes = 20 bytes of memory. This can be done as
// shown:
#include <stdio.h>
#include <stdlib.h>

int main() {
  int *ptr = (int *)malloc(20);

  // Checking if failed or pass
  // Moreover, if there is no memory available, the malloc will fail and return
  // NULL. So, it is recommended to check for failure by comparing the ptr to
  // NULL.
  if (ptr == NULL) {
    printf("Allocation Failed");
    exit(0);
  }

  // Populate the array
  for (int i = 0; i < 5; i++)
    ptr[i] = i + 1;

  // Print the array
  for (int i = 0; i < 5; i++)
    printf("%d ", ptr[i]);
  return 0;
}
