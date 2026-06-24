
// Standard Streams in C
// In C, there are three pre-defined file pointers as part of the standard
// library `stdio.h`. They represent standard input (`stdin`), standard output
// (`stdout`), and standard error (`stderr`).
// - `stdin`: This is the standard input stream, which is usually the keyboard.
// Functions such as `scanf()`, `getchar()`, `fgets()`, and others use `stdin`
// to get input data from the keyboard.

// - `stdout`: This represents the standard output stream, which typically
// displays on the computer screen. Functions like `printf()`, `putchar()`,
// `puts()`, and others output data to `stdout`.

// - `stderr`: This is the standard error stream, which is the default output
// for error messages, typically displayed on the computer screen.

#include <stdio.h>

int main() {
  // ----------- Standard Input (stdin) -----------
  int number;
  printf("Enter a number: "); // prompt user
  scanf("%d", &number);       // read from keyboard (stdin)
  printf("You entered: %d\n", number);

  // Using fscanf() with stdin (same as scanf)
  printf("Enter another number: ");
  fscanf(stdin, "%d", &number); // reads from standard input stream
  printf("You entered (via fscanf): %d\n", number);

  // ----------- Standard Output (stdout) -----------
  printf("Printing to stdout using printf\n"); // default output
  fprintf(stdout, "Printing to stdout using fprintf: %d\n",
          number); // explicit stdout

  // ----------- Standard Error (stderr) -----------
  int divisor = 0;
  int dividend = 5;
  if (divisor == 0) {
    fprintf(stderr, "Error: Division by zero!\n"); // prints error to stderr
  } else {
    printf("Result: %d\n", dividend / divisor);
  }

  // ----------- File Streams -----------
  FILE *fp;                    // file pointer (stream)
  fp = fopen("test.txt", "w"); // open file for writing
  if (fp == NULL) {            // check if file opened successfully
    fprintf(stderr, "Error opening file!\n");
    return 1;
  }
  fprintf(fp, "This is some text in the file.\n"); // write to file
  fclose(fp); // always close file to avoid resource leaks

  // Reading from file
  char buffer[100];
  fp = fopen("test.txt", "r"); // open file for reading
  if (fp != NULL) {
    fgets(buffer, sizeof(buffer), fp); // read one line from file
    printf("Read from file: %s", buffer);
    fclose(fp);
  }

  return 0;
}
