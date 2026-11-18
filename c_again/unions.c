#include <stdio.h>

/* In a struct, each member has its own memory. */
/* In a union, all members share the same memory, which means you can only use
 * one of the values at a time. */

union myUnion {
  int myNum;         // 1 byte
  char myLetter;     // 1 byte
  char myString[30]; // 30 bytes
};

int main() {
  /* The size of a union is usually the same as the size of its largest member:
   */
  union myUnion u1;

  u1.myNum = 1000;

  // Since this is the last value written to the union, myNum no longer holds
  // 1000 - its value is now invalid
  u1.myLetter = 'A';

  printf("myNum: %d\n", u1.myNum);       // This value is no longer reliable
  printf("myLetter: %c\n", u1.myLetter); // Prints 'A'

  printf("Size of union: %zu bytes\n", sizeof(u1)); // 32 bytes

  return 0;
}

/* When to Use Unions */

/* Use unions when: */

/*     You need to store different types in the same location */
/*     You only use one type at a time */
/*     Saving memory is very important */
