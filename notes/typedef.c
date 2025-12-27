// typedef for Structures
//
//     The typedef keyword is used to define an alias for the already existing
//     datatype. In structures, we have to use the struct keyword along with the
//     structure name to define the variables. Sometimes, this increases the
//     length and complexity of the code. We can use the typedef to define some
//     new shorter name for the structure.
//
//
//

#include <stdio.h>

// Defining structure
typedef struct {
  int a;
} str1;

// Another way of using typedef with structures
typedef struct {
  int x;
} str2;

int main() {

  // Creating structure variables using new names
  str1 var1 = {20};
  str2 var2 = {314};

  printf("var1.a = %d\n", var1.a);
  printf("var2.x = %d\n", var2.x);
  return 0;
}
