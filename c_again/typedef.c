#include <stdio.h>

typedef float Temperature;

// Without typedef:
struct Car {
  char brand[30];
  int year;
};

// With typedef:
typedef struct {
  char brand[30];
  int year;
} Car;

int main() {

  Temperature today = 25.5;
  Temperature tomorrow = 18.6;

  printf("Today: %.1f C\n", today);
  printf("Tomorrow: %.1f C\n", tomorrow);

  struct Car car1 = {"BMW", 1999}; // needs "struct"
  Car car2 = {"Ford", 1969};       // shorter with typedef

  printf("%s %d\n", car1.brand, car1.year);
  printf("%s %d\n", car2.brand, car2.year);

  return 0;
}
