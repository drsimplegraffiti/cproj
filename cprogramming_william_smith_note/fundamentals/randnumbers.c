#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// - Input: For `srand()`, an unsigned integer seed.
// - Output: For `rand()`, a pseudo-random integer.

int main(void) {

  srand(time(NULL)); // seed the random number generator with the current time
  printf("Random number %d\n", rand()); //297399417 % 10

  // printf("Random number 1-10 %d\n", rand() % 10);
  printf("Random number 1-10 %d\n", rand() % 10 + 1);
  printf("Random number %d\n", rand() % 100 + 1);
  return 0;
}
