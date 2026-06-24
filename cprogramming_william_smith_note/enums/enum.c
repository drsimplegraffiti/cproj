#include <stdio.h>

/*
========================================================
ENUMERATIONS IN C (enum)
========================================================
- `enum` allows defining a type that can take one of a few specific integral
values
- Enumerators are constants (by default starting at 0)
- You can explicitly assign values to enumerators
========================================================
*/

int main() {

  /*=======================================================
    1) Basic enum example
  =======================================================*/
  enum Day { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

  enum Day today = Wednesday; // Assign an enum value
  printf("Today is day number: %d\n",
         today); // Defaults: Sunday=0, Monday=1, etc.

  /*=======================================================
    2) Enum with custom values
  =======================================================*/
  enum Month {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
  };

  enum Month birthMonth = March; // March = 3
  printf("Birth month number: %d\n", birthMonth);

  /*=======================================================
    3) Notes:
      - By default, first enumerator = 0, next increments by 1
      - You can assign custom values (e.g., January=1)
      - Enums are stored as integers internally
      - Useful for readable code instead of using raw numbers
  =======================================================*/

  return 0;
}
