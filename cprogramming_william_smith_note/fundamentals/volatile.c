#include <stdio.h>

/*
========================================================
VOLATILE IN C
========================================================
- `volatile` tells the compiler:
    "Do NOT optimize this variable; its value may change at any time"
- Commonly used for:
    - Hardware registers
    - Multithreaded programs
    - Signals / interrupts
- Prevents compiler from caching the variable in a register
========================================================
*/

int main() {

  /*=======================================================
    1) Volatile variable
  =======================================================*/
  volatile int v = 10; // compiler must always read from memory
  printf("Volatile int v: %d\n", v);

  v = 20; // value can still be changed
  printf("Volatile int v after change: %d\n", v);

  /*=======================================================
    2) Volatile pointer to variable (pointer is normal)
    int * volatile ptr -> pointer itself is volatile (rare)
  =======================================================*/
  int x = 100;
  int *volatile ptr_to_x = &x; // pointer may change unexpectedly
  printf("Value via volatile pointer: %d\n", *ptr_to_x);

  *ptr_to_x = 200; // can modify value
  printf("Value via volatile pointer after change: %d\n", *ptr_to_x);

  // ptr_to_x = &v; // ❌ Some compilers may warn: pointer is volatile, cannot
  // be reassigned in strict rules

  /*=======================================================
    3) Pointer to volatile variable (common)
    volatile int * p -> value pointed to is volatile
  =======================================================*/
  volatile int y = 50;
  volatile int *p_to_vol = &y;
  printf("Volatile value via pointer: %d\n", *p_to_vol);

  *p_to_vol = 60; // can change value
  printf("Volatile value via pointer after change: %d\n", *p_to_vol);

  /*=======================================================
    4) Volatile pointer to volatile variable
    volatile int * volatile pp -> both pointer and value are volatile
  =======================================================*/
  volatile int z = 5;
  volatile int *volatile pp = &z;
  printf("Volatile pointer to volatile value: %d\n", *pp);

  *pp = 10; // value can change
  printf("After modification: %d\n", *pp);

  // pp = &y; // ❌ pointer itself is volatile, cannot reassign in some strict
  // scenarios

  /*=======================================================
    5) Notes:
      - volatile prevents compiler optimization
      - pointer variations:
          volatile int * p          : points to volatile value
          int * volatile p          : volatile pointer (address cannot be
  assumed constant) volatile int * volatile p : pointer AND value are volatile
  =======================================================*/

  return 0;
}
