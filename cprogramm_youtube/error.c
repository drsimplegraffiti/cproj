// Error mean when something goes wrong

// Types of Errors:
// 1. Compile time error: Happens before the programs run
//     - compilers GCC/CC/Clang catches them
// e.g
// ```c
// int x = "hello"; Diagnostics:
// 1. Incompatible pointer to integer conversion initializing 'int' with an
// expression of type 'char[12]' [-Wint-conversion]
// 1a. printf("") missing semi colon
// ```

// 2. Runtime errors:
// Happens when the program is running:
// Programs runs fine, but crashed on the way
// int a = 10 / 0;
// Diagnostics: 1. Division by zero is undefined [-Wdivision-by-zero]
// 2b:   int *p = NULL;
// *p = 10;
// printf("%p\n", p); // [1]    324733 segmentation fault (core dumped)  ./main
// p points to nothing, so writing *p = 5 crashes (segmentation fault).
// fix A:
// int x;
// int *p = &x;
//
// *p = 5;
// printf("%d\n", x);

// Fix option B: allocate memory
// int *p = malloc(sizeof(int));
//
// if (p != NULL) {
//     *p = 5;
//     printf("%d\n", *p);
//     free(p);
// } else {
//     printf("Memory allocation failed\n");
// }
// NULL → “points to nothing” → don’t dereference it
// Division → never allow denominator = 0

// 3. Logical error
//     if(x = 8){ use == instead of =
//         printf("good");// error.c:30:7: note: each undeclared identifier is
//         reported only once for each function it appears in
//     }

// ERROR HANDLING IN C is manual compared to other languages like Java, C#
// 1. Return codes: (0, 1, EXIT_FAILURE, EXIT_SUCCESS)
// non-zero == error
// #include <stdio.h>
// #include <stdlib.h>
// int main() {
//   int denominator = 0;
//   if (denominator == 0) {
//     printf("Error: division by zero\n");
//     return EXIT_FAILURE;
//   }
//
//   printf("All good\n");
//   return EXIT_SUCCESS;
//
//  EXIT_SUCCESS and EXIT_FAILURE come from <stdlib.h>
//  Using them is more portable than hardcoding 0 and 1
//   return 0;
// }

// 2. perror() (system-level errors)
// Use perror() when a system/library call fails and sets errno.

// #include <stdio.h>
// #include <stdlib.h>
// int main() {
//
//   FILE *file = fopen("data.txt", "r");
//   if (file == NULL) {
//     perror("Failed to open file"); // perror() automatically prints a message
//     based on errno return 1;
//   }
//
//   fclose(file);
//   return 0;
//
//   return 0;
// }

// 3. error + strerror: More control than perror():

// #include <errno.h>
// #include <stdio.h>
// #include <string.h>
//
// int main() {
//
//   FILE *file = fopen("data.txt", "r");
//
//   if (file == NULL) {
//     printf("Error: %s\n", strerror(errno)); // man strerror
//     return 1;
//   }
//
//   fclose(file);
//   return 0;
// }


// 4: custom errors messages
// For logic errors (not system errors), just print your own:
// if (denominator == 0) {
//     fprintf(stderr, "Invalid input: denominator is zero\n");
// }
// Use stderr for errors (important in real apps)


// 5. Returning errors from functions
//
// Instead of crashing, return error codes:
// int divide(int a, int b, int *result) {
//     if (b == 0) return -1;
//
//     *result = a / b;
//     return 0;
// }
//
// int main() {
//     int result;
//
//     if (divide(10, 0, &result) != 0) {
//         printf("Division failed\n");
//     }
// }

//6. exit() for immediate termination
// #include <stdlib.h>
//
// if (something_wrong) {
//     fprintf(stderr, "Fatal error\n");
//     exit(EXIT_FAILURE);
// }

// Use when you cannot recover
// Best Practice Summary
// Use fprintf(stderr, ...) → for errors
// Use perror() → for system errors
// Use errno → when you need details
// Use return codes → for flow control
// Use EXIT_SUCCESS / EXIT_FAILURE → in main()
// Avoid crashing (like *NULL) → validate first
