#include <stdio.h>

// Structure can be passed to a function in the same way as normal variables.
// Though, it is recommended to pass it as a pointer to avoid copying a large
// amount of data.

// Structure definition
struct A {
  int x;
};

// Function to increment values
void increment(struct A a, struct A *b) {
  a.x++;
  b->x++;
}

int main() {
  struct A a = {10};
  struct A b = {10};

  // Passing a by value and b by pointer
  increment(a, &b);

  printf("a.x: %d \tb.x: %d", a.x, b.x);
  return 0;
}
