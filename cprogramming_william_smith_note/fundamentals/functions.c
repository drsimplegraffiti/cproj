#include <stdio.h>

/*
========================================================
FUNCTIONS IN C (TL;DR)
========================================================
- Functions are self-contained blocks of code that perform specific tasks
- They help make code modular, readable, and reusable
- Components:
    1) Return Type  -> type of value returned (void if none)
    2) Function Name
    3) Parameters   -> inputs passed to function
    4) Function Body -> code that executes the task
========================================================
*/

// 1) Function prototype (forward declaration)
int add(int num1, int num2);
void greet(const char *name);

int main() {

  /*=======================================================
    2) Calling a function with return value
  =======================================================*/
  int result = add(10, 20); // call add function
  printf("Result of add: %d\n", result);

  /*=======================================================
    3) Calling a function with void return type
  =======================================================*/
  greet("Alice");

  /*=======================================================
    NOTES:
    - Function prototypes are declared before main or other functions
    - Helps compiler know return type and parameters
    - Functions can return values or be void
    - Modularizes code and improves readability
  =======================================================*/

  return 0;
}

/*========================================================
  4) Function definitions
========================================================*/
int add(int num1, int num2) {
  int sum = num1 + num2;
  return sum; // return value to caller
}

void greet(const char *name) { printf("Hello, %s!\n", name); }
