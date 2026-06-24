/*
Program to learn C
Author: Abayomi Ogunnusi
Built with nvim
*/

#include <ctype.h> // // Header File
#include <float.h>
#include <limits.h>
#include <math.h>
#include <math.h> // for sqrt
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h> // for atoi
#include <string.h>

// a is an identifier here
// identifier is the name of the variable
int a = 10; // Global declarations
// Semi colon ; is the terminator

// KEYWORDS/RESERVED WORDS in C
// auto 	else 	long 	switch
// break 	enum 	register 	typedef
// case 	extern 	return 	union
// char 	float 	short 	unsigned
// const 	for 	signed 	void
// continue 	goto 	sizeof 	volatile
// default 	if 	static 	while
// do 	int 	struct 	_Packed
// double

// A C program consists of various tokens and a token is either a keyword, an
// identifier, a constant, a string literal, or a symbol.
// token example:
// printf("Hello, World! \n");
// The individual tokens are −
// printf
// (
//    "Hello, World! \n"
// );
// The C compiler identifies whether the token is a keyword, identifier,
// comment, a literal, an operator, any of the other recognized special symbols
// or not. This exercise is done by the tokenizer in the first stage of the
// compilation process.

// <string.h> → string operations
// <math.h>   → math functions
// <stdlib.h> → memory, conversions, utilities

// Install GCC
// https://gcc.gnu.org/install/

// System Programming − C language is used to develop system software which are
// close to hardware such as operating systems, firmware, language translators,
// etc. Embedded Systems − C language is used in embedded system programming for
// a wide range of devices such as microcontrollers, industrial controllers,
// etc. Compiler and Interpreters − C language is very common to develop
// language compilers and interpreters. Database Systems − Since C language is
// efficient and fast for low-level memory manipulation. It is used for
// developing DBMS and RDBMS engines. Networking Software − C language is used
// to develop networking software such as protocols, routers, and network
// utilities. Game Development − C language is widely used for developing games,
// gaming applications, and game engines. Scientific and Mathematical
// Applications − C language is efficient in developing applications where
// scientific computing is required. Applications such as simulations, numerical
// analysis, and other scientific computations are usually developed in C
// language. Text Editor and IDEs − C language is used for developing text
// editors and integrated development environments such as Vim and Emacs.

//  From system programming to photo editing software
// C programming language, on the other hand, provides a low-level access to the
// memory. This makes it a mid-level language Low level: Assembly

// Preprocessor directives in C carry out some of the important roles such as
// importing functions from a library, defining and expanding the macros, etc.

// ctype.h − Functions for testing and mapping characters, like isalpha,
// isdigit, etc.

// ANSI C
// In the 1980s, the American National Standards Institute (ANSI) began working
// on a formal standard for the C language.

// #define TYPEOF(x)                                                              \
//   _Generic((x),                                                                \
//       int: "int",                                                              \
//       float: "float",                                                          \
//       double: "double",                                                        \
//       char: "char",                                                            \
//       default: "unknown")

#define TYPEOF(x)                                                              \
  _Generic((x),                                                                \
      int: "int",                                                              \
      float: "float",                                                          \
      double: "double",                                                        \
      char: "char",                                                            \
      char *: "char * (string)",                                               \
      const char *: "const char * (string)",                                   \
      default: "unknown")

/*forward declaration*/
float area_of_square(float);

// Extern says: “These variables exist somewhere else”
// you can declare the extern here
extern int extern_a;
extern int extern_b;

#define LENGTH 10
#define WIDTH 5
#define NEWLINE '\n'

// boolean as a constant
#define FALSE 0
#define TRUE 1

// 10 + 4 + 8 = 22 bytes
struct employee {
  char name[10];  // 10 bytes
  int age;        // 4 bytes
  double percent; // 8 bytes
};

