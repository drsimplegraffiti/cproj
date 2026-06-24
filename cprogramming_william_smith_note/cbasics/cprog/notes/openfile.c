// File handling in C is the process in which we create, open, read, write, and
// close operations on a file. C language provides different functions such as
// fopen(), fwrite(), fread(), fseek(), fprintf(), etc. to perform input,
// output, and many different C file operations in our program.

#include <stdio.h>
#include <stdlib.h>

int main() {

  // File pointer to store the
  // value returned by fopen
  FILE *fptr;

  // Opening the file in read mode
  fptr = fopen("filename.txt", "r");

  // checking if the file is
  // opened successfully
  if (fptr == NULL) {
    printf("The file is not opened.");
  }
  return 0;
}
