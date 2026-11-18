#include <stdio.h>
#include <string.h>

struct Person {
  int age;
  char grade;
  char name[199];
};

int main() {

  struct Person p1;
  p1.age = 19; // modifies the value
  p1.grade = 'A';
  strcpy(p1.name, "James the first");
  // Print values
  printf("%d %c %s\n", p1.age, p1.grade, p1.name);

  struct Person p2 = {.name = "jude", .age = 1, .grade = 'A'};
  printf("%d %c %s\n", p2.age, p2.grade, p2.name);

  struct Person p3 = {1, 'A', "james"};
  printf("%d %c %s\n", p3.age, p3.grade, p3.name);

  struct Person p4[3] = {
      {1, 'B', "mimi"}, {19, 'F', "mide"}, {3, 'C', "segun"}};

  printf("person %d, %s\n", p4[0].age, p4[0].name);

  int i;
  for (i = 0; i < 3; i++) {
    printf("%s is %d years old\n", p4[i].name, p4[i].age);
  }

  return 0;
}
