#include <errno.h> // For errno
#include <stdio.h>
#include <stdlib.h> // For exit()
#include <string.h> // For strerror()

/*
========================================================
ERROR HANDLING IN C (TL;DR)
========================================================
- C does NOT have exceptions.
- Errors must be handled manually.
- Common techniques:
    1) Check return values
    2) Use errno and strerror
    3) Write custom error handling functions
========================================================
*/

// Custom error handling function
void handleError(const char *message, int errorCode) {
  // Print the error message
  printf("Error: %s\n", message);
  // Exit the program with the provided error code
  exit(errorCode);
}

int main() {

  /*=======================================================
    1) Checking return value of a function (e.g., fopen)
  =======================================================*/
  FILE *file1 = fopen("file_does_not_exist.txt", "r");
  if (file1 == NULL) {
    printf("Return value check: Unable to open file\n");
    // Exit with error code 1
    return 1;
  }
  fclose(file1);

  /*=======================================================
    2) Using errno and strerror for human-readable error
  =======================================================*/
  FILE *file2 = fopen("another_missing_file.txt", "r");
  if (file2 == NULL) {
    printf("Errno check: %s\n",
           strerror(errno)); // strerror converts errno to message
    return 1;
  }
  fclose(file2);

  /*=======================================================
    3) Using a custom error handling function
  =======================================================*/
  FILE *file3 = fopen("yet_another_file.txt", "r");
  if (file3 == NULL) {
    handleError("Custom handler: Cannot open file", 1);
  }
  fclose(file3);

  /*=======================================================
    NOTES:
    - Always check return values of functions that can fail
    - errno is set by system/library functions on error
    - strerror(errno) provides a human-readable error message
    - Custom error functions reduce repetitive code
  =======================================================*/

  printf("Program completed without errors.\n");

  return 0;
}
