#include <stdio.h>
#include <string.h>

void printStr(char str[]) { printf("%s", str); }

int main() {

  // A string is an array of characters terminated by a special character '\0'
  // (null character). This null character marks the end of the string and is
  // essential for proper string manipulation.
  // Unlike many modern languages, C does not have a built-in string data type.
  // Instead, strings are implemented as arrays of char.
  // A string in C is an array of characters ending with \0.

  // declaring and initializing a string
  char str[] = "Geeks";

  // printing the string
  printf("The string is: %s\n", str);

  // Internally, this creates an array like: { 'G', 'e', 'e', 'k', 's', '\0'}
  // Access first character
  // of string
  printf("%c \n", str[0]);

  //   Update
  //
  // We can change individual characters of a string using their index: str[0] =
  // 'h'. Strings can also be updated using standard library functions like
  // strcpy() to replace the entire string. Ensure the new string fits within
  // the allocated array size to avoid memory issues.
  str[0] = 'D';
  printf("The string is: %s\n", str);

  printf(" string length is : %lu \n", strlen(str));

  char greet[5];

  printf("Enter a name of len(5): ");
  scanf("%s", greet);
  printf("%s\n", greet);

  //   Passing Strings to Function
  // As strings are character arrays, we can pass strings to functions in the
  // same way we pass an array to a function. Below is a sample program to do
  // this:
  char strf[] = "GeeksforGeeks";

  // Passing string to a
  // function
  printStr(strf);

  // string pointers
  char strp[20] = "Geeks";

  // Pointer variable which stores
  // the starting address of
  // the character array str
  char *ptrp = strp;

  // While loop will run till
  // the character value is not
  // equal to null character
  while (*ptrp != '\0') {
    printf("%c", *ptrp);
    ptrp++;
  }

  // pointer to a string literal
  // A string literal is a sequence of characters enclosed in double quotes,
  // like "Hello" or "1234". Internally, it is stored as a constant character
  // array terminated by a null character '\0'.
  // Points to a string literal in read-only memory.
  // Cannot modify the content: Cannot modify the content:
  // Use when you just need to read the string.
  const char *strliterals = "Hello World";

  printf("%s\n", strliterals);

  //   Creates a mutable array on the stack.
  // You can modify it safely:
  char charArray[] = "Hello World";
  charArray[0] = 'h'; // ✅ works

  return 0;
}