int main(void) {

  struct employee e1 = {"Raghav", 25, 78.90};
  printf("Size of employee variable: %lu\n",
         sizeof(e1)); // But you got: 24 bytes. the extra space is from padding
   printf("size of employee struct: %lu\n", sizeof(struct employee));

  int arrd[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  printf("Size of arr: %lu\n",
         sizeof(arrd)); // i.e 10 elements * 4bytes for each = 40 bytes

  // getting the lenght
  int yl = sizeof(arrd) / sizeof(int);
  printf("No of elements in arr: %d\n", yl);

  // dynamic memorry allocation
  // The sizeof operator is used to compute the memory block to be dynamically
  // allocated with the malloc() and calloc() functions.
  // The malloc() function is used with the following syntax −
  // type *ptr = (type *) malloc(sizeof(type)*number);
  // The following statement allocates a block of 10 integers and stores its
  // address in the pointer −
  int *ptr = (int *)malloc(sizeof(int) * 10);
  printf("pointer is %p\n", ptr);

  // character arithmetic
  char charone = 'A';
  char chartwo = 'B';
  int charthree = charone + chartwo;
  printf("sum of two chars %d and %d is %d\n", charone, chartwo, charthree);

  // The Size of a Pointer in C
  // The sizeof() operator returns the same value irrespective of the type. This
  // includes the pointer of a built−in type, a derived type, or a double
  // pointer.
  printf("Size of int data type: %lu \n", sizeof(int *));
  printf("Size of char data type: %lu \n", sizeof(char *));
  printf("Size of float data type: %lu \n", sizeof(float *));
  printf("Size of double data type: %lu \n", sizeof(double *));
  printf("Size of double pointer type: %lu \n", sizeof(int **));

  // you can also shift character and add them together too
  char c1 = 'A' + 1;
  char c2 = 'C' - 1;
  int diff = 'C' - 'A';

  printf("A + 1 = %c\n", c1);
  printf("C - 1 = %c\n", c2);
  printf("C - A = %d\n", diff);

  // compare characters
  if ('a' < 'z') {
    printf("'a' comes before 'z'\n");
  }

  // INCREMENT AND DECREMENT
  char ch = 'A';
  printf("Original character: %c\n", ch);

  ch++; // Increment
  printf("After increment: %c\n", ch);

  ch--; // Decrement
  printf("After decrement: %c\n", ch);

  // Converting to Uppercase and Lowercase
  //
  // In ASCII, the difference between uppercase and lowercase letters is 32. To
  // convert an uppercase letter to lowercase, we add 32 to it. For example, 'M'
  // + 32 becomes 'm'. Similarly, to convert a lowercase letter to uppercase, we
  // subtract 32 from it. For example, 'm' - 32 becomes 'M'.
  char upper = 'M';
  char lower = upper + 32; // Convert uppercase to lowercase

  char small = 'm';
  char capital = small - 32; // Convert lowercase to uppercase

  printf("Original Uppercase: %c\n", upper);
  printf("Converted to Lowercase: %c\n", lower);
  printf("Original Lowercase: %c\n", small);
  printf("Converted to Uppercase: %c\n", capital);

  printf("size of char %zu\n", sizeof(char));

  printf("False: %d \n True: %d", FALSE, TRUE);

  // octal (base 8)
  int oct = 025;  // 025 (octal) → 21 in decimal
  int hex = 0xa1; // 0xa1 (hex) → 161 in decimal
  printf("Octal to decimal: %d\n", oct);
  // Octal (rare): int x = 010;  // this is 8, NOT 10. Avoid octal
  //
  // Linux file permissions → chmod 755
  // Old/legacy code
  // Escape sequences → '\101'

  // hexadecimal (base 16)
  printf("Hexadecimal to decimal: %d\n",
         hex); // commonly used in memory address : Memory addresses output
               // looks like 0x7ffeefbff5ac
               // Hex is used because:
               // Maps cleanly to binary (1 hex digit = 4 bits)
               // Much shorter than binary

  // Modern C compilers also let you represent an integer as a binary number,
  // for which you need to add a 0b prefix.
  int xxx = 0b00010000;
  printf("binary to decimal: %d\n", xxx);

  // tips:
  // 212      /* valid */
  // 215u     /* valid */
  // 0xFeeL   /* valid */
  // 078      /* invalid: 8 is not an octal digit */
  // 032UU    /* invalid: cannot repeat a suffix */

  // variance of integer literals
  // 85       /* decimal */
  // 0213     /* octal */
  // 0x4b     /* hexadecimal */
  // 30       /* int */
  // 30u      /* unsigned int */
  // 30l      /* long */
  // 30ul     /* unsigned long */

  // character literals
  char BINGO = 'B';
  printf("prints the character %c\n", BINGO);
  printf("prints the ASCII value %d\n", BINGO);
  // though \n is two charactesrs but still fits into character
  printf("\n is a new line \n");

  printf("sizeof float is %zu bytes \n", sizeof(float));
  printf("sizeof double is %zu bytes \n", sizeof(double));
  printf("sizeof long double is %zu bytes \n", sizeof(long double));

  printf("CHAR_BIT    :   %d\n", CHAR_BIT);
  printf("CHAR_MAX    :   %d\n", CHAR_MAX);
  printf("CHAR_MIN    :   %d\n", CHAR_MIN);
  printf("INT_MAX     :   %d\n", INT_MAX);
  printf("INT_MIN     :   %d\n", INT_MIN);
  printf("LONG_MAX    :   %ld\n", (long)LONG_MAX);
  printf("LONG_MIN    :   %ld\n", (long)LONG_MIN);
  printf("SCHAR_MAX   :   %d\n", SCHAR_MAX);
  printf("SCHAR_MIN   :   %d\n", SCHAR_MIN);
  printf("SHRT_MAX    :   %d\n", SHRT_MAX);
  printf("SHRT_MIN    :   %d\n", SHRT_MIN);
  printf("UCHAR_MAX   :   %d\n", UCHAR_MAX);
  printf("UINT_MAX    :   %u\n", (unsigned int)UINT_MAX);
  printf("ULONG_MAX   :   %lu\n", (unsigned long)ULONG_MAX);
  printf("USHRT_MAX   :   %d\n", (unsigned short)USHRT_MAX);

  printf("Storage size for float : %zu \n", sizeof(float));
  printf("FLT_MAX     :   %g\n", (float)FLT_MAX);
  printf("FLT_MIN     :   %g\n", (float)FLT_MIN);
  printf("-FLT_MAX    :   %g\n", (float)-FLT_MAX);
  printf("-FLT_MIN    :   %g\n", (float)-FLT_MIN);
  printf("DBL_MAX     :   %g\n", (double)DBL_MAX);
  printf("DBL_MIN     :   %g\n", (double)DBL_MIN);
  printf("-DBL_MAX     :  %g\n", (double)-DBL_MAX);
  printf("Precision value: %d\n", FLT_DIG);

  /*
  TL;DR: const in different contexts (with distinct names)

  -----------------------------------
  1) POINTER TO CONSTANT
     (value is read-only, pointer can move)
  -----------------------------------
  int a = 10, b = 20;

  const int *pintc = &a;

  printf("%d\n", *pintc); // 10

  // *pintc = 50;  NOT allowed (cannot change value)
  pintc = &b;   //  allowed (pointer can move)

  -----------------------------------
  2) CONSTANT POINTER TO VARIABLE
     (pointer is fixed, value can change)
  -----------------------------------
  int x = 30, y = 40;

  int *const cpint = &x;

  *cpint = 100;  //  allowed (change value → x = 100)

  // cpint = &y;  NOT allowed (pointer cannot move)

  -----------------------------------
  3) CONSTANT POINTER TO CONSTANT
     (nothing can change)
  -----------------------------------
  int m = 50, n = 60;

  const int *const cpcint = &m;

  // *cpcint = 200;  NOT allowed (cannot change value)
  // cpcint = &n;   NOT allowed (cannot move pointer)

  -----------------------------------
  MENTAL MODEL
  -----------------------------------
  const int *pintc     → move pointer, can't change value
  int *const cpint     → can't move pointer, can change value
  const int *const cpcint → can't move or change anything
  */

  int areac;
  areac = LENGTH * WIDTH;
  printf("length: %d width: %d", LENGTH, WIDTH);
  printf("%c", NEWLINE);
  printf("value of area : %d", areac);

  // You can declare a constant in C program with either of the following two
  // ways
  //  Using the const Keyword
  //  Using the #define Directive
  const float PI = 3.14159265359;
  float radius = 5;
  float areab = PI * radius * radius;
  printf("areab: %f", areab);

  // A constant in C can be of any of the data types including primary data
  // types such as int, float, char, and derived data types such as struct.

  // define using #define: #define PI = 3.14159265359
  // Although the constant so defined can also be used in any expression (just
  // as the one with the const keyword), there is a difference between the two.
  //
  // The constants created by the #define directive are not handled by the
  // compiler. Instead, they behave as macros, whose values are substituted at
  // the runtime.
  //
  // The other notable difference is that you need not mention the data type of
  // the value to be assigned to the constant when using the #define directive.

  // and the use it in another file. say math.c
  // you can use these variables in another file
  int extern_a = 5;
  int extern_b = 10;

  printf("extern a %d\n", extern_a);
  printf("extern b %d\n", extern_b);

  // scanf   → reads from standard input (keyboard)
  // fscanf  → reads from a file (FILE *)

  // scanf
  // int x;
  // scanf("%d", &x); Reads input from: stdin (keyboard)

  // FILE *fp = fopen("test.txt", "r");
  // fscanf(fp, "%d", &x);
  // Reads input from: a file (fp)
  // fscanf(fp, "%d, %d, %d", &x, &y, &z);
  // Reads from file fp
  // Expects format like:
  // 10, 20, 30
  // Then:
  // printf("%d, %d, %d", x, y, z);

  // printf("Enter num1 and num2: ");
  // int num1, num2;
  // scanf("%d %d", &num1, &num2);
  // printf("num one and two are: %d %d\n", num1, num2);

  // character input
  // The %c format specifier reads a single character from the keyboard.
  // However, we must give a blank space before %c in the format string. This is
  // because the %c conversion specifier won't automatically skip any leading
  // whitespaces.
  // printf("Enter a character: ");
  // char cu;
  // scanf(" %c", &cu);
  // The space before %c matters.
  //
  // Why?
  // Because %c reads everything including whitespace:
  // spaces
  // newlines (\n)
  // tabs
  //
  // So if you previously pressed Enter, there is a leftover \n in the input
  // buffer. The space in " %c" means:
  //
  //  “skip all whitespace first, then read a character”
  // printf("character %c\n", cu);

  // char ch1, ch2;
  // printf("Enter two characters: ");
  // scanf(" %c %c", &ch1, &ch2);
  //
  // printf("You entered characters: %c and %c", ch1, ch2);

  // Character Input Using gets()
  // char ch;
  //
  // printf("Enter a character: ");
  // ch = getchar();
  //
  // puts("You entered: ");
  // putchar(ch);
  //
  // printf("\nYou entered character: %c", ch);

  char message[] = "Welcome to Tutorialspoint";
  printf("Using %%s specifier: %s\n", message); //%% → prints a single %

  int marks = 90;
  printf("You scored %d%% in the exam.\n",
         marks); // To print the % symbol itself, we use %% inside printf().

  int numm = 2314;
  printf("Without flag: |%5d|\n", numm);
  printf("With left-justify: |%-5d|\n", numm);

  int pos = 1423;
  int neg = -1423;
  printf("Without flag: %d, %d\n", pos, neg);
  printf("With plus flag: %+d, %+d\n", pos, neg);

  // quotes: Using Tab and Quotes
  printf("Item\tPrice\n");
  printf("\"Book\"\t$12\n");
  printf("\"Pen\"\t$2\n");

  // Length Modifiers in printf() Function
  // Printing Long Long and Long Double
  // use ll and L to print long long integers and long doubles.
  long long ll = 123456789012345;
  long double ld = 3.141592653589793238;
  printf("Long long number: %lld\n", ll);
  printf("Long double: %.15Lf\n", ld);

  short s = 32000;
  long l = 1234567890;
  printf("Short number: %hd\n", s);
  printf("Long number: %ld\n", l);

  // Precision with Float and String
  // Width in printf() function sets the minimum space for a value. It adds
  // extra spaces if the value is shorter, and by default, the value is
  // right-aligned. We use %.2f to print a floating-point number with 2 decimal
  // places, and
  // %.5s to print only the first 5 characters of a string.
  float pi = 3.14159;
  char str2[] = "Tutorialspoint";

  printf("Pi with 2 decimals: %.2f\n", pi);
  printf("String with 5 characters: %.5s\n", str2);

  int nume = 2314;
  printf("Octal without #: %o\n", nume);
  printf("Octal with #: %#o\n", nume);
  printf("Hex lowercase without #: %x\n", nume);
  printf("Hex lowercase with #: %#x\n", nume);
  printf("Hex uppercase without #: %X\n", nume);
  printf("Hex uppercase with #: %#X\n", nume);

  int xd, yd, zd;

  FILE *fp = fopen("test.txt", "w");

  xd = 10;
  yd = 20;
  zd = 30;

  fprintf(fp, "%d, %d, %d", xd, yd, zd);

  fclose(fp);

  // HANDLE the white space error in scanf
  // It ensures:
  // reads only up to size - 1
  // prevents buffer overflow
  // includes newline if space allows
  char name[20];

  printf("Enter your name: ");
  fgets(name, sizeof(name), stdin);

  printf("You entered the name: %s", name);

  // READ CHARACTER SEQUENCE
  char cha;
  char word[10];

  int i = 0;
  printf("Enter characters. End by pressing the Enter key: ");

  while (1) {
    cha = getchar();
    word[i] = cha;
    if (cha == '\n')
      break;
    i++;
  }
  printf("\nYou entered the word: %s", word);

  printf("type of: %s\n", TYPEOF(4));
  printf("type of: %s\n", TYPEOF(4.6));

  double x = 16.0;

  sqrt(x);                          // square root → 4
  pow(2, 3);                        // 2^3 → 8
  printf("ceil %f\n", ceil(2.3));   // → 3
  printf("floor %f\n", floor(2.9)); // → 2
                                    // gcc main.c -lm

  char str[] = "123";

  int num = atoi(str);     // stdlib
  double root = sqrt(num); // math

  printf("len: %lu\n", strlen(str)); // string
  printf("sqrt: %.2f\n", root);

  char arr[] = "world";
  printf("%s\n", TYPEOF(arr));

  char c[] = "Hello";
  char d[] = "World";

  strcpy(d, c);                              // copy string
  printf("string lenght: %lu\n", strlen(c)); // length
  printf("compared: %d\n", strcmp(c, d));    // compare
  strcat(c, d);                              // concatenate

  bool tall = true;
  if (!!tall) {
    printf("not tall\n");
  }

  char a = '4';
  if (!isdigit(a)) {
    printf("this is not a digit\n");
  } else {
    printf("this is a digit\n");
  }

  float side = 5.50;
  float area = area_of_square(side);
  printf("Side=%5.2f Area=%5.2f", side, area);

  return 0;
}

/*subroutine*/
// A reusable block of code that performs a specific task and can be called from
// other parts of the program.
float area_of_square(float side) {
  float area = pow(side, 2);
  return area;
}

// main.c
//   ↓ (-E)
// expanded code
//   ↓ (-S)
// assembly (main.s)
//   ↓ (-c)
// object file (main.o)
//   ↓ (link)
// executable (main)

//-E → stops after preprocessing
// gcc -E main.c
//  Stops at:
// After handling:
// #include
// #define
// macros
// removing comments
//  What you get:
// Expanded C code
// Printed to terminal (or redirect to file)
// gcc -E main.c > main.i
// So -E stops BEFORE compilation (no assembly, no object file)

// -S → stops after compilation
// gcc -S main.c
// Stops at:
// After converting code → assembly
//  What you get:
// main.s (assembly file)
//
//  So -S stops BEFORE assembling (no .o, no executable)
// main.c
//   ↓ (-E stops here)
// preprocessed code (.i)
//   ↓ (-S stops here)
// assembly (.s)
//   ↓ (-c stops here)
// object file (.o)
//   ↓
// executable
