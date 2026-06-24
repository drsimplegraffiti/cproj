#include <math.h>
#include <stdio.h>

/*
========================================================
MATH LIBRARY FUNCTIONS TL;DR
========================================================
- sin(), cos(), tan() : Trigonometric functions (angle in radians)
- exp()               : Exponential e^x
- log(), log10()      : Natural log (base e), common log (base 10)
- sqrt()              : Square root
- ceil(), floor()     : Round up/down
- pow()               : Power function (base^exponent)
========================================================
*/

int main() {
  // Trigonometric functions
  double angle = M_PI / 4; // 45 degrees in radians
  printf("sin(45°) = %f\n", sin(angle));
  printf("cos(45°) = %f\n", cos(angle));
  printf("tan(45°) = %f\n", tan(angle));

  // Exponential function
  double num1 = 2.0;
  printf("exp(2) = %f\n", exp(num1));

  // Logarithmic functions
  double num2 = 10.0;
  printf("log(10) = %f\n", log(num2));
  printf("log10(10) = %f\n", log10(num2));

  // Square root function
  double num3 = 16.0;
  printf("sqrt(16) = %f\n", sqrt(num3));

  // Rounding functions
  double num4 = 10.7;
  printf("ceil(10.7) = %f\n", ceil(num4));
  printf("floor(10.7) = %f\n", floor(num4));

  // Power function
  double base = 2.0, exponent = 3.0;
  printf("pow(2,3) = %f\n", pow(base, exponent));

  return 0;
}
