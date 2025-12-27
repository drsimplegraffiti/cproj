// free()

// The memory allocated using functions malloc() and calloc() is not
// de-allocated on their own. The free() function is used to release dynamically
// allocated memory back to the operating system. It is essential to free memory
// that is no longer needed to avoid memory leaks.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
  int *ptr = (int *)calloc(5, sizeof(int));

  // Do some operations.....
  for (int i = 0; i < 5; i++)
    printf("%d ", ptr[i]);

  // Free the memory after completing
  // operations
  free(ptr);

  return 0;
}
