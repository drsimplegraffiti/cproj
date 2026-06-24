// Exceptions are runtime anomalies or abnormal conditions that a program
// encounters during its execution. C doesn’t provide any specialized
// functionality for this purpose like other programming languages such as C++
// or Java. However, In C, goto keyword is often used for the same purpose. The
// goto statement can be used to jump from anywhere to anywhere within a
// function.
//
// Let's take a look at an example:
#include <stdio.h>

int main() {
  FILE *file = NULL;

  // Attempt to open the file
  file = fopen("example.txt", "r");
  if (file == NULL) {
    printf("Error opening file\n");

    // Jump to the error section if the file couldn't be opened
    goto error;
  }
  printf("File opened successfully!\n");
  fclose(file);
  return 0;

error:

  // Error handling section
  printf("Exiting\n");
  return 1;
}

// Examples of goto for Exception Handling
//
// The following examples demonstrate the use of goto for exception handling in
// C: Simulate try-catch Statements
//
// The try catch statements are used for exception handling in C++ and Java.
// #include <stdio.h>
// int main() {
//     FILE *file = NULL;
//     int result = 0;
//
//     file = fopen("example.txt", "r");
//     if (file == NULL) {
//         printf("Error opening file\n");
//
//         // Jump to the error label if file cannot be opened
//         goto error;
//     }
//
//     // Read data (simulating an error)
//     result = fread(NULL, 1, 100, file);
//     if (result == 0) {
//         printf("Error reading file\n");
//
//         // Jump to error if reading fails
//         goto error;
//     }
//
//     // Process data (simulating a successful operation)
//     printf("Successfull\n");
//
//     // Close the file and exit
//     fclose(file);
//     return 0;
//
// error:
//
//     // Error handling section
//     if (file != NULL) {
//         fclose(file);
//     }
//     return 1;
// }
//
//
//
// #include <stdio.h>
// #include <stdlib.h>
//
// int processFile(const char *filename) {
//     FILE *file = NULL;
//     char *buffer = NULL;
//
//     // Open the file
//     file = fopen(filename, "r");
//     if (!file) {
//         fprintf(stderr, "Error: Failed to open file '%s'\n", filename);
//         goto cleanup;
//     }
//
//     // Allocate memory for the buffer
//     buffer = (char *)malloc(1024);
//     if (!buffer) {
//         fprintf(stderr, "Error: Memory allocation failed\n");
//         goto cleanup;
//     }
//
//     // Simulate reading file content
//     if (fread(buffer, 1, 1024, file) == 0) {
//         fprintf(stderr, "Error: Failed to read file\n");
//         goto cleanup;
//     }
//
//     printf("File processed successfully.\n");
//
// cleanup:
//     // Cleanup resources
//     if (buffer) free(buffer);
//     if (file) fclose(file);
//
//     // Return error status
//     return (file && buffer) ? 0 : -1;
// }
//
// int main() {
//     const char *filename = "example.txt";
//
//     if (processFile(filename) != 0) {
//         fprintf(stderr, "An error occurred while"
//                 "processing the file.");
//         return 1;
//     }
//
//     return 0;
// }
