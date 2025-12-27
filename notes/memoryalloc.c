#include <stdio.h>
#include <stdlib.h>

int main() {

  int *arr;

  // Allocate memory for 10 integers
  arr = (int *)malloc(10 * sizeof(int));

  if (arr == NULL) {
    printf("Memory allocation failed!\n");
    return 1;
  }

  // Initialize and print the array
  for (int i = 0; i < 10; i++) {
    arr[i] = i + 1;
    printf("%d ", arr[i]);
  }

  // Free the allocated memory
  free(arr);
}
