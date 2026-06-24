

#include <stdio.h>
#include <stdlib.h>

int main() {

  // allocate memory
  int *ptr = (int *)malloc(sizeof(int));

  *ptr = 10;
  printf("%d\n", *ptr);

  // Forgot to free memory free(ptr) is missing
  return 0;
}
// variables and parameters of the function while the heap is used for dynamic
// memory allocation during runtime. A memory leak occurs when a program
// dynamically allocates memory but does not release it after it's no longer
// needed.
//
//     In C, memory is allocated using malloc() / calloc() and released using
//     free(). In C++, memory is allocated using new / new[] and released using
//     delete / delete[].
// Data can be stored in either stack or heap memory. The stack stores local
//
// Common Causes of Memory Leak

//     Memory is allocated (malloc/new) but not released (free/delete).
//     If a pointer to allocated memory is overwritten or goes out of scope
//     without freeing, the memory it pointed to becomes unreachable. In
//     long-running programs, even small leaks add up over time. This gradually
//     eats up system memory, making the program slow or crash.
//
// How to avoid memory leaks?
//
//     Always free/ delete the memory after use.
//     Don't overwrite a pointer before freeing its old memory.
//     In C++, prefer smart pointers (unique_ptr, shared_ptr) to handle memory
//     automatically. Use tools like Valgrind to detect leaks during testing.
