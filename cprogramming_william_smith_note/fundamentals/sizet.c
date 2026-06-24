#include <stdio.h>
#include <string.h> // For memcpy

/*
========================================================
THE sizeof OPERATOR IN C
========================================================
- `sizeof` is a compile-time unary operator
- Returns the size of a type or variable in BYTES
- Can be used with:
  - Primitive types (int, float, char, double)
  - Arrays
  - Structs
  - Expressions
- Useful for memory management and low-level programming
========================================================
*/

struct MyStruct {
  int a;
  double b;
  char c;
};

int main() {

  /*=======================================================
    1) sizeof with primitive data types
  =======================================================*/
  printf("Size of int: %zu bytes\n", sizeof(int));
  printf("Size of float: %zu bytes\n", sizeof(float));
  printf("Size of char: %zu bytes\n", sizeof(char));
  printf("Size of double: %zu bytes\n", sizeof(double));

  /*=======================================================
    2) sizeof with variables
  =======================================================*/
  int x = 100;
  double y = 3.14;
  char z = 'A';
  printf("Size of variable x: %zu bytes\n", sizeof x); // parentheses optional
  printf("Size of variable y: %zu bytes\n", sizeof(y));
  printf("Size of variable z: %zu bytes\n", sizeof(z));

  /*=======================================================
    3) sizeof with arrays
  =======================================================*/
  int arr[10];
  printf("Size of array arr: %zu bytes\n", sizeof(arr));
  printf("Number of elements in arr: %zu\n", sizeof(arr) / sizeof(arr[0]));

  /*=======================================================
    4) sizeof with structs
  =======================================================*/
  struct MyStruct s = {10, 20.5, 'x'};
  printf("Size of struct MyStruct: %zu bytes\n", sizeof(s));

  /*=======================================================
    5) sizeof with byte arrays storing a struct
  =======================================================*/
  unsigned char byteArray[sizeof(s)]; // allocate array same size as struct
  memcpy(byteArray, &s, sizeof(s));   // copy struct into byte array
  printf("Size of byteArray: %zu bytes\n", sizeof(byteArray));

  /*=======================================================
    6) Notes:
    - sizeof(type) requires parentheses for types
    - sizeof(variable) parentheses optional
    - sizeof gives size in bytes, platform dependent
    - Useful for dynamic memory, arrays, structs, and low-level code
  =======================================================*/

  return 0;
}
