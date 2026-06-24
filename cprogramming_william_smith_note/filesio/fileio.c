#include <stdio.h>

int main() {
  // ----------- File Handling -----------
  FILE *fp = fopen("test.txt", "w"); // open file for writing
  if (fp == NULL) {
    printf("Failed to open file\n");
    return 1;
  }

  fputs("Hello, world!\n", fp); // write a line to file
  fputc('A', fp);               // write a single character to file
  fclose(fp);                   // close file

  // ----------- Reading from File -----------
  fp = fopen("test.txt", "r"); // open file for reading
  if (fp == NULL) {
    printf("Failed to open file\n");
    return 1;
  }

  char buffer[50];
  fgets(buffer, sizeof(buffer), fp); // read a line from file
  printf("Read line: %s", buffer);

  char ch = fgetc(fp); // read a single character
  printf("Next character: %c\n", ch);

  fclose(fp);

  // ----------- Formatted File I/O -----------
  fp = fopen("test.txt", "w");
  fprintf(fp, "Number: %d, Text: %s\n", 123,
          "C"); // write formatted output to file
  fclose(fp);

  fp = fopen("test.txt", "r");
  int num;
  char str[20];
  fscanf(fp, "Number: %d, Text: %s", &num,
         str); // read formatted input from file
  printf("Read from file -> %d, %s\n", num, str);
  fclose(fp);

  // ----------- Console I/O -----------
  printf("Enter a number: ");
  int input;
  scanf("%d", &input); // read formatted input from keyboard
  printf("You entered: %d\n", input);

  printf("Enter your name: ");
  scanf("%s", str); // read a string
  printf("Hello, %s!\n", str);

  return 0;
}

// ✅ Explanation in code comments:
// fopen() / fclose() → open/close file
// fputc() / fputs() → write character/line to file
// fgetc() / fgets() → read character/line from file
// fprintf() / fscanf() → formatted file I/O
// printf() / scanf() → formatted console I/O
