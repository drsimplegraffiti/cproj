#include <stdio.h>

int main() {

  // Name of the file to be deleted
  const char *file = "file.txt";

  // Attempt to delete the file
  if (remove(file) == 0) {
    printf("File deleted successfully.\n");
  } else {
    printf("Error: Unable to delete the file.\n");
  }

  return 0;
}
