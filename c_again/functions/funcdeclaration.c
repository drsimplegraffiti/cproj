#include <math.h>
#include <stdio.h>

/* inline suggests to the compiler that it should replace a function call with
 * the actual function code instead of performing a normal function call. */
/* The compiler may optimize it as if you had written: */
/* int result = 1 + 3; */
/* TL;DR */
/* - inline = suggests avoiding function-call overhead. */
/* - It can improve performance for small, frequently called functions. */
/* - The compiler is not required to inline the function. */
/* - static inline = function has internal linkage (only accessible within that
 * source file). */
/* Inline functions are best for small, simple functions. Avoid using them for:
 */
/* Large functions (they make your program bigger) */
/* Recursive functions */
/* Functions that are rarely called */
static inline int add_num(int a, int b) { return a + b; }

// function declaration
void greetings();
void add(int a, int b);

/* Passing a function pointer to another function: */
void greetMorning() { printf("Good morning!\n"); }
void greetEvening() { printf("Good evening!\n"); }

void greet(void (*func)()) { func(); }

int main() {

  greet(greetMorning);
  greet(greetEvening);

  greetings();
  add(1, 2);

  double res = sqrt(4);
  printf("res is %.2f\n", res);

  printf("ceil from 1.2 to %f\n", ceil(1.2));

  int inline_res = add_num(1, 3);
  printf("inline res %d\n", inline_res);
  return 0;
}

// function definition
void greetings() { printf("have you eaten?\n"); }
void add(int a, int b) { printf("a + b = %d\n", a + b); }
