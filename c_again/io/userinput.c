#include <stdio.h>
#include <string.h>

/* Discard everything left on the current input line. */
static void flush_line(void) {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

int main(void) {
  int my_num;
  char firstName[30];

  /* Note: When you use scanf() with a string, the array must be big enough for
   * the text (we used 30, which is enough for most first names). */
  /* You also do not use the reference operator (&) with strings, because the
   * name of an array already gives its memory address. */

  printf("Type a number: ");

  if (scanf("%d", &my_num) != 1) { // & is called the reference operator
    printf("please enter a real number\n");
    return 1;
  }
  flush_line(); /* remove the leftover newline after the number */

  printf("Enter your first name: ");
  // Get and save the text
  if (scanf("%29s", firstName) != 1) { // cannot read space like james brown
    printf("invalid name\n");
    return 1;
  }
  flush_line(); /* remove the leftover newline (and any extra words) */

  // cannot read space like james brown
  /* That's why, when working with strings, we often use the fgets() function to
   * read a line of text. Note that you must include the following arguments:
   * the name of the string variable, sizeof(string_name), and stdin (standard
   * input, which is usually the keyboard): */

  char full_name[90];
  printf("please enter full name: ");

  if (!fgets(full_name, sizeof(full_name), stdin)) {
    return 1;
  }
  full_name[strcspn(full_name, "\n")] = '\0'; /* strip trailing newline */

  printf("your full name is %s\n", full_name);
  printf("Age is  %d and name is %s\n", my_num, firstName);

  return 0;
}
