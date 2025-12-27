// A lot of C function calls return -1 or NULL or set an in case of an error
// code as the global variable errno, so quick tests on these values are easily
// done with an instance of ‘if statement’.

// What is errno?
//
// errno is a global variable defined in the <errno.h> header file that
// indicates the error that occurred during a function call in C. When a
// function fails, the errno variable is automatically set to a specific error
// code, which helps identify the type of error encountered. Different values of
// errno correspond to different types of errors, providing useful information
// for error handling in C programs.
#include <errno.h>
#include <stdio.h>

int main() {

  // If a file is opened which does not exist,
  // then it will be an error and corresponding
  // errno value will be set
  FILE *fp;

  // opening a file which does not exist
  fp = fopen("gfg.txt", "r");

  printf("Value of errno: %d\n", errno);

  return 0;
}
