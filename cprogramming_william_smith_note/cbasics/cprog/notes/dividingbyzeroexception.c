Manually Checking before Division

    The most used method is to check if the
    divisor(number that divides the dividend)
        in the division is zero or not using if else statement.

    Example : C

#include <float.h>
#include <stdio.h>

              int main() {
  float a = 10, b = 0;
  float res;

  // Check division by zero
  if (b == 0) {
    printf("Error: Division by zero");
  } else {
    res = a / b;
    printf("%f", res);
  }
  return 0;
}

Output

Error: Division by zero

Explanation: The program checks for division by zero using if (b == 0) before performing the division. If b is 0, it prints an error message.
Using Signal Handling

Signal handling can be used to catch runtime exceptions like divide-by-zero errors. In case of floating-point errors, SIGFPE (Floating Point Exception) is raised. We can create a signal handler function and assign it to SIGFPE using signal() function. The setjump and longjmp can be used to jump to the previous valid state of the program, allowing you to handle the exception and resume execution. The SIGFPE can be cleared by using the feclearexcept and fetestexcept functions from the fenv.h header

Example:
C

#include <fenv.h>
#include <float.h>
#include <setjmp.h>
#include <signal.h>
#include <stdio.h>

    jmp_buf recovery;

void handle_divide_by_zero(int sig) {

  // Re-assign the signal handler
  signal(SIGFPE, handle_divide_by_zero);
  printf("Error: Division by zero\n");

  // Jump to the recovery point
  longjmp(recovery, 1);
}
int main() {
  double a = 10, b = 0, res;
  int recovery_status;

  // Assign the signal handler
  signal(SIGFPE, handle_divide_by_zero);

  // Set a recovery point
  recovery_status = setjmp(recovery);
  if (recovery_status == 0) {
    res = a / b;
    if (fetestexcept(FE_DIVBYZERO)) {
      feclearexcept(FE_DIVBYZERO);
      raise(SIGFPE);
    } else {
      printf("%f", res);
    }
  }
  return 0;
}

Output

inf

Explanation: Program executes step by step as follow:

    The program sets up a signal handler for SIGFPE to catch floating-point exceptions like division by zero.
    It attempts to divide a by b, where b is 0, which will cause a floating-point exception.
    If the division by zero exception occurs and raise(SIGFPE)
will trigger the signal handler(handle_divide_by_zero())
    .The signal handler prints an error message and then uses longjmp() to
    return to the recovery point,
    avoiding the program crashing.The program can then proceed without further
    errors(or cleanup operations),
    as it has recovered from the division by zero.
