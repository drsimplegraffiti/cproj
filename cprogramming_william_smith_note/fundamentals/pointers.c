#include <stdio.h>

/*
========================================================
POINTERS IN C (TL;DR)
========================================================
- Pointers store memory addresses of other variables
- Allows direct memory manipulation
- Syntax: type *pointerName;
========================================================
*/

int main() {

  /*=======================================================
    1) Declaring and assigning pointers
  =======================================================*/
  int x = 10;
  int *p = &x;                                    // p points to x
  printf("Value of x through pointer: %d\n", *p); // dereference to get value

  /*=======================================================
    2) Modifying value via pointer
  =======================================================*/
  *p = 20; // change x through pointer
  printf("Modified x: %d\n", x);

  /*=======================================================
    3) Pointers and arrays
  =======================================================*/
  int numbers[5] = {1, 2, 3, 4, 5};
  int *pa = numbers; // array name = pointer to first element
  printf("First element via pointer: %d\n", *pa);

  pa++; // move to next element
  printf("Second element via pointer arithmetic: %d\n", *pa);

  /*=======================================================
    4) Pointer difference
  =======================================================*/
  int *p1 = &numbers[0];
  int *p2 = &numbers[4];
  int diff = p2 - p1; // number of elements between pointers
  printf("Difference between p2 and p1: %d\n", diff);

  /*=======================================================
    5) Pointer comparison
  =======================================================*/
  int *p3 = &numbers[0];
  if (p1 == p3) {
    printf("p1 and p3 point to the same element.\n");
  }

  /*=======================================================
    6) Pointer assignment
  =======================================================*/
  int *p4;
  p4 = p1; // p4 points to the same element as p1
  printf("p4 points to value: %d\n", *p4);

  /*=======================================================
    NOTES:
    - Pointer arithmetic: p++ moves to next element
    - Subtract pointers to get distance
    - Always ensure pointers point to valid memory
    - Useful with arrays, dynamic memory, and structs
  =======================================================*/

  return 0;
}
