#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
  char name[255];
  int age;
  float dof;
  char *name2;
};

int main() {

  struct Person p1;
  p1.age = 10;
  p1.dof = 10.4f;
  strcpy(p1.name, "james");
  p1.name2 = "jude";
  return 0;
}
