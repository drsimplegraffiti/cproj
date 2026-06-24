#include <stdio.h>

int main() {
  // ---------------- Safe file reading ----------------
  FILE *fp;
  char buffer[100]; // buffer of fixed size

  // Open a file for reading
  fp = fopen("test.txt", "r");
  if (fp == NULL) {
    printf("Error opening file!\n");
    return 1;
  }

  // Use fgets() to safely read lines from the file
  // fgets() ensures no more than sizeof(buffer)-1 characters are read
  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    printf("%s", buffer); // print each line
  }

  fclose(fp); // always close the file

  // ---------------- Unsafe input example ----------------
  char unsafeBuffer[5];
  printf("\nUnsafe example (do NOT use gets()): ");
  // gets() does not limit input; user entering >4 chars can overflow buffer
  // gets(unsafeBuffer);  // <-- unsafe, commented out to prevent crash

  // ---------------- Safe input example ----------------
  char safeBuffer[5];
  printf("\nSafe example using fgets(): ");
  // fgets() reads at most sizeof(safeBuffer)-1 characters from stdin
  fgets(safeBuffer, sizeof(safeBuffer), stdin);
  printf("You entered: %s\n", safeBuffer);

  return 0;
}

// ✅ Key Points in Code:
// Buffer Management
// Always define fixed-size buffers (char buffer[100]).
// Never exceed the buffer size when reading input.
// Safe Functions
// fgets(buffer, sizeof(buffer), fp) – safe for reading from files.
// fgets(buffer, sizeof(buffer), stdin) – safe for reading user input.
// Unsafe Functions
// gets(buffer) – dangerous because it does not limit input size. Can cause
// buffer overflow. Stream Redirection You can safely read from files (fp) or
// standard input (stdin) using fgets(). Always close file streams with fclose()
// to prevent resource leaks.
