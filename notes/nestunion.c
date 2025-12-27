#include <stdio.h>

// Define a union with
// different data types
union Student {
  int rollNo;
  union Academic {
    int marks;
  } performance;
};

int main() {

  // Declare a union variable
  union Student abc;

  // Assign and print the
  // roll number
  abc.rollNo = 21;
  printf("%d\n", abc.rollNo);

  // Assign and print the
  // member of inner union
  abc.performance.marks = 91;
  printf("%d", abc.performance.marks);
  return 0;
}

// Nested Union
//
// In C, we can define a union inside another union like structure. This is
// called nested union and is commonly used when you want to efficiently
// organize and access related data while sharing memory among its members.
