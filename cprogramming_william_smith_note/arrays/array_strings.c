#include <stdio.h>
#include <string.h> // For string functions

/*
========================================================
ARRAYS AND STRINGS IN C (TL;DR)
========================================================
- Arrays: collection of elements of the same type in contiguous memory
- Strings: arrays of characters ending with null character '\0'
========================================================
*/

int main() {

  /*=======================================================
    1) Arrays
  =======================================================*/
  int numbers[5];  // Declaration of array
  numbers[0] = 10; // Assign value to first element
  numbers[1] = 20;
  numbers[2] = 30;
  numbers[3] = 40;
  numbers[4] = 50;

  // Or initialize at declaration
  int nums[5] = {1, 2, 3, 4, 5};

  printf("Array elements:\n");
  for (int i = 0; i < 5; i++) {
    printf("nums[%d] = %d\n", i, nums[i]);
  }
  printf("\n");

  /*=======================================================
    2) Accessing an element
  =======================================================*/
  int firstNumber = nums[0]; // 1
  printf("First element: %d\n\n", firstNumber);

  /*=======================================================
    3) Strings
  =======================================================*/
  char name[] = "John"; // String declaration & initialization
  printf("String: %s\n", name);

  // Access individual characters
  char firstLetter = name[0]; // 'J'
  printf("First letter: %c\n", firstLetter);

  // Modifying a string character
  name[0] = 'M';
  printf("Modified string: %s\n", name);

  /*=======================================================
    NOTES:
    - Array indices start at 0
    - Strings are null-terminated arrays of chars
    - Can use string functions from <string.h> like strcpy, strlen, strcat
    - Arrays and strings are fundamental for handling data in C
  =======================================================*/

  return 0;
}
