#include <ctype.h>
#include <stdio.h>

int main() {
  char ch = 'A';

  // ----------- Check character types -----------
  if (isdigit(ch)) { // checks if ch is a digit (0-9)
    printf("%c is a digit\n", ch);
  }

  if (isalpha(ch)) { // checks if ch is an alphabet letter (a-z or A-Z)
    printf("%c is an alphabet letter\n", ch);
  }

  if (isalnum(ch)) { // checks if ch is alphanumeric (letter or digit)
    printf("%c is an alphanumeric character\n", ch);
  }

  // ----------- Change case of characters -----------
  char lower = 'a';
  char upper = 'A';

  printf("'%c' to uppercase: %c\n", lower,
         toupper(lower)); // converts to uppercase
  printf("'%c' to lowercase: %c\n", upper,
         tolower(upper)); // converts to lowercase

  return 0;
}

// ✅ Summary of ctype functions in code comments:
// isdigit() → is it a digit?
// isalpha() → is it a letter?
// isalnum() → is it a letter or digit?
// toupper() → convert to uppercase
// tolower() → convert to lowercase
// This gives a quick and practical example to check character types and change
// case in C.
