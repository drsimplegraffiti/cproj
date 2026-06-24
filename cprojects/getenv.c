#include <stdio.h>
#include <stdlib.h>

int main() {

  char *shell = getenv("SHELL");
  printf("The current shell is: %s\n", shell);
}
