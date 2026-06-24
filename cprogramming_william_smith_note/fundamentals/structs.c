#include <stdio.h>
#include <string.h> // For strcpy and memcpy

/*
========================================================
STRUCTURES IN C (TL;DR)
========================================================
- Structures allow grouping related variables into a single type
- Useful for complex data types and records
- Can be nested, passed to functions, and used with pointers
========================================================
*/

// Nested struct example
struct Date {
  int day;
  int month;
  int year;
};

// Main struct example with nested struct
struct Student {
  char name[50];
  int age;
  float grade;
  struct Date birthday;
};

typedef struct {
  int id;
  char name[50];
} StudentArrayType;

int main() {

  /*=======================================================
    1) Creating a struct variable and accessing members
  =======================================================*/
  struct Student john;
  strcpy(john.name, "John Doe");
  john.age = 20;
  john.grade = 4.0;
  john.birthday.day = 15;
  john.birthday.month = 6;
  john.birthday.year = 2003;

  printf("Name: %s\n", john.name);
  printf("Age: %d\n", john.age);
  printf("Grade: %.2f\n", john.grade);
  printf("Birthday: %02d/%02d/%04d\n\n", john.birthday.day, john.birthday.month,
         john.birthday.year);

  /*=======================================================
    2) Using pointers to structs
  =======================================================*/
  struct Student *p = &john;   // pointer to struct
  strcpy(p->name, "Jane Doe"); // arrow operator to access members
  p->age = 22;

  printf("Pointer access -> Name: %s\n", p->name);
  printf("Pointer access -> Age: %d\n\n", p->age);

  /*=======================================================
    3) Array of structs
  =======================================================*/
  StudentArrayType students[4] = {
      {1, "John Doe"}, {2, "Jane Doe"}, {3, "Jim Doe"}, {4, "Jill Doe"}};

  printf("Array of structs:\n");
  for (int i = 0; i < 4; i++) {
    printf("ID: %d, Name: %s\n", students[i].id, students[i].name);
  }
  printf("\n");

  /*=======================================================
    4) Using memcpy to read and update structs in array
  =======================================================*/
  StudentArrayType secondStudent;
  memcpy(&secondStudent, &students[1], sizeof(StudentArrayType));
  // Copy secondStudent into the third element
  memcpy(&students[2], &secondStudent, sizeof(StudentArrayType));

  printf("After memcpy update:\n");
  for (int i = 0; i < 4; i++) {
    printf("ID: %d, Name: %s\n", students[i].id, students[i].name);
  }

  /*=======================================================
    NOTES:
    - Access members: structVar.member or pointer->member
    - Nested structs: access with dot operator
    - Arrays of structs allow managing multiple records
    - memcpy can copy structs efficiently
    - typedef allows shorter type names
  =======================================================*/

  return 0;
}
