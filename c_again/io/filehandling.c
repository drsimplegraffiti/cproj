#include <stdio.h>

int main() {
  FILE *fptr;

  char reader[255];

  // Create a File
  /* fptr = fopen("file.txt", "w"); writes */
  fptr = fopen("file.txt", "a+"); // a for appends, a+ for read and appending

  if (fptr == NULL) {
    perror("File error");
    return 1;
  }

  // Write some text to the file
  fprintf(fptr, "Some text\n");

  /* The first parameter specifies where to store the file content, which will
   * be in the myString array we just created. */
  /* The second parameter specifies the maximum size of data to read, which
   * should match the size of myString (100). */
  /* The third parameter requires a file pointer that is used to read the file
   * (fptr in our example). */

  // fgets only reads the first line
  /* fgets(reader, 100, fptr); */

  // Move file pointer to the beginning
  rewind(fptr);

  // Read the content and print it
  while (fgets(reader, 100, fptr)) {
    printf("%s", reader);
  }

  // Print the file content
  printf("%s", reader);

  // Close the file
  fclose(fptr);
  return 0;
}
