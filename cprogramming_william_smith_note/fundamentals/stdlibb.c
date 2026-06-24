#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a, const void *b) {
  return (*(int *)a - *(int *)b); // comparison function for qsort/bsearch
}

int main() {
  // ----------- Random Numbers -----------
  srand(time(NULL)); // seed random number generator with current time
  printf("Random number: %d\n", rand()); // generate a pseudo-random number

  // ----------- String to Number Conversion -----------
  char *str = "12345";
  printf("Integer: %d\n", atoi(str)); // string -> int
  printf("Long: %ld\n", atol(str));   // string -> long
  printf("Double: %f\n", atof(str));  // string -> double

  // ----------- Quick Sort -----------
  int arr[] = {4, 2, 5, 1, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  qsort(arr, n, sizeof(int), compare); // sort array in-place
  printf("Sorted array: ");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");

  // ----------- Binary Search -----------
  int key = 3;
  int *found = (int *)bsearch(&key, arr, n, sizeof(int), compare);
  if (found)
    printf("Found item: %d\n", *found);
  else
    printf("Item not found\n");

  // ----------- Dynamic Memory Allocation -----------
  int *p = (int *)malloc(4 * sizeof(int)); // allocate memory for 4 ints
  if (p == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }
  for (int i = 0; i < 4; i++)
    p[i] = i; // initialize memory
  printf("Allocated array: ");
  for (int i = 0; i < 4; i++)
    printf("%d ", p[i]);
  printf("\n");
  free(p); // free allocated memory

  // ----------- Program Termination -----------
  printf("Exiting program...\n");
  exit(0); // terminate program immediately

  return 0; // unreachable because of exit()
}
