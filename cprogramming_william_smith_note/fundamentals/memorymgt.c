#include <stdio.h>
#include <stdlib.h>

/*
========================================================
MEMORY MANAGEMENT IN C (TL;DR)
========================================================
- C does NOT have automatic garbage collection
- Programmer must allocate/deallocate memory manually
- Key functions: malloc, calloc, realloc, free
========================================================
*/

int main() {

  /*=======================================================
    1) malloc: allocate memory without initializing
  =======================================================*/
  int *arr1 = malloc(4 * sizeof(int)); // memory for 4 integers
  if (arr1 == NULL) {                  // always check for NULL
    printf("Memory allocation failed\n");
    return 1;
  }
  for (int i = 0; i < 4; i++)
    arr1[i] = i + 1; // assign values
  printf("arr1: ");
  for (int i = 0; i < 4; i++)
    printf("%d ", arr1[i]);
  printf("\n");

  /*=======================================================
    2) calloc: allocate and initialize memory to zero
  =======================================================*/
  int *arr2 = calloc(4, sizeof(int)); // 4 integers, initialized to 0
  if (arr2 == NULL) {
    printf("Memory allocation failed\n");
    free(arr1);
    return 1;
  }
  printf("arr2 (initialized to 0): ");
  for (int i = 0; i < 4; i++)
    printf("%d ", arr2[i]);
  printf("\n");

  /*=======================================================
    3) realloc: resize previously allocated memory
  =======================================================*/
  arr1 = realloc(arr1, 8 * sizeof(int)); // resize arr1 to hold 8 integers
  if (arr1 == NULL) {
    printf("Memory reallocation failed\n");
    free(arr2);
    return 1;
  }
  for (int i = 4; i < 8; i++)
    arr1[i] = i + 1; // assign new values
  printf("arr1 after realloc: ");
  for (int i = 0; i < 8; i++)
    printf("%d ", arr1[i]);
  printf("\n");

  /*=======================================================
    4) free: deallocate memory to avoid memory leaks
  =======================================================*/
  free(arr1); // free memory allocated by malloc/realloc
  free(arr2); // free memory allocated by calloc

  /*=======================================================
    NOTES:
    - Always check if malloc/calloc/realloc returns NULL
    - Free memory when done to prevent leaks
    - Pointers are required to access dynamically allocated memory
  =======================================================*/

  return 0;
}
