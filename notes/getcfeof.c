#include <stdio.h>

int main() {
  FILE *fptr = fopen("file.txt", "w"); // Open file in write mode
  char ch;

  // --- getc() ---
  // Reads a single character from the file pointed by fptr.
  // Returns the character on success, or EOF on error or end-of-file.
  ch = getc(fptr);

  if (ch == EOF) {
    // --- feof() ---
    // Checks if the file pointer has reached the End Of File.
    // Returns non-zero (true) if EOF is reached, 0 otherwise.
    if (feof(fptr))
      printf("End of File\n"); // Reached actual EOF
    else
      printf("Unable to Read\n"); // Read error occurred
  } else {
    printf("Read Character: %c\n", ch); // Successfully read a character
  }

  fclose(fptr); // Close the file
  return 0;
}
