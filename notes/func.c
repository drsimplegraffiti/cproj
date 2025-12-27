#include <stdio.h>

void func(int val);
void func_pointer(int *val);

int main() {
  int x = 1;

  // Passing x by value to func()
  func(x);
  printf("%d\n", x); // x is still 1

  int y = 1;
  // Passing address of x
  func_pointer(&y);
  printf("%d", y); // y will be 123
}

// pass by value
// In this method, a copy of the argument is passed to the function. The
// function works on this copy, so any changes made to the parameter inside the
// function do not affect the original argument. It is also known as call by
// value.

// Function that takes parameters by value
void func(int val) {

  // Changing the value
  val = 123;
}

// Pass by Pointers
//
// This method uses a pointer as a parameter to receive the address of the data
// that is passed to the function in the function call as argument. This allows
// the function to access and modify the content at that particular memory
// location, hence, modifications done in the function are reflected in the
// original value. It is also known as call by pointers. Function that takes
// parameters by pointer
void func_pointer(int *val) {

  // Changing the value
  *val = 123;
}
