#include <stdio.h>
#include <unistd.h>

int main(void) {

  int a = 10;
  int *ptr_a = &a;
  printf("the address of a is %p\n", (void *)&ptr_a);
  printf("dereferenced pointer is %d\n", *ptr_a);

  const char msg[] = "Hello world\n";
  printf("sizeof of msg is %lu\n", sizeof(msg));
  write(1, msg, sizeof(msg) -1);

  return 0;
}

// gcc main.c -g -Wall -Wextra -Werror  -std=c2x -fsanitize=address -pedantic -o
// main && ./main                             ✘ INT   system
