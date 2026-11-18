#include <stdio.h>

// To use a pointer to a struct, just add the * symbol, like you would with
// other data types.

// To access its members, you must use the -> operator instead of the dot .
// syntax:

struct Car {
  char brand[30];
  int year;
};

/* Passing Struct Pointers to Functions */

// Function that takes a pointer to a Car struct and updates the year
void updateYear(struct Car *c) {
  c->year = 2025; // Change the year
}

int main() {
  struct Car car = {"toyota", 2023};
  // pointer to struct
  struct Car *ptr = &car;

  // access members
  printf("Brand: %s\n", ptr->brand);
  printf("Year: %d\n", ptr->year);
  printf("Brand: %s\n", (*ptr).brand);
  /* ptr->brand is a shorter way to write (*ptr).brand: it goes to the struct
   * that ptr points to, and gets its brand member. */

  struct Car myCar = {"Toyota", 2020};
  updateYear(&myCar); // Pass a pointer so the function can change the year
                      //
  printf("Brand: %s\n", myCar.brand);
  printf("Year: %d\n", myCar.year);

  return 0;
}
