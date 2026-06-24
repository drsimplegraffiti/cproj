#include <stdio.h>

int main() {

  //   Using scanf() with a Scanset
  // We can also use scanf() to read strings with spaces by utilizing a scanset.
  // A scanset in scanf() allows specifying the characters to include or exclude
  // from the input.

  char strscan[20];

  // Using scanset in scanf
  // to read until newline
  scanf("%[^\n]s", strscan);

  // Printing the read strscaning
  printf("%s", strscan);

  return 0;
}
