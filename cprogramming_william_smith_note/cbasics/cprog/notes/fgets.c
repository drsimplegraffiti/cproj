// Using fgets()
//
// If someone wants to read a complete string, including spaces, they should use
// the fgets() function. Unlike scanf(), fgets() reads the entire line,
// including spaces, until it encounters a newline.

#include <stdio.h>

int main() {
  char str[20];

  // Reading the string
  // (with spaces) using fgets
  fgets(str, 20, stdin);

  // Displaying the string using puts
  printf("%s", str);
  return 0;
}
