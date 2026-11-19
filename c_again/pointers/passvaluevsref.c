#include <stdio.h>

void addTenRef(int *x) { *x = *x + 10; }
void addTeValn(int x) { x = x + 10; }

int main() {

  int num = 90;
  addTenRef(&num);
  printf("my num is %d\n", num);

  int num2 = 90;
  addTeValn(num);
  printf("my num2 is %d\n", num2);

  // arrays decays to pointers
  int numbers[] = {19, 3, 45};
  int *ptr = numbers;
  /* numbers is an array. */
  /* ptr is a pointer to an integer. */
  /* numbers decays to &numbers[0]. */
  /* numbers == &numbers[0] // true */
  printf("ptr %p\n", ptr);
  printf("ptr value: %d\n", *ptr);

  return 0;
}
