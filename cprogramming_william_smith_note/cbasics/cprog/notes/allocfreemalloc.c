// METHOD 1
// #include <stdio.h>
// #include <stdlib.h>
//
// int main() {
//
//   // Initially allocate memory for 5 integers
//   int *ptr = (int *)malloc(5 * sizeof(int));
//
//   // Check if allocation was successful
//   if (ptr == NULL) {
//     printf("Memory Allocation Failed\n");
//     exit(0);
//   }
//
//   // Now, we need to store 8 elements so
//   // Reallocate to store 8 integers
//   ptr = (int *)realloc(ptr, 8 * sizeof(int));
//
//   // Check if reallocation was successful
//   if (ptr == NULL) {
//     printf("Memory Reallocation Failed\n");
//     exit(0);
//   }
//
//   // Assume we only use 5 elements now
//   for (int i = 0; i < 5; i++) {
//     ptr[i] = (i + 1) * 10;
//   }
//
//   // Shrink the array back to 5 elements
//   ptr = (int *)realloc(ptr, 5 * sizeof(int));
//
//   // Check if shrinking was successful
//   if (ptr == NULL) {
//     printf("Memory Reallocation Failed\n");
//     exit(0);
//   }
//
//   for (int i = 0; i < 5; i++)
//     printf("%d ", ptr[i]);
//
//   // Finally, free the memory when done
//   free(ptr);
//
//   return 0;
// }

// METHOD 2
// #include <stdio.h>
// #include <stdlib.h>
//
// int main() {
//
//   // Initially allocate memory for 5 integers
//   int *ptr = (int *)malloc(5 * sizeof(int));
//
//   // Check if allocation was successful
//   if (ptr == NULL) {
//     printf("Memory Allocation Failed\n");
//     exit(0);
//   }
//
//   // Check if shrinking was successful
//   if (ptr == NULL) {
//     printf("Memory Reallocation Failed\n");
//     exit(0);
//   }
//
//   for (int i = 0; i < 5; i++) {
//     ptr[i] = (i + 1) * 10;
//     printf("%d\n", ptr[i]);
//   }
//
//   // Finally, free the memory when done
//   free(ptr);
//
//   return 0;
// }
//
//
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
//
// int main(void) {
//     char *str = malloc(6); // "hello" + '\0'
//
//     if (!str) {
//         perror("malloc");
//         return 1;
//     }
//
//     strcpy(str, "hello");
//     printf("%s\n", str);
//
//     free(str);
//     return 0;
// }
//
//
// UNKNOWN SIZE
// gcc -Wall -Wextra -std=gnu11 readlines.c -o readlinesJ
// ./readlines < file.txt
// or ./readlines <<EOF
// -Wextra is a compiler warning flag in GCC (and Clang).
// -Wall → most common warnings
// - Wextra → even more warnings
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char **lines = NULL;
  size_t count = 0, cap = 0;

  char *line = NULL;
  size_t len = 0;

  while (getline(&line, &len, stdin) != -1) {

    if (count == cap) {
      cap = cap ? cap * 2 : 8;
      char **tmp = realloc(lines, cap * sizeof *lines);
      if (!tmp) {
        perror("realloc");
        return 1;
      }
      lines = tmp;
    }

    lines[count++] = line;
    line = NULL; // IMPORTANT
    len = 0;
  }

  for (size_t i = 0; i < count; i++) {
    printf("%s", lines[i]);
    free(lines[i]);
  }

  free(lines);
  return 0;
}

// allocate array of strings
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
//
// int main(void) {
//     char **lines = NULL;   // array of strings
//     size_t count = 0;      // number of strings stored
//     size_t cap = 0;        // capacity of the array
//
//     char *line = NULL;
//     size_t len = 0;
//
//     printf("Enter lines (Ctrl+D to finish):\n");
//
//     // Read lines from stdin
//     while (getline(&line, &len, stdin) != -1) {
//
//         // Grow the array if needed
//         if (count == cap) {
//             cap = cap ? cap * 2 : 4; // double capacity
//             char **tmp = realloc(lines, cap * sizeof(*lines));
//             if (!tmp) {
//                 perror("realloc");
//                 return 1;
//             }
//             lines = tmp;
//         }
//
//         lines[count++] = line;  // store pointer
//         line = NULL;            // important! getline will allocate new
//         buffer len = 0;
//     }
//
//     printf("\nYou entered %zu lines:\n", count);
//
//     for (size_t i = 0; i < count; i++) {
//         printf("%s", lines[i]); // lines already include '\n'
//         free(lines[i]);         // free each string
//     }
//
//     free(lines);  // free the array of pointers
//     return 0;
// }
//
