#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
========================================================
STRING LIBRARY FUNCTIONS TL;DR
========================================================
- strchr()/strrchr() : Find first/last occurrence of a char
- strtok()           : Split string into tokens
- strdup()           : Duplicate a string (malloc'ed)
- strlen()           : Get string length
- strcpy()/strncpy() : Copy string (full/partial)
- strcat()/strncat() : Concatenate strings (full/partial)
- memcpy()/memmove()/memset() : Memory manipulation
========================================================
*/

int main() {
  // 1) strchr() and strrchr()
  char str[] = "Hello, World!";
  char *p = strchr(str, 'o');
  if (p)
    printf("First 'o' at position %ld\n", p - str + 1);
  p = strrchr(str, 'o');
  if (p)
    printf("Last 'o' at position %ld\n", p - str + 1);

  // 2) strtok()
  char s[] = "Hello, World! C Programming";
  char *token = strtok(s, " ,!");
  while (token) {
    printf("Token: %s\n", token);
    token = strtok(NULL, " ,!");
  }

  // 3) strdup()
  char *copy = strdup(str);
  if (copy) {
    printf("Copied string: %s\n", copy);
    free(copy);
  }

  // 4) strlen()
  size_t len = strlen(str);
  printf("Length of string: %zu\n", len);

  // 5) strcpy() and strncpy()
  char dest[50];
  strcpy(dest, "Hello");
  printf("Copied string: %s\n", dest);
  strncpy(dest, "World", 5);
  dest[5] = '\0';
  printf("Copied string with strncpy: %s\n", dest);

  // 6) strcat() and strncat()
  char dest2[50] = "Hello";
  char src2[] = ", World!";
  strcat(dest2, src2);
  printf("Concatenated string: %s\n", dest2);
  strcpy(dest2, "Hello");
  strncat(dest2, src2, 6);
  printf("Concatenated string with strncat: %s\n", dest2);

  // 7) memcpy(), memmove(), memset()
  char src3[] = "Hello, World!";
  char dest3[20], dest4[20], dest5[20];
  memcpy(dest3, src3, strlen(src3) + 1);
  memmove(dest4, src3, strlen(src3) + 1);
  memset(dest5, '$', 5);
  dest5[5] = '\0';
  printf("After memcpy: %s\n", dest3);
  printf("After memmove: %s\n", dest4);
  printf("After memset: %s\n", dest5);

  return 0;
}
