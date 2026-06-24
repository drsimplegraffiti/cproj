// implemention

#include "calculate.h"

int calculate(int numberOne, int numberTwo, char opt) {

  if (opt == '+') {
    return numberOne + numberTwo;
  } else if (opt == '-') {
    return numberOne - numberTwo;
  } else if (opt == '*') {
    return numberOne * numberTwo;
  } else {
    return 0;
  }
}
