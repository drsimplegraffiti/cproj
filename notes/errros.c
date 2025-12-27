// Using if-else
//
// In C, error handling is done manually since there is no built-in try-catch
// block like in other programming languages. To manage errors, we can use
// if-else statements to check for conditions and handle any potential errors
// that may occur during program execution.
//
// Example:

#include <errno.h>
#include <stdio.h>

int main() {
  FILE *fp;

  // opening a file which does not exist
  fp = fopen("gfg.txt", "r");

  if (fp == NULL) {
    printf("File openning error");
  } else {
    printf("File open successfully");
  }
  return 0;
}
