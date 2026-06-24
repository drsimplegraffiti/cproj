// A union is a user-defined data type that can hold different data types,
// similar to a structure.
//
//     Unlike structures, all members of a union are stored in the same memory
//     location. Since all members share the same memory, changing the value of
//     one member overwrites the value of the others. Union members can be
//     accessed using the dot (.) operator. Example: u.member. Unions are useful
//     when you want to save memory by storing different types of data in the
//     same memory space.
// Size of Union

// The size of the union will always be equal to the size of the largest member
// of the union. All the less-sized elements can store the data in the same
// space without any overflow.
//
#include <stdio.h>

// Define a union with
// different data types
union Student {
  int rollNo;
  float height;
  char firstLetter;
};

union A {
  int x;
  char y;
};

union B {
  int arr[10];
  char y;
};

int main() {

  // Declare a union variable
  union Student data;

  // Assign and print the roll number
  data.rollNo = 21;
  printf("%d\n", data.rollNo);
  data.height = 5.2;
  printf("%.2f\n", data.height);
  data.firstLetter = 'N';
  printf("%c", data.firstLetter);

  // Finding size using sizeof() operator
  printf("Sizeof A: %ld\n", sizeof(union A));
  printf("Sizeof B: %ld\n", sizeof(union B));

  return 0;
}
