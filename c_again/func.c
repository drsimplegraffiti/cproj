#include <stdio.h>

// pass by value
void greetings(char name[]) {
  printf("your name is %s\n", name);
  printf("\n");
}

int add(int a, int b) { return a + b; }

void my_fun(int nums[3]) {
  for (int i = 0; i < 3; i++) {
    printf("%d\n", nums[i]);
  }
}

int main() {
  greetings("jude");
  greetings("james");

  int res = add(3, 7);
  printf("res is %d\n", res);

  int nums[3] = {1, 4, 5};
  my_fun(nums);
  return 0;
}
