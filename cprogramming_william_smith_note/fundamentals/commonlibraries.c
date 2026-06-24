#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
========================================================
COMMON C LIBRARIES TL;DR
========================================================
1) Math library (math.h)
   - sin(), cos(), tan()     : Trigonometric functions
   - exp()                   : Exponent
   - log(), log10()          : Logarithms
   - sqrt()                  : Square root
   - ceil(), floor()         : Round up/down
   - pow()                   : Power function

2) Time library (time.h)
   - time()                  : Current calendar time
   - clock()                 : Processor time
   - difftime()              : Difference between two times
   - asctime()               : Convert time struct to string

3) String library (string.h)
   - strchr(), strrchr()     : Find first/last occurrence of char
   - strstr()                : Find substring
   - strtok()                : Split string into tokens
   - strdup()                : Duplicate string
   - strlen()                : Length of string
   - strcpy(), strncpy()     : Copy strings
   - strcat(), strncat()     : Concatenate strings
   - strcmp(), strncmp()     : Compare strings

4) Standard I/O library (stdio.h)
   - fopen(), fclose()       : Open/close files
   - fread(), fwrite()       : Read/write files
   - fgetc(), fputc()        : Read/write chars
   - fgets(), fputs()        : Read/write strings
   - fprintf(), fscanf()     : Formatted file I/O
   - printf(), scanf()       : Console I/O
   - gets(), puts()          : Read/write lines

5) Standard library (stdlib.h)
   - rand(), srand()         : Pseudo-random numbers
   - atoi(), atol(), atof()  : Convert string to int/long/double
   - qsort()                 : Sort array
   - bsearch()               : Binary search
   - malloc(), calloc()      : Dynamic memory allocation
   - free()                  : Free allocated memory
   - exit()                  : Terminate program
   - abs()                   : Absolute value

6) Character type library (ctype.h)
   - isdigit(), isalpha(), isalnum() : Character checks
   - isupper(), islower()            : Case checks
   - toupper(), tolower()            : Convert case
========================================================
*/

int main() {
  // Math library example
  double val = 16.0;
  printf("sqrt(16) = %.2f\n", sqrt(val));
  printf("2^3 = %.2f\n", pow(2, 3));

  // Time library example
  time_t t = time(NULL);
  printf("Current time: %s", asctime(localtime(&t)));

  // String library example
  char str1[20] = "Hello";
  char str2[] = "World";
  strcat(str1, str2); // concatenate strings
  printf("Concatenated string: %s\n", str1);

  // Stdlib example
  char numStr[] = "123";
  int num = atoi(numStr);
  printf("Converted number: %d\n", num);

  // Ctype example
  char ch = 'a';
  if (isalpha(ch)) {
    printf("%c is alphabetic, uppercase: %c\n", ch, toupper(ch));
  }

  // String to Number Conversion: `atoi()`, `atol()`, `atof()`
  // These functions convert strings to numbers. `atoi()` converts to an
  // integer, `atol()` converts to a long integer, and `atof()` converts to a
  // double floating- point number.

  char *str = "12345";
  printf("Integer: %d\n", atoi(str));
  printf("Long: %ld\n", atol(str));
  printf("Double: %f\n", atof(str));

  return 0;
}
