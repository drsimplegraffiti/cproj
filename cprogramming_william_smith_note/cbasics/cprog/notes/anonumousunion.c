// Anonymous Union
//
//     An anonymous union in C is a union that does not have a name.Instead of
//         accessing its members through a named union variable,
//     you can directly access the members of the anonymous union.This is useful
//         when you want to access the union members directly within a specific
//             scope,
//     without needing to declare a union variable.gg

#include <stdio.h>
#include <string.h>

// Define a union with
// different data types
struct Student {
  int rollNo;
  char name[100];

  // Anonymous union
  union {
    int marks;
  } performance;
};

int main() {

  // Declare a structure variable
  struct Student abc;

  abc.rollNo = 21;
  strcpy(abc.name, "james");
  printf("%d\n", abc.rollNo);
  printf("%s\n", abc.name);

  // Assign and print the member of anonymous union
  abc.performance.marks = 91;
  printf("%d", abc.performance.marks);

  return 0;
}
