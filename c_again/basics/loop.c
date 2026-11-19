#include <stdio.h>

int main() {

  int nums[4] = {1, 2, 9, 6, 7};
  int len = sizeof(nums) / sizeof(nums[0]);

  for (int i = 0; i < len; i++) {
    printf("i is %d, ", nums[i]);
    printf("mem_address is %p\n", &nums[i]);
  }

  // Get the memory address of the myNumbers array
  printf("%p\n", nums);

  // Get the memory address of the first array element
  printf("%p\n", &nums[0]);

  // Get the value of the first element in nums
  printf("The first element is: %d\n", *nums);

  for (int i = 0; i < len; i++) {
    printf("i am array: %d\n", *(nums + i));
  }

  /* int myNumbers[4] = {25, 50, 75, 100}; */
  /* int *ptr = myNumbers; */
  /* int i; */

  /* for (i = 0; i < 4; i++) { */
  /*   printf("%d\n", *(ptr + i)); */
  /* } */

  // pointer arithmetic
  int myNumbers[4] = {25, 50, 75, 100};
  int *p = myNumbers; // points to myNumbers[0]

  printf("%d\n", *p);       // 25
  printf("%d\n", *(p + 1)); // 50
  printf("%d\n", *(p + 2)); // 75
  printf("%d\n", *(p + 3)); // 100

  printf("%d\n", *p); // 10
  p++;                // move to myNumbers[1]
  printf("%d\n", *p); // 20
  p--;                // back to myNumbers[0]
  printf("%d\n", *p); // 10

  p += 2;             // jump to myNumbers[2]
  printf("%d\n", *p); // 30
                      //
                      //
  int lld[5] = {10, 20, 30, 40, 50};
  int *start = &lld[1]; // points to 20
  int *end = &lld[4];   // points to 50

  int distance = end - start;
  printf("%d\n", distance); // 3 elements apart
  //
  //
  int myNumbers1[2] = {1, 2};
  char letters[] = "Hi"; // 'H', 'i', '\0'

  int *pi = myNumbers1; // int pointer
  char *pc = letters;   // char pointer

  printf("%p\n", pi);
  printf("%p\n", pi + 1); // moves by sizeof(int) (4 bytes)
  printf("%p\n", pi + 2); // moves by sizeof(int) (4 bytes)

  printf("%p\n", pc);
  printf("%p\n", pc + 1); // moves by 1 byte

  return 0;
}
