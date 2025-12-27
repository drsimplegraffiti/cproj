#include <stdbool.h>
#include <stdio.h>

void greet(void) { printf("void data type called...\n"); }

int main(void) {

  int age = 30;
  float weight = 90.89f;
  double money = 90.7878;
  char grade = 'A';

  printf("%d\n", age);
  printf("%f\n", weight);
  printf("%lf\n", money);
  printf("%c\n", grade);

  size_t sizeof_weight =
      sizeof(weight); // c needs a size that can represent the maximum possible
                      // size of any object in memory
  printf("size of weight: %zu bytes\n", sizeof_weight);

  greet();

  // Size of data types
  printf("The type of int is : %zu bytes\n", sizeof(int));
  printf("The type of float is : %zu bytes\n", sizeof(float));
  printf("The type of char is : %zu bytes\n", sizeof(char));
  printf("The type of double is : %zu bytes\n", sizeof(double));

  const int like = 5;

  int n = 42;
  float pi = 3.14f;
  char ch = 'C';
  char str[] = "C is fun!";
  bool flag = true;

  printf("%d %f %c %s %d\n", n, pi, ch, str, flag);

  fputs("This is my string", stdout);
  printf("\n");
  fputs("This is my string with a new line\n", stdout);

  int person_age;
  printf("Enter your age: ");
  scanf("%d", &person_age);

  printf("Your age is %d\n", person_age);
  printf("Address: %p\n", (void *)&person_age);

  char charac;
  printf("Enter a grade: ");
  scanf(" %c", &charac);
  printf("You entered: %c\n", charac);

  char name[100] = "abayomi jones";
  printf("%s\n", name);

  char str_character[100];
  printf("Enter a word: ");
  scanf("%99s", str_character);
  printf("%s\n", str_character);

  // Clear newline left by scanf
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;

  char my_name[20];
  printf("Enter your name: ");
  fgets(my_name, sizeof(my_name), stdin);

  printf("Hello, %s", my_name);

  int a = 25, b = 5;

  // using operators and printing results
  printf("a + b = %d\n", a + b);
  printf("a - b = %d\n", a - b);
  printf("a * b = %d\n", a * b);
  printf("a / b = %d\n", a / b);
  printf("a %% b = %d\n", a % b);
  printf("+a = %d\n", +a);
  printf("-a = %d\n", -a);
  printf("a++ = %d\n", a++);
  printf("a-- = %d\n", a--);

  int i;
  float f;
  char d;

  printf("Size of int: %d bytes\n", (int)sizeof(i));
  printf("Size of int: %lu bytes\n", sizeof(i));
  printf("Size of float: %d bytes\n", (int)sizeof(f));
  printf("Size of char: %d bytes\n", (int)sizeof(d));

  printf("Size of char: %lu bytes\n", sizeof(char));
  printf("Size of int: %lu bytes\n", sizeof(int));
  printf("Size of float: %lu bytes\n", sizeof(float));
  printf("Size of double: %lu bytes\n", sizeof(double));
  printf("Size of pointer: %lu bytes\n", sizeof(void *));

  // integer variable
  int num = 10;
  int *add_of_num = &num;

  printf("sizeof(num) = %lu bytes\n", sizeof(num));
  printf("&num = %p\n", &num);
  printf("*add_of_num = %d\n", *add_of_num);
  printf("(10 < 5) ? 10 : 20 = %d\n", (10 < 5) ? 10 : 20);
  printf("(float)num = %f\n", (float)num);

  int bb = 1;

label:
  printf("%d ", bb);
  n++;

  if (bb <= 10)
    goto label;

  return 0;
}
