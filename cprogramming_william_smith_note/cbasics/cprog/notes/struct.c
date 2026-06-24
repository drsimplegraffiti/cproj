#include <stdio.h>

// In C, a structure is a user-defined data type that can be used to group items
// of possibly different types into a single type.

struct A {
  int x; // x is a member of the struct
};

struct Student {
  char name[50];
  int age;
  float grade;
};

int main() {

  struct A a;
  a.x = 11;

  printf("%d\n", a.x);

  // Declaring and initializing a structure variable
  struct Student s1 = {"James", 1, 10.9};

  // Designated Initializing another structure
  struct Student s2 = {.age = 18, .name = "Vikas", .grade = 22};

  // Accessing structure members
  printf("%s\t%d\t%.2f\n", s1.name, s1.age, s1.grade);
  printf("%s\t%d\t%.2f\n", s2.name, s2.age, s2.grade);

  // Create a copy of student s1
  //     Copying structure is simple as copying any other variables. For
  //     example, s1 is copied into s2 using assignment operator.
  //         But this method only creates a shallow copy of s1 i.e. if the
  //         structure s1 have some dynamic resources allocated by malloc, and
  //         it contains pointer to that resource, then only the pointer will be
  //         copied to s2. If the dynamic resource is also needed, then it has
  //         to be copied manually (deep copy).
  struct Student s1c = s1;

  printf("Student 1 ID: %s\n", s1c.name);
  printf("Student 1 Grade: %f", s1c.grade);
  return 0;
}
