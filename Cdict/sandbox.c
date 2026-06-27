#include <stdio.h>

void greet(const char *name, int age, char *buffer) {

  sprintf(buffer, "my name is %s and i am %d years old", name, age);

}

int main() {
  char output[100];

  greet("james", 4, output);

  printf("%s\n", output);

  return 0;
}
