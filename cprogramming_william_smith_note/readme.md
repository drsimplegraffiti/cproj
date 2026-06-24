### c programming  (Created in 1972)
- **C** is portable, runs on different types of hardwares or operating systems (OS) that was not possible with Assembly language.
- Understanind programming computing and **memory** management
- High level(between low level programming and low level hardware operations), general purpose used for systems programming, compilers, interpreters, device drivers, embedded programming and application software. Unix OS is primary written in C.
- Close to computer hardware, because of low level access to memory. 
- Provides low level direct access to memory through the use of pointers and pointers arithmetic.
- Has rich standard library for i/o operations such **printf**, **scanf** and malloc, free
- Efficient use of CPU memory

source file == c file ending with .c 

```c
// directive #include instructs the preprocessor to include the standard library.
// the standard library is useful for performing input and output operations e.g printf and scanf
#include <stdio.h>  //the line #include <stdio.h> is called a preprocessor directive

int main(){

// primary data type in C : int(32 bits), char, double, float(32 bit)
// complex data types in C are : arrays, structs, pointers


    printf("hello world \n"); // statements end with semicolons
    return 0;
}
```

### Check size using sizeof
```c
#include <stdio.h>

int main() {
    if (sizeof(int) == 4) {
        printf("int is 32-bit\n");
    } else if (sizeof(int) == 8) {
        printf("int is 64-bit\n");
    } else {
        printf("int is %zu bytes\n", sizeof(int));
    }
    return 0;
}
```


### Integer variations
```c
/*
========================================================
INTEGER DATA TYPES IN C
========================================================

Integers are data types that store whole numbers
(positive and negative), without decimals.

C provides several variations depending on:
- Size (how many bytes)
- Signed or unsigned
- Fixed-width guarantees

========================================================
1) BASIC SIGNED INTEGER TYPES
========================================================
*/

#include <stdio.h>
#include <stdint.h>   // For fixed-width integer types
#include <limits.h>   // For min/max limits

int main() {

    /*
    signed char
    - Usually 1 byte
    - Range: -128 to 127
    */
    signed char a = -100;

    /*
    short (short int)
    - At least 2 bytes
    */
    short b = -32000;

    /*
    int
    - Usually 4 bytes
    */
    int c = -100000;

    /*
    long
    - 4 bytes (Windows)
    - 8 bytes (Linux 64-bit)
    */
    long d = -1000000L;

    /*
    long long
    - At least 8 bytes
    */
    long long e = -9000000000LL;


    /*
    ========================================================
    2) UNSIGNED INTEGER TYPES
    ========================================================

    Unsigned types store ONLY positive numbers (including 0).
    They give a larger positive range because no bit is used for sign.
    */

    unsigned char ua = 255;
    unsigned short ub = 65000;
    unsigned int uc = 4000000000U;
    unsigned long ud = 1000000000UL;
    unsigned long long ue = 180000000000ULL;


    /*
    ========================================================
    3) FIXED-WIDTH INTEGER TYPES (from <stdint.h>)
    ========================================================

    These guarantee exact sizes across platforms.
    Useful for:
    - Embedded systems
    - Networking
    - File formats
    */

    int8_t   f  = -120;        // exactly 8 bits
    int16_t  g  = -32000;      // exactly 16 bits
    int32_t  h  = -2000000000; // exactly 32 bits

    uint8_t  uf = 250;         // unsigned 8-bit
    uint16_t ug = 60000;       // unsigned 16-bit
    uint32_t uh = 4000000000U; // unsigned 32-bit


    /*
    ========================================================
    4) PRINTING VALUES
    ========================================================
    */

    printf("signed char: %d\n", a);
    printf("short: %d\n", b);
    printf("int: %d\n", c);
    printf("long: %ld\n", d);
    printf("long long: %lld\n", e);

    printf("unsigned int: %u\n", uc);
    printf("uint32_t: %u\n", uh);

    /*
    ========================================================
    5) CHECKING SIZE OF TYPES
    ========================================================
    */

    printf("\nSizes in bytes:\n");
    printf("char: %zu\n", sizeof(char));
    printf("short: %zu\n", sizeof(short));
    printf("int: %zu\n", sizeof(int));
    printf("long: %zu\n", sizeof(long));
    printf("long long: %zu\n", sizeof(long long));

    /*
    ========================================================
    IMPORTANT NOTES
    ========================================================

    1) signed is default for most integer types.
       int == signed int

    2) Sizes can vary depending on platform.

    3) Fixed-width types (int32_t etc.)
       are safer when exact size matters.

    4) Unsigned integers cannot represent negative numbers.

    5) Use <limits.h> to check ranges like:
       INT_MIN, INT_MAX, etc.
    */

    return 0;
}

/*
========================================================
SUMMARY
========================================================

Signed types:
    signed char
    short
    int
    long
    long long

Unsigned types:
    unsigned char
    unsigned short
    unsigned int
    unsigned long
    unsigned long long

Fixed-width types:
    int8_t, int16_t, int32_t
    uint8_t, uint16_t, uint32_t

Use fixed-width types when size must be exact.
========================================================
*/
```

### Use fixed-width integer types (Best Practice)
```c
#include <stdio.h>
#include <stdint.h>

int main() {
    printf("int32_t size: %zu\n", sizeof(int32_t));
    printf("int64_t size: %zu\n", sizeof(int64_t));
    return 0;
}
```
int is:

Usually 32-bit
Almost never 64-bit
But the C standard only guarantees:
```c
sizeof(char) <= sizeof(short) <= sizeof(int) <= sizeof(long)
```

### Dynamic Memory Allocation
- Done through functions such as malloc(), calloc(), realloc() and *free()* for allocation and deallocation of memory during runtime.

```c
#include <stdio.h> // Includes standard input/output functions like printf and scanf
#include <stdlib.h> // Includes functions like malloc(), free(), and exit()

int main() { // Main function: program execution starts here

  int *ptr; // Declare a pointer to an integer (will point to dynamically
            // allocated memory)
  int i, n; // Declare two integers:
            // i = loop counter
            // n = number of elements the user wants

  printf("Enter the number of elements: "); // Ask user for number of elements
  scanf("%d", &n); // Read user input and store it in variable n

  // Dynamically allocate memory using malloc()
  // malloc allocates memory for n integers (n * size of int bytes)
  // we cast because malloc() returns a void pointer (void *).
  // void * means “This is a pointer to some memory, but I’m not telling you
  // what type it is.”
  // (int *) tells the compiler: “Treat the memory returned by malloc() as a
  // pointer to int.”
  // In C → NOT required, In C, a void * is automatically converted to any other pointer type.
  // ptr = malloc(n * sizeof(int));
  ptr = (int *)malloc(n * sizeof(int));

  // Check if the memory has been successfully allocated
//ptr will be NULL if:
//The system is out of memory
//The requested size is too large
//Allocation fails for any reason

  if (ptr == NULL) { // If malloc returns NULL, allocation failed
    printf("Memory not allocated. \n"); // Print error message
    exit(0);                            // Exit the program immediately
  } else {
    // If we reach here, memory allocation was successful

    printf("Memory has been allocated successfully using malloc. \n");

    // Store values into allocated memory (like an array)
    for (i = 0; i < n; ++i) { // Loop from 0 to n-1
      ptr[i] = i + 1;         // Assign values 1, 2, 3, ..., n
    }

    // Print the elements stored in memory
    printf("The elements of the array are: ");
    for (i = 0; i < n; i++) { // Loop again from 0 to n-1
      printf("%d, ", ptr[i]); // Print each element
    }

    // Free the allocated memory
    free(ptr); // Releases the memory back to the system
    printf("\nmemory freed successfully \n");
  }

  return 0; // Indicate successful program execution
}

```

Run:
```bash
~/Downloads/cprogramming_william_smith_note ❯ gcc main.c -Wall -Wextra -pedantic -o main -DDEBUG && ./main 
Enter the number of elements: 10
Memory has been allocated successfully using malloc. 
The elements of the array are: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
memory freed successfully 

```

### Allocate memory for ONE string
```c
#include <stdio.h>
#include <stdlib.h>

int main() {

    char *ptr;
    int n;

    printf("Enter maximum length of string: ");
    scanf("%d", &n);

    ptr = (char *)malloc((n + 1) * sizeof(char));  
    // +1 for the null terminator '\0'

    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }

    printf("Enter a string: ");
    scanf("%s", ptr);   // reads a word (no spaces)

    printf("You entered: %s\n", ptr);

    free(ptr);
    printf("Memory freed successfully\n");

    return 0;
}
```

### Allocate memory for MULTIPLE strings
```c
#include <stdio.h>
#include <stdlib.h>

int main() {

    char **ptr;
    int n = 3;
    int size = 20;
    int i;

    // Allocate memory for array of string pointers
    ptr = (char **)malloc(n * sizeof(char*));

    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }

    // Allocate memory for each string
    for (i = 0; i < n; i++) {
        ptr[i] = (char *)malloc(size * sizeof(char));

        if (ptr[i] == NULL) {
            printf("Memory not allocated for string %d.\n", i);
            exit(0);
        }
    }

    // Input strings
    for (i = 0; i < n; i++) {
        printf("Enter string %d: ", i + 1);
        scanf("%s", ptr[i]);
    }

    // Print strings
    for (i = 0; i < n; i++) {
        printf("String %d: %s\n", i + 1, ptr[i]);
    }

    // Free memory
    for (i = 0; i < n; i++) {
        free(ptr[i]);
    }
    free(ptr);

    printf("Memory freed successfully\n");

    return 0;
}
```

Note: ⚠ Why many C programmers avoid casting malloc
If you forget to include <stdlib.h>, like this:
```c
#include <stdio.h>
// #include <stdlib.h>   ← missing!

Then malloc() has no proper declaration.
Without the cast, the compiler warns you.
But with the cast, the warning might disappear — hiding a serious problem.

That’s why many experienced C programmers write:

int *ptr = malloc(n * sizeof *ptr);
This is:
Cleaner
Safer
More idiomatic C
```

### Compiler
Translate human readable code into machine code which the hardware executes.
 **Process involves different stages:**
- Lexical analysis
- Syntax analysis
- Semantic analysis
- Optimization
- Code generation


**Lexical Analysis (Scanner)**
Lexical analysis is the first stage of compilation.

In this stage, the compiler reads the source code character by character and groups them into tokens.

A token is the smallest meaningful unit in a program.

```c
#include <stdio.h>

int main(){

int count_word = 9;
    return 0;
}
```

**Examples of tokens: **
Keywords → int, return
Identifiers → main, count_word
Operators → =, +, -
Separators (punctuation) → (, ), {, }, ;
Literals → 9, 0
Preprocessor symbols → #, include

**Important Clarification**
- The lexical analyzer:
- Does not check grammar.
- Does not check meaning.
- It only converts character streams into tokens.


**Syntax Analysis**:
Also called parsing, this is the second stage of compilation.

The compiler takes the tokens produced by the lexical analyzer and checks whether they follow the grammar rules of the programming language (e.g., C).
It ensures that the token sequence forms a valid syntactic structure.

The output of this stage is usually a parse tree or syntax tree, which represents the hierarchical structure of the source code.

**Example**:
For the statement:
```c
int x = 5;
```
Tokens from lexical analysis: int, x, =, 5, ;

Syntax analysis checks:
int → valid type
x → valid identifier
= → valid assignment operator
5 → valid literal
; → statement terminator
If the sequence violates C grammar, the compiler reports a syntax error.

**Semantic Analysis**

Semantic analysis is the third stage of compilation, which comes after syntax analysis.

While syntax analysis checks if the structure of the code is correct, semantic analysis checks if the meaning of the code is valid.

It ensures that the program obeys the rules of the language regarding types, declarations, and operations.

**Key Checks Performed:**
Type checking – ensures operations are done between compatible types.
```c
int x = "hello";  // Error: assigning string to int
```
Declaration checks – ensures variables and functions are declared before use.
```c
y = 10; // Error: 'y' not declared
```
Scope and visibility checks – ensures variables are accessed only in valid scopes.
Function call validation – checks number and types of arguments.
```c
int sum(int a, int b);
sum(5); // Error: argument count mismatch
```
Constant evaluation – ensures constants are not modified.
```c
const int PI = 3;
PI = 4; // Error: cannot assign to constant
```

**Code Generation (Final Stage)**

Code generation is the final stage of the compilation process.

In this stage, the compiler converts the optimized intermediate representation (IR) of the program into target machine code (or assembly code) that the computer’s processor can execute.

What Happens in Code Generation?

**Instruction Selection**
The compiler translates intermediate operations into equivalent machine instructions.
Example:
```c
a = b + c
```
might become something like:
```text
LOAD R1, b
ADD  R1, c
STORE a, R1
```
**Register Allocation **
The compiler decides which variables should be stored in CPU registers (fast access) and which should be stored in memory.

**Address Calculation**
Memory locations for variables, arrays, and functions are determined.

**Machine Code Emission**
The final binary or assembly instructions are generated.


### C Compiler
Most popular is the GNU Compiler Collection
```bash
# install
sudo apt update 
sudo apt install build-essential

# check version
gcc --version
```


### Compiling and running C
processes involved:
- preprocessing: handling e.g #include, #define. Resolves before actual compilation begins
- compilation: converts actual c code into assembly language(syntactic and semantic analysis)
- assembly: assembler converts assembly code into machine code to produce .o or .obj binary code.
- linking: combines object files with necessary binaries to generate executable file.

gcc -o main main.c
gcc - GNU compiler
-o - name of executable output
-Wall - enable all compilers warning messages
-g - Includes debugging information, useful for gdb
-O - activates Optimization
```bash
gcc -Wall -g -O -o main main.c
```


### Variables
```c
#include <stdio.h>

// Standard library are collections of headers files and library routines used
// to perform various operations e.g i/o. operations, memory management etc
// common standard library
// <stdio.h> standard input/output
// <stdlib.h> - standard library functions
// <string.h> - string handling
// <math.h> - math functions

// Format specifiers:
// %d - integers
// %i - integers
// %s - strings
// %f - floating points
// %c - for characters

int main() {

  // Data types
  char name[] = "abayomi"; // characters are stored as integer values corresponding to their ASCII codes
  int myInt = 10; // variable declaration and initialization
  double balance = 90.89;
  float ledgerBaalance = 90.89f;
  char grade = 'A';

  // printf(""); is used for printing to the standard output
  printf("Name is: %s\n", name);
  printf("float is: %f\n", ledgerBaalance);
  printf("float is with decimal format: %.2f\n", ledgerBaalance);
  printf(" double is: %f\n", balance);
  printf("char is: %c\n", grade);
  printf("int is: %i\n", myInt);

  // scanf(""); is used for reading into the standard input

  // Prompt the user to enter a number
  printf("Enter a number: ");

  // Declare an integer variable to store the input
  int num;

  // Read an integer from standard input and check if it was successful
  // scanf("%d", &num) returns the number of successful assignments
  // If it is not 1, it means the user input was invalid
  // if failed, then it returns 0 (or EOF if the input is interrupted).
  if (scanf("%d", &num) != 1) {
    // Inform the user about invalid input
    printf("Invalid number!\n");
    // Exit the program with a non-zero status to indicate an error
    return 1;
  }

  // Declare a character array (string) to store the name
  // Size 80 to prevent buffer overflow
  char magicName[80];

  // Prompt the user to enter a name
  printf("Enter a name: ");

  // Read a string from standard input with a maximum of 79 characters
  // %79s prevents writing beyond the array (leaving 1 byte for '\0')
  // Check if the input was successful
  if (scanf("%79s", magicName) != 1) {
    // magicName is an array of characters.
    // In C, an array name decays to a pointer to its first element
    // So magicName is already of type char *.
    // Using &magicName would give it type char (*)[80] (pointer to the whole
    // array), which does not match what scanf("%s", ...) expects.
    // For numeric types like int, float, double, etc., you do need & because
    // you need to pass a pointer to the variable so scanf can write the value
    // there.

    // automatically Inform the user if reading the name failed
    printf("Failed to read a name!\n"); // also a statement
    // Exit the program with an error code
    return 1; //this is a statement, statements are instructions given to perform specific task
  }

  printf("Enter a character: ");
  char character;

  // " %c" – the leading space tells scanf to skip any whitespace characters
  // (spaces, tabs, newlines) before reading a single character. Why is this
  // necessary? Without the space: scanf("%c", &character); If the previous
  // scanf left a newline \n in the input buffer (from pressing Enter),
  // scanf("%c", ...) will read that leftover newline as the character.
  // e.g Enter a number: 5⏎

  //  Rule of thumb:
  // Use " %c" when reading a single character after any other input that might
  // leave a newline or space in the buffer.

  // You don’t need the space if you’re the first input in the program, but it’s
  // safer to always include it in multi-input scenarios.
  if (scanf(" %c", &character) != 1) {
    printf("invalid character entered. \n");
    return 1;
  }

  printf("You entered: %d and a name called: %s, your grade is %c\n", num,
         magicName, character);
  return 0;
}
```

### Functions
```c
#include <stdio.h>

// function prototype : enforces the compiler to type check the function
void greet();

int main() {
  greet();
  return 0;
}

// function definition
void greet() { printf("say hello \n"); }
```

### C keywords
```text
The following is a list of standard keywords in C:
auto double int struct break else long switch
case enum register typedef char extern return union
const float short unsigned continue for signed void
default goto sizeof volatile do if static while
```

### Global vs local identifier
```c


#include <stdio.h>

int globalVariable = 12; // global variable

// function definition
void doSomething() {
  int x = 19;           // local identifier
  globalVariable = 123; // global variable accessed and modified here
  x--;                  // can access local variable here too
}

int main() {
  globalVariable = 1; // global variable accessed and modified here too
  printf("%d\n", globalVariable);
  doSomething();
  return 0;
}
```


#### Data types
```c
#include <stdio.h>
#include <string.h>

struct Person {
  char name[30]; // array → fixed memory, must use strcpy/strncpy
  int age;
  float salary;
  char *color; // pointer → can directly assign string literal;
};

typedef struct{
  int age;
  char name[100];
  } Male;

// UNION: members share same memory, only one valid at a time
// similar to structure but members of unions share the same memory location.
// i.e you can store different data types in the same memory location, but
// only once member can hold a value at a time.
union Student {
  int age;
  float height;
  char color[20]; // writing to one overwrites others
};

int main() {

  Male m;
  m.age = 19;
  strcpy(m.name, "Rnady");
  printf("%s\n", m.name);

  // Data types
  char grade =
      'A'; // stored as integer values, 1 byte of memory(8 bits), range -128 to
           // 127 for signed char and 0 to 255 for unsigned representation.

  int age =
      19; // usually occupies 4 bytes, but can vary. it is dependent on size and
  // whether it is signed or unsigned signed int: -2,147,483,648 to
  // 2,147,483,647 (4 bytes) unsigned int: 0 to 4,294,967,295

  // unsigned means the variable cannot store negative numbers
  unsigned int y = 10;
  // unsigned int y = -10; // ⚠ NOT correct

  // smaller variants of int
  short int si = -32;
  long long int li = 23232323232LL;

  // floats - 4 bytes i.e 24 bits,7 decimal precision
  // double - 8 bytes, precision is 15 decimal digits

  // Derived data types: pointers, structures, unions
  // 1. Arrays: collection of elements of the same types.
  int arr[4] = {1, 2, 3, 4}; // 4 elements

  // 2. Pointers
  // variable that stores the memory address of another variable
  int p = 89;
  int *ptr = &p;

  printf("Value of p: %d\n", p);
  printf("Address of p: %p\n", (void *)&p);
  printf("Pointer value: %p\n", (void *)ptr);
  printf("Value through pointer: %d\n", *ptr); // dereferencing: accessing the value at the address stored in pointer

  struct Person p1;
  p1.age = 1;
  p1.color = "blue"; // we can use this method because we declared char *color;
                     // pointer allows direct assignment
  strcpy(p1.name, "jude"); // when we use char name[]; we use this approach
                           // fixed array requires copy
  // An array has fixed memory — you must copy into it.
  // contiguous memory, fixed type
  strncpy(p1.name, "James",
          sizeof(p1.name) - 1); // Instead of strcpy, better practice:

  printf("Name: %s\n", p1.name);
  printf("Color: %s\n", p1.color);
  printf("Age: %d\n", p1.age);
  printf("Salary: %.2f\n", p1.salary);

  // initialize struct
  struct Person p2 = {"James", 19, 10.29f, "red"};

  printf("Name: %s\n", p2.name);
  printf("Color: %s\n", p2.color);
  printf("Age: %d\n", p2.age);
  printf("Salary: %.2f\n", p2.salary);

  // union
  union Student s1;
  s1.age = 90;                // sets memory
  strcpy(s1.color, "purple"); // overwrites age! unions share memory.  color
                              // will override the age in the union
  printf("Union Age: %d\n", s1.age); // prints garbage due to overwrite

  // enumeration
  enum Scores { HIGH, LOW, MEDIUM };
  // HIGH is automatically assigned 0, LOW = 1, MEDIUM = 2 by default.
  enum Scores result = HIGH;
  printf("Enum result is: %d\n", result); // prints 0

  const char *scoreNames[] = {"HIGH", "LOW", "MEDIUM"};
  printf("Enum result is: %s\n", scoreNames[result]); // prints "HIGH"

  return 0;
}
```


### Constants
```c
#include <stdio.h>

// constants are immutable values, cannot be changed during execution

#define PI 3.14

int main() {

  const int MAX_AGE = 90;
  printf("constant using define directive: %f\n", PI);
  printf("constant using const keyword: %d\n", MAX_AGE);
  return 0;
}
```

### Ternary operator
```c

int main(){
int x = 5;
const char *result = (x > 0) ? "Positive" : "Non-positive";
printf("%s\n", result);
}
```


### Main function
Method 1:
```c
#include <stdio.h>

int main(void) {
  // void means the function does not take in any parameter
  // suitable for programs that doesnt take or require command line arguments

  return 0;
}
```
Method 2:
```c
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // argc : number of arguments including program name
  // argv : array of strings (char pointers) holding each argument

  printf("Total arguments (argc): %d\n", argc);

  // Loop through all arguments
  for (int i = 0; i < argc; i++) {
    printf("argv[%d] = %s\n", i, argv[i]);
  }

  // Example: check if at least 2 arguments were passed
  if (argc < 3) {
    printf("Not enough arguments! Usage: ./main arg1 arg2\n");
  } else {
    printf("First argument: %s\n", argv[1]);
    printf("Second argument: %s\n", argv[2]);

    // Example: using ternary operator
    printf("Is first argument 'hello'? %s\n",
           (strcmp(argv[1], "hello") == 0) ? "Yes" : "No");
  }

  return 0;
}

/*
Example run:

$ ./main op1 op2

Output:
Total arguments (argc): 3
argv[0] = ./main
argv[1] = op1
argv[2] = op2
First argument: op1
Second argument: op2
Is first argument 'hello'? No
*/
```


### No magic hardcoded values
```c
#include <stdio.h>
#define SUCCESS 0
#define ERROR 1

int main(void) {
  FILE *file = fopen("ex.txt", "r");
  if (file == NULL) {
    fprintf(stderr, "Error: Error opening file \n");
    return ERROR;
  }

  fclose(file);
  return SUCCESS;
}
```


### Headers
- Standard library: e.g <stdio.h>
- User-defined library e.g #include "someheader.h";
Libraries come in two forms :
- static libraries: has .a extension on unix and .lib on windows
- dynamic libraries: aka shared libraries have .so extension(unix) or .dll(windows)
steps:
- create mylib.c
```c
// Including "mylib.h" inside mylib.c is good practice — it ensures the function
// definition matches the declaration.

#include "mylib.h"
#include <stdio.h>

void greet() { printf("greeting\n"); }
```

- create mylib.h
```c
#ifndef MYLIB_H // Perfect header guard
#define MYLIB_H

void greet();

#endif
```

Then in main.c
```c
#include "mylib.h"

int main(void) {
  greet();
  return EXIT_SUCCESS;
}

```
gcc main.c mylib.c -o program

To compile a static library:
Static Library (.a)
```bash

# 1. Compile object file
gcc -c mylib.c

# 2. Create static library
ar rcs libmylib.a mylib.o

# 3. Compile main and link static library
gcc main.c -L. -lmylib -o program #-L tells the linker to search for libraries in the current directory and -lmylib specifies the library to link with.

# 4. Run
./program
```

Dynamic/Shared Library (.so)
```bash

# 1. Compile with position-independent code
gcc -fPIC -c mylib.c

# 2. Create shared library
gcc -shared -o libmylib.so mylib.o

# 3. Compile main and link shared library
gcc main.c -L. -lmylib -Wl,-rpath=. -o program

# 4. Run
./program
```

### Modifiers in C

Modifiers are keywords that change the size, range, or behavior of basic data types like int and char.

Think of modifiers as “adjustments” you apply to a type to control:

How much memory it uses
Whether it can store negative numbers
How large or small the values can be

### signed and unsigned

These control whether a variable can store negative numbers.

🔹 signed (default for int and char)

Can store positive and negative values.

Example:
```c
int a = -10;   // valid
char b = -5;   // valid

// by default
int      // same as signed int
char     // usually same as signed char (depends on compiler)


// Modifiers change size and whether negatives are allowed

int a = -10;                 // signed by default (can be negative)
char b = -5;                 // usually signed by default

unsigned int u = 10;         // only positive values (no negatives)

short int si = 100;          // smaller range than int

long int li = 1000000L;      // larger range than int (L = long literal)

unsigned short us = 25;      // small, positive-only integer

unsigned long ul = 4000000000L; // large, positive-only integer

```


### Arrow operator
```c
#include <stdio.h>

struct Point {
  int x;
  int y;
};

int main(void) {

  struct Point p1 = {10, 20}; // normal struct variable

  struct Point *ptr = &p1; // pointer to struct

    // Accessing members using dot operator (for normal struct variable)
printf("dot operator: x = %d\n", p1.x);  // Access x using .
printf("dot operator: y = %d\n", p1.y);  // Access y using .

    // ✅ Accessing members using arrow operator (for pointer to struct)
  printf("arrow operator: x = %d\n", ptr->x);
  printf("arrow operator: y = %d\n", ptr->y);

  // modifying values using arrow operator
  ptr->x = 30;
  ptr->y = 40;

  printf("Updated x = %d\n", ptr->x);
  printf("Updated y = %d\n", ptr->y);

  return 0;
}
```

### enum
```c
#include <stdio.h>

// by default enums start from 0
enum Week { Sunday, Monday, Tuesday, Wednesday, Thursday };

// you can override the starting point
enum Grade { High = 1, Medium = 2, Low = 3 };

int main(void) {

  enum Week today = Tuesday;
  enum Grade studentGrade = High;

  printf("Today (numeric value): %d\n", today);
  printf("Student Grade (numeric value): %d\n", studentGrade);

  // Changing values
  today = Thursday;
  studentGrade = Low;

  printf("Updated Today (numeric value): %d\n", today);
  printf("Updated Grade (numeric value): %d\n", studentGrade);

  return 0;
}
```


### sizeof of modifiers

```c
#include <limits.h>
#include <stdio.h>

int main() {

  // Important Concept
  // Type modifiers:

  // short → usually smaller range
  // long → larger range
  // unsigned → no negative values
  // signed → allows negatives (default for int)

  // They affect:
  // Memory size
  // Value range

  printf("double: %zu bytes\n", sizeof(double));
  printf("float: %zu bytes\n", sizeof(float));
  printf("char: %zu bytes\n", sizeof(char));
  printf("short: %zu bytes\n", sizeof(short));
  printf("int: %zu bytes\n",
         sizeof(int)); // by default int type is signed (both -v and +v)
  printf("long: %zu bytes\n", sizeof(long));
  printf("long long: %zu bytes\n", sizeof(long long));

  // Type modifiers alter size and/or range.
  // Primary modifiers: signed, unsigned, short, long.

  short int shortVar = 90;
  unsigned int unsignedVar = 100;
  long int longVar = 1000000L;
  long long int bigVar = 9000000000LL;

  printf("shortVar: %zu bytes\n", sizeof(shortVar));
  printf("unsignedVar: %zu bytes\n", sizeof(unsignedVar));
  printf("longVar: %zu bytes\n", sizeof(longVar));
  printf("bigVar: %zu bytes\n", sizeof(bigVar));

  // overflow: Overflow happens when a variable tries to store a number that is
  // outside its allowed range. Every data type has a minimum and maximum value
  // it can store.
  // If you go past that limit, the value “wraps around” (for unsigned) or
  // causes undefined behavior (for signed).

  unsigned char x = 255; // max value for 1 byte
  printf("Before overflow: %u\n", x);

  x = x + 1; // overflow happens here, 255 + 1 = 256
             // But max is 255 → so it wraps to 0.

  printf("After overflow: %u\n", x); // becomes 0

  // int overflow
  int h = INT_MAX; // maximum int value
  printf("Before overflow: %d\n", h);

  h = h + 1; // signed overflow
  printf("After overflow: %d\n", h);

  // Short overflow
  short s = SHRT_MAX;
  printf("\nShort overflow:\nBefore: %d\n", s);
  s++;
  printf("After: %d\n", s); // wraps to SHRT_MIN

  // Long overflow (for demonstration, may vary by system)
  long l = LONG_MAX;
  printf("\nLong overflow:\nBefore: %ld\n", l);
  l++;
  printf("After: %ld\n", l); // undefined behavior for signed long

  return 0;
}
```

### Default initialization
- Local variables (inside functions) are not automatically initialized.
- Their values are garbage (whatever happens to be in memory).
- Only static or global variables are automatically initialized to 0.
```c
#include <stdio.h>

int globalVar;        // global variable → automatically 0
static int staticVar; // static variable → automatically 0

int main() {
    int localVar;     // local variable → not initialized (garbage)
    
    printf("Global: %d\n", globalVar);   // 0
    printf("Static: %d\n", staticVar);   // 0
    printf("Local: %d\n", localVar);     // garbage (random value)
    
    return 0;
}
```

### scope
```c
#include <stdio.h>
#include <stdlib.h>

int globalVar; // global variable → automatically 0. this variable is globally
               // accessible

// Static variable retain their value throughout the execution of the program.
static int staticVar; // static variable → automatically 0

void demoFunction() {
  static int funcStatic = 5; // retains value between calls
  int autoVar = 10;          // automatic → destroyed after function ends

  printf("funcStatic: %d\n", funcStatic);
  printf("autoVar: %d\n", autoVar);

  funcStatic++;
  autoVar++;
}

int main() {
  int localVar; // local variable → not initialized (garbage). automatic local
                // variable → garbage

  printf("Global: %d\n", globalVar); // 0
  printf("Static: %d\n", staticVar); // 0
  printf("Local: %d\n", localVar);   // garbage (random value)
                                     //

  demoFunction(); // funcStatic=5, autoVar=10
  demoFunction(); // funcStatic=6, autoVar=10 (autoVar resets)
                  //

  // dynamic allocation: variables allocated at runtime using malloc(),
  // calloc(), realloc(), free() functions. remains valid until freed()

  int *ptr = (int *)malloc(sizeof(int)); // Dynamically allocate memory
  if (ptr == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }
  *ptr = 100;
  printf("Dynamically allocated value: %d\n", *ptr);
  free(ptr); // Deallocate memory

  return 0;
}
```


### Constants
```c
#include <stdio.h>

// constant using #define directive/macros
#define PI 3.14

int main() {
  // literal constant: passed directly in code
  printf("Integer constant: %d\n", 10);
  printf("Floating point constant: %f\n", 11.20);
  printf("character constant: %c\n", 'A');

  // printing constant from macros
  printf("PI values is %f\n", PI);
  printf("PI values is %d\n", (int)PI); // cast

  // using const keyword
  const int MAX_AGE = 19;
  printf("%d\n", MAX_AGE);
}
```

### enum and structs
```c
#include <stdio.h>
#include <string.h>

enum Status { INACTIVE, SUSPENDED, ACTIVE };

struct User {
  int age;
  char name[50];
  enum Status status;
};

int main() {
  struct User userOne;
  userOne.age = 10;
  strcpy(userOne.name, "jude");
  userOne.status = ACTIVE;

  printf("%d\n", userOne.status);
  printf("%s\n", userOne.name);
  printf("%d\n", userOne.age);
}
```


### Pointer
```c
#include <stdio.h>

int main() {

    int val = 65;           // Declare an integer variable 'val' and initialize it to 65

    void *ptr = &val;       // Declare a void pointer 'ptr' and store the address of 'val'
                             // void* can hold the address of any data type

    int *intPtr = (int *)ptr; // Cast the void pointer back to an int pointer
                               // Now 'intPtr' points to the same location as 'ptr'

    printf("%d\n", *intPtr);  // Dereference 'intPtr' to get the value of 'val' and print it
                               // Outputs: 65

    return 0;                 // Return 0 to indicate successful execution
}
```


### Storage classes
```c
#include <stdio.h>

// Global variable using 'extern' storage class
extern int globalVar; // 'extern' tells the compiler this variable is defined elsewhere

int main() {
    
    // 1. auto (default for local variables)
    auto int a = 10;    // 'auto' is the default for local variables, stores in stack
                         // 'auto' keyword is optional; same as writing 'int a = 10;'
    
    // 2. register
    register int b = 20; // Suggests storing 'b' in CPU register for faster access
                          // Cannot take address of 'b' (&b is invalid)
    
    // 3. static
    static int c = 30;   // Local static variable: retains value across function calls
                          // Stored in data segment, not stack
    
    printf("auto a = %d\n", a);
    printf("register b = %d\n", b);
    printf("static c = %d\n", c);
    
    // Demonstrating static retaining value
    c++;
    printf("static c after increment = %d\n", c);
    
    return 0;
}

// Definition of the extern variable
int globalVar = 100;      // 'extern' in main() refers to this definition
```



### site_t;
size_t is an unsigned integer type used to represent sizes and memory counts in C.
Used for: sizes of objects, array indexing, sizeof, memory functions.
Defined in: <stddef.h>, <stdio.h>, <stdlib.h>, etc.
It is unsigned (cannot store negative values).
Its size depends on the system (e.g., 4 bytes on 32-bit, 8 bytes on 64-bit).

🔹 Why it exists
Because memory sizes can never be negative.

Example:
You can't have -10 bytes.
So C uses an unsigned type designed specifically for sizes → size_t.
```c
#include <stdio.h>
#include <stdlib.h>

int main() {

    int arr[10];

    size_t size = sizeof(arr);   // sizeof returns size_t
    printf("Size of array in bytes: %zu\n", size);

    size_t length = sizeof(arr) / sizeof(arr[0]); // number of elements
    printf("Number of elements: %zu\n", length);

    // Using size_t in loops (recommended)
    for (size_t i = 0; i < length; i++) {
        printf("Index: %zu\n", i);
    }

    return 0;
}
```

🔹 Important Notes
Use %zu to print size_t.
sizeof always returns size_t.
Functions like malloc() use size_t:
```c
int *ptr = malloc(10 * sizeof(int)); // argument type is size_t
```

| Type     | Signed? | Used For                       |
| -------- | ------- | ------------------------------ |
| `int`    | Yes     | General numbers                |
| `size_t` | No      | Sizes / memory / array indexes |

### Conditionals
```c
#include <stdio.h>

int main() {

    int x = 2;

    // =========================
    // 1️⃣ if / else if / else
    // =========================
    if (x == 1) {
        printf("x is 1\n");
    } 
    else if (x == 2) {
        printf("x is 2\n");
    } 
    else {
        printf("x is something else\n");
    }

    // =========================
    // 2️⃣ switch statement
    // =========================
    switch (x) {
        case 1:
            printf("Switch: x is 1\n");
            break;              // prevents fall-through
        case 2:
            printf("Switch: x is 2\n");
            break;
        default:
            printf("Switch: default case\n");
    }

    // =========================
    // 3️⃣ Ternary operator
    // =========================
    (x % 2 == 0) ? 
        printf("x is even\n") : 
        printf("x is odd\n");

    // =========================
    // 4️⃣ goto and labels
    // =========================
    if (x == 2) {
        goto success;   // jump to label
    }

    goto end;           // unconditional jump

success:                // label
    printf("Jumped to success label\n");

end:                    // label
    printf("Program ending\n");

    return 0;
}
```


### goto
```c
#include <stdio.h>
#include <stdlib.h>

int processFile(const char *filename) {

    // Try to open file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        goto error;   // jump to final error return
    }

    // Allocate memory
    int *buffer = (int *)malloc(100 * sizeof(int));
    if (buffer == NULL) {
        perror("Memory allocation failed");
        goto cleanup_file;  // file opened, so close it
    }

    // Read integers from file
    for (int i = 0; i < 100; i++) {
        if (fscanf(file, "%d", &buffer[i]) != 1) {
            perror("Error reading file");
            goto cleanup_memory;  // free memory + close file
        }
    }

    // ✅ Normal success path
    free(buffer);     // release memory
    fclose(file);     // close file
    return 0;

    // =========================
    // 🔻 Cleanup section
    // =========================

cleanup_memory:
    free(buffer);     // free allocated memory

cleanup_file:
    fclose(file);     // close opened file

error:
    return -1;        // indicate failure
}

int main() {

    if (processFile("data.txt") == -1) {
        printf("Failed to process file.\n");
    }

    return 0;
}
```


### char[] vs char[size]
```c
#include <stdio.h>

int main() {

    // Explicit size (19 bytes total)
    char name1[19] = "james";
    // "james" = 6 bytes (j a m e s \0)
    // Remaining 13 bytes are '\0'
    // Can store longer string later (up to 18 chars + '\0')

    // Auto-sized by compiler
    char name2[] = "james";
    // Compiler makes it:
    // char name2[6] = "james";
    // Exactly fits 5 chars + null terminator
    // No extra space

    printf("name1: %s (size: %zu)\n", name1, sizeof(name1));
    printf("name2: %s (size: %zu)\n", name2, sizeof(name2));

    // Modifying contents is allowed
    name1[0] = 'J';
    name2[0] = 'J';

    // But arrays cannot be reassigned
    // name1 = "john";  // ❌ ERROR
    // name2 = "john";  // ❌ ERROR

    return 0;
}

/*
TL;DR

char name[19] = "james";
→ Fixed size 19 bytes (extra unused space)

char name[] = "james";
→ Auto-sized to 6 bytes (exact fit)

Both are arrays.
Arrays cannot be reassigned.
*/
```


### Funcitons
```c
/*
===============================
TL;DR — FUNCTION PROTOTYPE vs HEADER (.h)
===============================

1) FUNCTION PROTOTYPE (Single .c file)

- A prototype tells the compiler a function exists BEFORE it is used.
- It is usually placed at the top of the .c file.
- Parameter names are optional in the prototype.

Example (single file):

#include <stdio.h>

int add(int, int);   // <-- prototype (declaration)

int main() {
    int result = add(6, 3);   // compiler knows add() exists
    printf("%d\n", result);
    return 0;
}

int add(int x, int y) {   // <-- definition (implementation)
    return x + y;
}

Why needed?
Because the compiler reads top-to-bottom. Without the prototype,
main() would not know what add() is.

----------------------------------

2) USING A HEADER FILE (.h) (Multiple files)

Used when splitting code into multiple files.

square.h  (declaration only)
----------------------------------
#ifndef SQUARE_H
#define SQUARE_H

int square(int);   // function declaration

#endif
----------------------------------

square.c  (definition / implementation)
----------------------------------
#include "square.h"

int square(int n) {
    return n * n;
}
----------------------------------

main.c  (usage)
----------------------------------
#include <stdio.h>
#include "square.h"   // gives access to square()

int main() {
    int num = 5;
    printf("%d\n", square(num));
    return 0;
}
----------------------------------

Why use .h files?

- Avoid repeating prototypes in multiple files
- Share function declarations safely
- Keep code organized
- #ifndef prevents multiple inclusion errors

----------------------------------

SUMMARY

Prototype in same file:
    int func(int);      // declare at top
    int func(int x) {}  // define later

Header file approach:
    Put declarations in .h
    Put definitions in .c
    #include the .h wherever needed

Prototype = tells compiler a function exists.
Definition = actual function code.
Header = shared declaration file.
*/
```



#### Pass by value vs reference
```c
#include <stdio.h>

/* PASS BY VALUE
   - A copy of the variable is passed.
   - Changes inside the function do NOT affect the original variable.
*/
void passByValue(int x) {
    x = x * 2; // only modifies local copy
}

/* PASS BY REFERENCE
   - Address of the variable is passed (using pointers).
   - Changes inside the function affect the original variable.
*/
void passByReference(int *x) {
    *x = *x * 2; // modifies the original variable through pointer
}

int main() {
    int a = 5, b = 5;

    passByValue(a);
    printf("After passByValue, a = %d\n", a); // still 5

    passByReference(&b);
    printf("After passByReference, b = %d\n", b); // now 10

    return 0;
}
```

Ex1
```c
#include <stdio.h>

/*
===============================
PASSING ARGUMENTS BY VALUE
===============================

- C passes arguments by value by default.
- Only a copy of the variable is sent to the function.
- Changes inside the function do NOT affect the original variable.
*/

void modifyValuesByValue(int x, int y) {
    x += 10;
    y += 20;
}

void modifyValuesByReference(int *x, int *y) {
    /*
    ===============================
    PASSING ARGUMENTS BY REFERENCE
    ===============================

    - We pass the address of the variable using pointers.
    - Changes inside the function modify the original variable.
    */
    *x += 10;
    *y += 20;
}

int main() {
    int a = 5, b = 10;

    // Pass by value
    modifyValuesByValue(a, b);
    printf("After pass by value: a = %d, b = %d\n", a, b);
    // Output: a = 5, b = 10 (original variables unchanged)

    // Pass by reference
    modifyValuesByReference(&a, &b);
    printf("After pass by reference: a = %d, b = %d\n", a, b);
    // Output: a = 15, b = 30 (original variables modified)

    return 0;
}

/*
TL;DR:
- Pass by value = safer, copies only, original unchanged.
- Pass by reference = use & in call, * in function, modifies original.
*/
```


### Multiple return value
```c

#include <stdio.h>

/*
=========================================
Returning Multiple Values Using struct
=========================================

- C functions can only return ONE value directly.
- To return multiple values, we use a struct.
- The struct groups related values together.
*/

typedef struct {
    int sum;
    int product;
} Results;

/*
Function returns a struct (Results).
Both sum and product are stored inside it.
*/
Results calculate(int a, int b) {
    Results res;          // create struct variable
    res.sum = a + b;      // assign sum
    res.product = a * b;  // assign product
    return res;           // return entire struct
}

int main() {

    // receive returned struct
    Results res = calculate(3, 4);

    /*
    IMPORTANT:
    You CANNOT print a struct directly like:
        printf("%d\n", res);   ❌ WRONG

    Because printf does not know how to print a struct.
    You must print each member separately.
    */

    printf("Sum = %d\n", res.sum);
    printf("Product = %d\n", res.product);

    return 0;
}

/*
OUTPUT:
Sum = 7
Product = 12

TL;DR:
- struct allows grouping multiple values.
- Function returns struct as one object.
- Access members using dot operator (res.sum).
- Cannot print a struct directly.
*/

```


### Dynamic memory
```c
#include <stdio.h>
#include <stdlib.h>

/*
=========================================
Dynamic Memory (Heap) - malloc and free
=========================================

- Memory allocated with malloc() is created on the HEAP.
- It has dynamic storage duration.
- The programmer is responsible for freeing it using free().
- If you forget to free it → memory leak.
*/

void exampleFunction() {

    // Allocate memory for ONE int on the heap
    int *dynamicVar = (int *)malloc(sizeof(int));

    /*
    malloc returns a void* (generic pointer).
    We cast it to (int *).
    sizeof(int) ensures correct number of bytes.
    */

    // Always check if allocation succeeded
    if (dynamicVar == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    // Store a value in allocated memory
    *dynamicVar = 100;

    // Access value using dereference operator *
    printf("dynamicVar: %d\n", *dynamicVar);

    // Free the allocated memory
    free(dynamicVar);

    /*
    After free():
    - Memory is returned to the system.
    - Pointer becomes dangling (still holds old address).
    - Good practice: set pointer to NULL.
    */

    dynamicVar = NULL;
}

int main() {
    exampleFunction();
    return 0;
}

/*
OUTPUT:
dynamicVar: 100

TL;DR:
- malloc() → allocates memory on heap
- *ptr → access value
- free(ptr) → releases memory
- Always check for NULL
- Always free what you malloc
*/
```


### Inline function
```c
#include <stdio.h>

/*
=========================================
INLINE FUNCTION (TL;DR)
=========================================

- The 'inline' keyword suggests to the compiler:
    "Replace the function call with the actual code."

- Purpose:
    Reduce function call overhead (stack push/pop, jump, return).

- Best for:
    Small, simple, frequently used functions.

- IMPORTANT:
    'inline' is only a suggestion.
    The compiler may ignore it.

- Avoid:
    Large functions, loops, recursion.
*/

/* Inline function example */
inline int square(int x) {
    return x * x;
}

int main() {

    int num = 5;

    /*
    Instead of:
        int result = square(num);

    The compiler may internally replace it with:
        int result = num * num;
    */

    int result = square(num);

    printf("Square = %d\n", result);

    return 0;
}

/*
OUTPUT:
Square = 25

TL;DR:
- inline = request to expand function at call site.
- Used for small, fast operations.
- Not guaranteed (compiler decides).
*/
```


#### Function pointer
```c
#include <stdio.h>

/*
=========================================
FUNCTION POINTER (TL;DR)
=========================================

- A function pointer stores the ADDRESS of a function.
- It allows you to:
    • Pass functions as arguments
    • Call different functions dynamically
    • Implement callbacks

SYNTAX:

return_type (*pointer_name)(parameter_types);

Example:
int (*funcPtr)(int, int);
*/

/* Two normal functions */
int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int main() {

    /*
    Declare a function pointer:
    It can point to any function that:
    - Returns int
    - Takes (int, int)
    */
    int (*operation)(int, int);

    /* Point to add function */
    operation = add;
    printf("Add: %d\n", operation(3, 4));

    /* Point to multiply function */
    operation = multiply;
    printf("Multiply: %d\n", operation(3, 4));

    return 0;
}

/*
OUTPUT:
Add: 7
Multiply: 12

=========================================
Key Points
=========================================

- add and multiply are function addresses.
- No & is required when assigning:
      operation = add;
- You can call using:
      operation(3,4);
  or
      (*operation)(3,4);

TL;DR:
Function pointer = variable that stores a function’s address.
Used for flexibility and callbacks.
*/
```

Ex 2:
```c
#include <stdio.h>

int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }

int main() {

  int (*operation)(int, int);

  operation = add; // we can also do operation = &add; the & is optional
  printf("Add: %d\n", operation(3, 4));

  operation = multiply;
  printf("Multiply: %d\n", operation(3, 4));

  return 0;
}
```


Function pointers
```c
#include <stdio.h>

/*
=========================================
FUNCTION POINTERS — FULL EXPLANATION
=========================================

A function pointer:
- Stores the ADDRESS of a function
- Must match the function's signature
- Can be passed as an argument
- Can be stored in arrays

Signature format:
return_type (*pointer_name)(parameter_types);
*/

/* Basic operations (all same signature: int (int, int)) */

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;  // assume b != 0
}

/*
Function that takes another function as parameter.

int (*operation)(int, int)
^     ^         ^
|     |         |
|     |         parameter types
|     pointer to function
returns int
*/
void performOperation(int (*operation)(int, int), int x, int y) {
    printf("Result: %d\n", operation(x, y));
}

int main() {

    /*
    --------------------------------------
    1) Passing function as argument
    --------------------------------------
    */

    performOperation(add, 10, 5);       // 15
    performOperation(subtract, 10, 5);  // 5
    performOperation(multiply, 10, 5);  // 50
    performOperation(divide, 10, 5);    // 2


    /*
    --------------------------------------
    2) Array of function pointers
    --------------------------------------

    We store multiple functions in one array.
    All must match: int (int, int)
    */

    int (*operations[])(int, int) = {
        add,
        subtract,
        multiply,
        divide
    };

    for (int i = 0; i < 4; ++i) {
        printf("Operation %d result: %d\n", i,
               operations[i](10, 5));
    }

    return 0;
}

/*
=========================================
WHAT'S HAPPENING?
=========================================

- add, subtract, multiply, divide
  are function addresses.

- performOperation receives a function pointer
  and executes it.

- operations[] stores multiple function pointers
  in an array.

=========================================
TL;DR
=========================================

Function pointer = variable that stores a function's address.

Used for:
- Callbacks
- Strategy selection
- Dynamic behavior
- Clean switch-like logic

All functions stored must match the same signature.
*/
```


### Variable argument
```c
#include <stdio.h>
#include <stdarg.h>

/*
=========================================
VARIABLE ARGUMENT FUNCTIONS (TL;DR)
=========================================

Used when number of arguments is unknown at compile time.
Example: printf(), scanf()

Required header:
    #include <stdarg.h>

Macros:
    va_list  → holds argument list
    va_start → initialize list
    va_arg   → get next argument
    va_end   → cleanup

Rules:
1) Must have at least ONE fixed parameter.
2) Use ... after fixed parameter.
3) Usually pass count of arguments.
*/

int sum(int count, ...) {
    va_list args;
    int total = 0;

    va_start(args, count);   // start reading after 'count'

    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);  // read next int
    }

    va_end(args);  // cleanup

    return total;
}

int main() {
    printf("Sum = %d\n", sum(4, 2, 3, 4, 5)); // 14
    printf("Sum = %d\n", sum(2, 5, 10));      // 15
    return 0;
}

/*
KEY IDEA:
- count tells how many extra arguments follow.
- Compiler does NOT type-check variable arguments.
- You must know the types and order manually.
*/
```


```c
#include <stdio.h>
#include <stdarg.h>

/*
=========================================
VARIABLE ARGUMENT FUNCTION — FIND MAX
=========================================

max(int num, ...)

- num → number of arguments that follow
- ... → variable arguments
- Uses <stdarg.h> macros:
    va_list
    va_start
    va_arg
    va_end
*/

int max(int num, ...) {
    va_list valist;
    int max_val;

    // Initialize argument list (start after 'num')
    va_start(valist, num);

    // First value becomes initial maximum
    max_val = va_arg(valist, int);

    // Compare remaining values
    for (int i = 1; i < num; i++) {
        int value = va_arg(valist, int);
        if (value > max_val) {
            max_val = value;
        }
    }

    // Cleanup
    va_end(valist);

    return max_val;
}

int main() {
    printf("Max of 2, 3, 4, 5 = %d\n", max(4, 2, 3, 4, 5));
    printf("Max of 5, 10, 15, 20, 25 = %d\n",
           max(5, 5, 10, 15, 20, 25));
    return 0;
}

/*
OUTPUT:
Max of 2, 3, 4, 5 = 5
Max of 5, 10, 15, 20, 25 = 25

IMPORTANT NOTES:
- You must pass the correct count.
- Compiler does NOT type-check variable arguments.
- Types must match what va_arg expects.
*/
```


### String manipulation
```c
#include <stdio.h>
#include <string.h>

/*
=========================================
STRING MANIPULATION (<string.h>) TL;DR
=========================================

Common functions:

strcat(dest, src)
    → Appends src to end of dest
    → dest must have enough space

strcpy(dest, src)
    → Copies src into dest
    → Overwrites dest

strlen(str)
    → Returns length of string
    → Does NOT count '\0'
*/

int main() {

    char str1[20] = "Hello";
    char str2[20] = "World";

    // Concatenate (append)
    strcat(str1, str2);
    printf("%s\n", str1);  // HelloWorld

    char str3[20];

    // Copy string
    strcpy(str3, str1);
    printf("%s\n", str3);  // HelloWorld

    // Length of string
    int len = strlen(str1);
    printf("Length: %d\n", len);  // 10

    return 0;
}

/*
IMPORTANT:
- Always ensure destination array is large enough.
- Strings in C are null-terminated ('\0').
- strlen counts characters BEFORE '\0'.
*/
```


### Math function
```c
#include <stdio.h>
#include <math.h>

/*
=========================================
MATH FUNCTIONS (<math.h>) TL;DR
=========================================

Common functions:

sqrt(x)
    → Square root of x

pow(base, exponent)
    → base raised to exponent

sin(x)
    → Sine of x (x must be in RADIANS)

NOTE:
When compiling, you may need:
    gcc file.c -lm
*/

int main() {

    double result;

    // Square root
    result = sqrt(16.0);
    printf("sqrt(16) = %.2f\n", result);  // 4.00

    // Power
    result = pow(2.0, 8.0);
    printf("2^8 = %.2f\n", result);       // 256.00

    // Sine (pi/2 radians ≈ 1.5708)
    result = sin(3.14159 / 2);
    printf("sin(pi/2) = %.2f\n", result); // 1.00

    return 0;
}

/*
IMPORTANT:
- All trig functions use radians, NOT degrees.
- Use double for better precision.
*/
```


### CHARACTER FUNCTIONS 
```c
#include <stdio.h>
#include <ctype.h>

/*
=========================================
CHARACTER FUNCTIONS (<ctype.h>) TL;DR
=========================================

Common functions:

isalpha(c)
    → True if c is a letter (A–Z or a–z)

isdigit(c)
    → True if c is a digit (0–9)

Other useful ones:
isalnum(c)  → letter or digit
islower(c)  → lowercase letter
isupper(c)  → uppercase letter
toupper(c)  → convert to uppercase
tolower(c)  → convert to lowercase
*/

int main() {

    char ch = 'a';   // fixed single quotes

    if (isalpha(ch)) {
        printf("%c is an alphabetic character\n", ch);
    }

    if (isdigit(ch)) {
        printf("%c is a digit\n", ch);
    }

    return 0;
}

/*
OUTPUT:
a is an alphabetic character

IMPORTANT:
- These functions return non-zero (true) or 0 (false).
- They expect an unsigned char or EOF.
*/
```


### Pointer arithmetic
```c
#include <stdio.h>

/*
=========================================
POINTER ARITHMETIC TL;DR
=========================================

- Pointers store memory addresses of variables.
- You can perform arithmetic to move through memory.
- Operations:
    ptr + n  → move forward n elements
    ptr - n  → move backward n elements
    ptr++    → move to next element
    ptr--    → move to previous element
    ptr1 - ptr2 → difference in number of elements

IMPORTANT:
- Arithmetic is scaled by the size of the data type.
  e.g., if int is 4 bytes, ptr + 1 moves 4 bytes ahead.
*/

int main() {

    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;  // points to arr[0]

    printf("Initial pointer points to: %d\n", *ptr);  // 10

    ptr++; // move to next int
    printf("After ptr++: %d\n", *ptr);  // 20

    ptr += 2; // move 2 ints ahead
    printf("After ptr += 2: %d\n", *ptr);  // 40

    ptr--; // move back by 1 int
    printf("After ptr--: %d\n", *ptr);  // 30

    // Difference between pointers
    int *start = arr;
    int diff = ptr - start;
    printf("Pointer points %d elements away from start\n", diff); // 2

    return 0;
}

/*
TL;DR:
- Pointer arithmetic moves in units of the pointed type size.
- Useful for arrays, dynamic memory, and iterating memory efficiently.
*/
```


### Double pointer
```c
#include <stdio.h>

/*
=========================================
POINTER ARITHMETIC TL;DR
=========================================

- Pointers store memory addresses of variables.
- You can perform arithmetic to move through memory.
- Operations:
    ptr + n  → move forward n elements
    ptr - n  → move backward n elements
    ptr++    → move to next element
    ptr--    → move to previous element
    ptr1 - ptr2 → difference in number of elements

IMPORTANT:
- Arithmetic is scaled by the size of the data type.
  e.g., if int is 4 bytes, ptr + 1 moves 4 bytes ahead.
*/

int main() {

    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;  // points to arr[0]

    printf("Initial pointer points to: %d\n", *ptr);  // 10

    ptr++; // move to next int
    printf("After ptr++: %d\n", *ptr);  // 20

    ptr += 2; // move 2 ints ahead
    printf("After ptr += 2: %d\n", *ptr);  // 40

    ptr--; // move back by 1 int
    printf("After ptr--: %d\n", *ptr);  // 30

    // Difference between pointers
    int *start = arr;
    int diff = ptr - start;
    printf("Pointer points %d elements away from start\n", diff); // 2

    return 0;
}

/*
TL;DR:
- Pointer arithmetic moves in units of the pointed type size.
- Useful for arrays, dynamic memory, and iterating memory efficiently.
*/
```


### Pointer and arrays
```c
#include <stdio.h>

/*
=========================================
POINTERS AND ARRAYS TL;DR
=========================================

- In C, the name of an array is a pointer to its first element.
- Array elements can be accessed using pointers.
- Pointer arithmetic can traverse arrays.
- Useful for iteration, dynamic memory, and passing arrays to functions.
*/

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;  // pointer to first element (arr == &arr[0])

    // Access elements using pointer arithmetic
    printf("First element: %d\n", *ptr);        // 10
    printf("Second element: %d\n", *(ptr + 1)); // 20

    // Iterate through array using pointer
    printf("Array elements: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i)); // same as arr[i]
    }
    printf("\n");

    // Increment pointer to traverse array
    ptr = arr;  // reset pointer
    for (int i = 0; i < 5; i++) {
        printf("%d ", *ptr);  // current element
        ptr++;                // move to next element
    }
    printf("\n");

    return 0;
}

/*
TL;DR:
- arr or &arr[0] points to the first element
- *(arr + i) == arr[i]
- Pointers and arrays are interchangeable in many contexts
- Pointer arithmetic moves by element size
*/
```


### Arrays and dynamic memory
```c
#include <stdio.h>
#include <stdlib.h>

/*
=========================================
ARRAYS VS DYNAMIC MEMORY TL;DR
=========================================

1) Static Arrays:
- Size fixed at compile time
- Allocated on stack
- Syntax: int arr[5];
- Cannot resize during runtime

2) Dynamic Memory:
- Size can be determined at runtime
- Allocated on heap using malloc/calloc/realloc
- Must free memory using free()
- Syntax: int *arr = (int*)malloc(n * sizeof(int));
*/

int main() {

    // Static array
    int arr[5] = {1, 2, 3, 4, 5};
    printf("Static array element 2: %d\n", arr[1]); // 2

    // Dynamic array
    int n = 5;
    int *dynArr = (int*)malloc(n * sizeof(int));
    if (dynArr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Assign values
    for (int i = 0; i < n; i++) {
        dynArr[i] = i * 10;
    }

    // Print dynamic array
    printf("Dynamic array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", dynArr[i]);
    }
    printf("\n");

    // Free allocated memory
    free(dynArr);
    dynArr = NULL; // good practice

    return 0;
}

/*
TL;DR:
- Static array: fixed size, stack memory
- Dynamic memory: runtime size, heap memory, must free
- Use dynamic memory for flexible or large datasets
*/
```


### Pointers and strings
```c
#include <stdio.h>

/*
=========================================
POINTERS AND STRINGS TL;DR
=========================================

1) char strArray[] = "hello world";
   - Creates an array of chars on the stack
   - Writable: you can modify characters, e.g., strArray[0] = 'H';
   - Size = number of characters + 1 for '\0'

2) char *strPointer = "hello world";
   - Creates a pointer to a string literal (usually in read-only memory)
   - Not writable! Modifying *strPointer is undefined behavior
   - Pointer can be reassigned to another string literal
*/

int main() {

    char strArray[] = "hello world";
    char *strPointer = "hello world";

    printf("Array: %s\n", strArray);     // hello world
    printf("Pointer: %s\n", strPointer); // hello world

    // Modify array (allowed)
    strArray[0] = 'H';
    printf("Modified Array: %s\n", strArray); // Hello world

    // Modify pointer string (NOT allowed, may crash)
    // strPointer[0] = 'H'; // ❌ undefined behavior

    // Pointer can point to a different string
    strPointer = "HELLO C";
    printf("Pointer reassigned: %s\n", strPointer); // HELLO C

    return 0;
}

/*
TL;DR:
- Array: memory allocated on stack, writable
- Pointer: points to string literal, may be read-only
- Use array for mutable strings, pointer for literals or dynamic assignment
*/
```


### Pointers with functions
```c
#include <stdio.h>   // Includes standard input/output functions like printf

// Function to swap two integers using pointers
void swap(int *x, int *y) {   // x and y store addresses of two integers
    int temp;                 // Temporary variable to hold a value

    temp = *x;                // Store value at address x into temp
    *x = *y;                  // Copy value at address y into address x
    *y = temp;                // Copy temp value into address y
}

int main() {
    int a = 10, b = 20;       // Declare and initialize two integers

    printf("Before swap: a = %d, b = %d\n", a, b);  
    // Print original values of a and b

    swap(&a, &b);             
    // Pass addresses of a and b to swap function
    // This allows the function to modify original variables

    printf("After swap: a = %d, b = %d\n", a, b);  
    // Print values after swapping

    return 0;                 // End program successfully
}

```


###  Returning pointers from Functions
a pointer from a function using dynamic memory allocation (malloc):
```c
#include <stdio.h>    // For printf
#include <stdlib.h>   // For malloc and free

// Function that allocates memory dynamically and returns a pointer
int* createNumber() {
    int *ptr;                     // Declare pointer
    ptr = (int*)malloc(sizeof(int));  // Allocate memory for one int

    if (ptr == NULL) {            // Check if memory allocation failed
        printf("Memory allocation failed\n");
        return NULL;
    }

    *ptr = 100;                   // Store value in allocated memory
    return ptr;                   // Return pointer (address)
}

int main() {
    int *num = createNumber();    // Receive returned pointer

    if (num != NULL) {
        printf("Value: %d\n", *num);  // Access value using dereferencing
        free(num);               // Free allocated memory (important!)
    }

    return 0;
}
```


### Program Using Function Pointer
```c
#include <stdio.h>

// Function to add two numbers
int add(int a, int b) {
    return a + b;
}

// Function to subtract two numbers
int subtract(int a, int b) {
    return a - b;
}

// Function to multiply two numbers
int multiply(int a, int b) {
    return a * b;
}

// Function that takes another function as parameter (function pointer)
void process(int (*operation)(int, int), int x, int y) {
    printf("Result: %d\n", operation(x, y));  
    // Calls the function passed as argument
}

int main() {
    int a = 10, b = 5;

    process(add, a, b);        // Calls add function
    process(subtract, a, b);   // Calls subtract function
    process(multiply, a, b);   // Calls multiply function

    return 0;
}
```


### malloc() – Memory Allocation
```c
#include <stdio.h>     // For printf
#include <stdlib.h>    // For malloc and free

int main() {

    int *ptr;   // Declare pointer to int

    ptr = (int*)malloc(3 * sizeof(int));  
    // Allocate memory for 3 integers
    // malloc does NOT initialize memory (contains garbage values)

    if (ptr == NULL) {  
        // Check if memory allocation failed
        printf("Memory allocation failed\n");
        return 1;
    }

    ptr[0] = 10;   // Assign value to first element
    ptr[1] = 20;   // Assign value to second element
    ptr[2] = 30;   // Assign value to third element

    printf("%d %d %d\n", ptr[0], ptr[1], ptr[2]);
    // Print stored values

    free(ptr);  
    // Release allocated memory back to system

    return 0;  
}
```

### calloc() – Contiguous Allocation
```c
#include <stdio.h>
#include <stdlib.h>

int main() {

    int *ptr;

    ptr = (int*)calloc(3, sizeof(int));  
    // Allocate memory for 3 integers
    // calloc initializes memory to ZERO

    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("%d %d %d\n", ptr[0], ptr[1], ptr[2]);
    // All values will print 0 0 0

    free(ptr);  
    // Free allocated memory

    return 0;
}
```


### realloc() – Resize Memory
```c
#include <stdio.h>
#include <stdlib.h>

int main() {

    int *ptr;

    ptr = (int*)malloc(2 * sizeof(int));  
    // Allocate memory for 2 integers

    ptr[0] = 10;
    ptr[1] = 20;

    ptr = (int*)realloc(ptr, 4 * sizeof(int));  
    // Resize memory to hold 4 integers
    // Old data (10, 20) is preserved

    ptr[2] = 30;  
    ptr[3] = 40;

    printf("%d %d %d %d\n", ptr[0], ptr[1], ptr[2], ptr[3]);

    free(ptr);  
    // Free memory

    return 0;
}
```

### free() – Deallocate Memory
```c
free(ptr);  
// Releases heap memory
// Prevents memory leak
```

### After freeing
```c
ptr = NULL;  
// Good practice to avoid dangling pointer
```

### Double Free (Dangerous)
```c
free(ptr);  
free(ptr);  // ❌ ERROR: Double free
```
Why dangerous?

Program may crash
Causes undefined behavior
Security risk

### Valgrind
```bash
gcc -g memory_test.c -o memory_test
valgrind --leak-check=full --track-origins=yes ./memory_test
```
-g → Adds debugging symbols (VERY important for Valgrind)
--leak-check=full → Shows detailed memory leak info
--track-origins=yes → Shows where uninitialized values come from

```c
#include <stdio.h>
#include <stdlib.h>

int main() {

    // ==============================
    // 1️⃣ Memory Leak Example
    // ==============================
    int *leak = (int*)malloc(sizeof(int));  
    // Allocates memory but never freed → memory leak

    *leak = 100;  
    printf("Leak value: %d\n", *leak);

    // (No free here → Valgrind will detect leak)


    // ==============================
    // 2️⃣ Use After Free
    // ==============================
    int *useAfterFree = (int*)malloc(sizeof(int));
    *useAfterFree = 200;

    free(useAfterFree);  
    // Memory freed

    // printf("%d\n", *useAfterFree);  
    // ❌ Uncomment to test use-after-free error


    // ==============================
    // 3️⃣ Double Free
    // ==============================
    int *doubleFree = (int*)malloc(sizeof(int));
    *doubleFree = 300;

    free(doubleFree);
    // free(doubleFree);  
    // ❌ Uncomment to test double free error


    // ==============================
    // 4️⃣ Uninitialized Memory
    // ==============================
    int *uninit = (int*)malloc(sizeof(int));
    // Memory allocated but NOT initialized

    // printf("%d\n", *uninit);  
    // ❌ Uncomment to test uninitialized value error

    free(uninit);


    // ==============================
    // 5️⃣ Correct Usage Example
    // ==============================
    int *correct = (int*)malloc(sizeof(int));
    if (correct == NULL) {
        return 1;  // Check allocation
    }

    *correct = 500;
    printf("Correct value: %d\n", *correct);

    free(correct);     // Properly freed
    correct = NULL;    // Prevent dangling pointer

    return 0;
}

```


### simple correct example showing how to set a pointer to NULL after free() to avoid dangling pointers and double free errors:
```c
#include <stdio.h>
#include <stdlib.h>

int main() {

    int *ptr = (int*)malloc(sizeof(int));  
    // Allocate memory for one integer

    if (ptr == NULL) {  
        // Always check if malloc failed
        printf("Memory allocation failed\n");
        return 1;
    }

    *ptr = 42;  
    // Store value in allocated memory

    printf("Value before free: %d\n", *ptr);

    free(ptr);  
    // Free the allocated memory

    ptr = NULL;  
    // VERY IMPORTANT:
    // Set pointer to NULL to avoid dangling pointer
    // Now ptr does not point to freed memory

    // Safe check before using pointer
    if (ptr != NULL) {
        printf("%d\n", *ptr);
    } else {
        printf("Pointer is NULL, cannot access memory.\n");
    }

    return 0;
}
```


### Pointers to pointers
```c
#include <stdio.h>

int main() {

    int x = 10;        // Normal integer variable
    int *p = &x;       // Pointer to int (stores address of x)
    int **pp = &p;     // Pointer to pointer (stores address of p)

    printf("Value of x: %d\n", x);        // 10
    printf("Using p: %d\n", *p);          // 10 (dereference once)
    printf("Using pp: %d\n", **pp);       // 10 (dereference twice)

    return 0;
}
```
x  = 10
p  → address of x
pp → address of p


### Modifying Value Using Pointer to Pointer
```c
#include <stdio.h>

int main() {

    int x = 5;
    int *p = &x;
    int **pp = &p;

    **pp = 50;   // Changes value of x

    printf("x = %d\n", x);   // 50

    return 0;
}
```

### Pointers to dynamic memory
```c
#include <stdio.h>
#include <stdlib.h>

int main() {

    int *ptr = (int*)malloc(sizeof(int));  
    // Allocate memory for one integer

    int **pptr = &ptr;  
    // Pointer to pointer

    if (ptr == NULL) {
        return 1;
    }

    **pptr = 100;  
    // Assign value using double pointer

    printf("Value: %d\n", *ptr);  // 100

    free(ptr);
    ptr = NULL;

    return 0;
}
```


#### Arrays and strings
```c
/*
===========================================================
            ARRAYS AND STRINGS IN C – FULL NOTES
===========================================================

----------------------------
1️⃣ WHAT IS AN ARRAY?
----------------------------
• An array is a collection of elements of SAME data type
• Stored in contiguous memory locations
• Accessed using index (starts from 0)

Syntax:
    data_type array_name[size];

Example:
    int arr[5];   // array of 5 integers

Memory:
    arr[0] arr[1] arr[2] arr[3] arr[4]

-----------------------------------------------------------
2️⃣ ARRAY DECLARATION & INITIALIZATION
-----------------------------------------------------------

int a[5];                    // Declaration
int b[5] = {1,2,3,4,5};      // Initialization
int c[] = {10,20,30};        // Size auto-detected
int d[5] = {1,2};            // Remaining elements become 0

-----------------------------------------------------------
3️⃣ ACCESSING ARRAY ELEMENTS
-----------------------------------------------------------

a[0] = 10;         // Assign value
printf("%d", a[0]); // Access value

Index always starts from 0
Last index = size - 1

-----------------------------------------------------------
4️⃣ ARRAY MEMORY CONCEPT
-----------------------------------------------------------

arr[i]  ==  *(arr + i)

Array name represents base address
Example:
    int arr[3] = {10,20,30};

    arr      → address of arr[0]
    *arr     → 10
    *(arr+1) → 20

-----------------------------------------------------------
5️⃣ TRAVERSING AN ARRAY
-----------------------------------------------------------

for(int i=0; i<5; i++)
{
    printf("%d ", arr[i]);
}

-----------------------------------------------------------
6️⃣ TYPES OF ARRAYS
-----------------------------------------------------------

1D Array:
    int arr[5];

2D Array:
    int matrix[2][3];

3D Array:
    int cube[2][2][2];

-----------------------------------------------------------
7️⃣ 2D ARRAY (MATRIX)
-----------------------------------------------------------

int mat[2][3] = {
    {1,2,3},
    {4,5,6}
};

Access:
    mat[0][1]  → 2

Memory is stored row-wise (row-major order)

-----------------------------------------------------------
8️⃣ PASSING ARRAY TO FUNCTION
-----------------------------------------------------------

void display(int arr[], int size)
{
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
}

NOTE:
Array decays into pointer when passed to function.

-----------------------------------------------------------
9️⃣ CHARACTER ARRAYS
-----------------------------------------------------------

char name[5] = {'J','o','h','n','\0'};

'\0' → Null character (string terminator)

-----------------------------------------------------------
🔟 WHAT IS A STRING?
-----------------------------------------------------------

• A string is a character array ending with '\0'

Example:
    char str[] = "Hello";

Memory:
    H e l l o \0

-----------------------------------------------------------
1️⃣1️⃣ STRING DECLARATION METHODS
-----------------------------------------------------------

char str1[] = "Hello";
char str2[10] = "Hi";
char str3[] = {'H','i','\0'};

-----------------------------------------------------------
1️⃣2️⃣ STRING INPUT / OUTPUT
-----------------------------------------------------------

scanf("%s", str);      // stops at space
gets(str);             // unsafe (deprecated)
fgets(str, size, stdin); // safe

printf("%s", str);

-----------------------------------------------------------
1️⃣3️⃣ COMMON STRING FUNCTIONS (<string.h>)
-----------------------------------------------------------

strlen(str);      → length (excluding '\0')
strcpy(a,b);      → copy string
strcat(a,b);      → concatenate
strcmp(a,b);      → compare
strchr(str,'a');  → find character
strstr(a,b);      → find substring

-----------------------------------------------------------
1️⃣4️⃣ STRING VS CHARACTER ARRAY
-----------------------------------------------------------

char str[] = "Hello";  // modifiable
char *str = "Hello";   // points to string literal (read-only)

-----------------------------------------------------------
1️⃣5️⃣ ARRAY OF STRINGS
-----------------------------------------------------------

char names[3][10] = {
    "John",
    "Alice",
    "Bob"
};

Access:
    names[0] → "John"

-----------------------------------------------------------
1️⃣6️⃣ POINTERS AND ARRAYS
-----------------------------------------------------------

int arr[3] = {1,2,3};
int *p = arr;

p[0] == arr[0]
*(p+1) == arr[1]

-----------------------------------------------------------
1️⃣7️⃣ DYNAMIC ARRAY
-----------------------------------------------------------

int *arr;
arr = (int*)malloc(5 * sizeof(int));

Access:
    arr[i]

free(arr);

-----------------------------------------------------------
1️⃣8️⃣ IMPORTANT DIFFERENCES
-----------------------------------------------------------

Array:
    int arr[5];
    • Fixed size
    • Stored in stack

Dynamic Array:
    int *arr = malloc(...)
    • Size decided at runtime
    • Stored in heap

-----------------------------------------------------------
1️⃣9️⃣ COMMON ERRORS
-----------------------------------------------------------

❌ Accessing out-of-bound index
❌ Forgetting '\0' in string
❌ Using gets()
❌ Not freeing dynamic memory
❌ Modifying string literal

-----------------------------------------------------------
2️⃣0️⃣ VIVA QUESTIONS
-----------------------------------------------------------

Q: What is array?
A: Collection of same data type stored in contiguous memory.

Q: Why string ends with '\0'?
A: To mark end of string.

Q: Difference between char str[] and char *str?
A: First is array, second is pointer to string literal.

Q: What is array decay?
A: When passed to function, array becomes pointer.

-----------------------------------------------------------
END OF ARRAYS AND STRINGS NOTES
-----------------------------------------------------------
*/
```


### Passing 1D Array to Function (Print + Sum)
```c
#include <stdio.h>

// Function to print array elements
void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to calculate sum of array
int sumArray(int arr[], int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printArray(numbers, size);

    int total = sumArray(numbers, size);
    printf("Sum = %d\n", total);

    return 0;
}
```


### Automatic Null Terminator
```c
#include <stdio.h>

int main() {

    char str[] = "Hello";  
    // Compiler stores: H e l l o \0

    printf("%s\n", str);  
    // %s prints characters until it finds '\0'

    return 0;
}
```


### fgets
```c
#include <stdio.h>

int main() {
    char name[20];   // Array to store input

    printf("Enter your name: ");

    fgets(name, sizeof(name), stdin);
    // Reads at most 19 characters, last character is '\0'
    // Includes spaces and stops at newline or EOF

    printf("Hello, %s", name);

    return 0;
}
```


### Removing new line
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[50];

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    // Remove trailing newline if present
    str[strcspn(str, "\n")] = '\0';

    printf("You entered: %s\n", str);

    return 0;
}
```


### read from and write to files
```c
#include <stdio.h>   // Include standard I/O library for file operations

int main() {

    FILE *fp;        // Declare a file pointer
    char str[100] = "Example string.";  // String to write to file
    char buffer[100];  // Buffer to read data from file

    // ============================
    // 1️⃣ Open a file for writing
    // ============================
    fp = fopen("example.txt", "w");  // Open file in write mode ("w")
    if(fp == NULL) {                 // Check if file was opened successfully
        printf("Error opening file for writing.\n");
        return 1;
    }

    fprintf(fp, "%s\n", str);        // Write string to file
    fclose(fp);                      // Close the file to save changes

    // ============================
    // 2️⃣ Open the same file for reading
    // ============================
    fp = fopen("example.txt", "r");  // Open file in read mode ("r")
    if(fp == NULL) {                 // Check if file opened successfully
        printf("Error opening file for reading.\n");
        return 1;
    }

    fgets(buffer, sizeof(buffer), fp);  // Read a line from file into buffer
    printf("Read from file: %s", buffer); // Print the string read from file

    fclose(fp);                       // Close the file after reading

    return 0;
}
```

### fgets, strchr, fprintf, getchar, sizeof, and strcspn

```c
#include <stdio.h>      // For printf, fprintf, fgets, getchar
#include <string.h>     // For strchr, strcspn

int main() {
    char str[100];      // Buffer to store input string
    char *ptr;          // Pointer used with strchr
    FILE *fp;           // File pointer for writing to a file

    // =============================
    // 1️⃣ fgets - Read string safely
    // =============================
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);  
    // Reads at most sizeof(str)-1 characters from stdin
    // Includes spaces and the newline character '\n' if there's space

    // =============================
    // 2️⃣ Remove trailing newline using strcspn
    // =============================
    str[strcspn(str, "\n")] = '\0';  
    // strcspn returns index of first '\n' (or end)
    // Replacing '\n' with '\0' makes string properly terminated

    printf("You entered: %s\n", str);

    // =============================
    // 3️⃣ strchr - Find a character in string
    // =============================
    ptr = strchr(str, 'a');  
    // Returns pointer to first occurrence of 'a', or NULL if not found
    if(ptr != NULL) {
        printf("First 'a' found at position: %ld\n", ptr - str);
        // Pointer arithmetic: position = ptr - str
    } else {
        printf("'a' not found in string.\n");
    }

    // =============================
    // 4️⃣ sizeof - Size of array
    // =============================
    printf("Size of str array: %lu bytes\n", sizeof(str));
    // sizeof(str) gives total memory allocated for the array, here 100 bytes

    // =============================
    // 5️⃣ getchar - Read single character
    // =============================
    char ch;
    printf("Enter a single character: ");
    ch = getchar();  
    // Reads next character from stdin
    printf("You entered: %c\n", ch);

    // =============================
    // 6️⃣ fprintf - Write to file
    // =============================
    fp = fopen("output.txt", "w");  
    if(fp == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    fprintf(fp, "Your string: %s\n", str);  
    // Writes formatted string to the file
    fprintf(fp, "Single character: %c\n", ch);

    fclose(fp);  
    // Always close the file to save data

    return 0;
}

```

### strcmp, strcat, strcpy,
```c
#include <stdio.h>
#include <string.h>  // Required for string functions

int main() {
    char str1[50] = "Hello";      // First string
    char str2[50] = "World";      // Second string
    char str3[50];                // Empty string for copy

    // =============================
    // 1️⃣ strlen - Find length of string
    // =============================
    printf("Length of str1: %lu\n", strlen(str1));
    // strlen counts characters up to '\0' (null terminator)

    // =============================
    // 2️⃣ strcpy - Copy string
    // =============================
    strcpy(str3, str1);  
    // Copies contents of str1 into str3
    printf("After strcpy, str3 = %s\n", str3);

    // =============================
    // 3️⃣ strcat - Concatenate strings
    // =============================
    strcat(str1, " ");      // Add a space
    strcat(str1, str2);     // Append str2 to str1
    printf("After strcat, str1 = %s\n", str1);

    // =============================
    // 4️⃣ strcmp - Compare strings
    // =============================
    int cmp1 = strcmp("Hello", "Hello");  
    int cmp2 = strcmp("Apple", "Banana");  

    printf("strcmp('Hello','Hello') = %d\n", cmp1);  
    // 0 → strings are equal

    printf("strcmp('Apple','Banana') = %d\n", cmp2);  
    // Negative → 'Apple' < 'Banana' (lexicographically)

    // =============================
    // 5️⃣ strchr - Find character
    // =============================
    char *ptr = strchr(str1, 'W');  
    if(ptr != NULL) {
        printf("'W' found at position: %ld\n", ptr - str1);
    } else {
        printf("'W' not found\n");
    }

    // =============================
    // 6️⃣ strstr - Find substring
    // =============================
    ptr = strstr(str1, "World");  
    if(ptr != NULL) {
        printf("Substring 'World' found at position: %ld\n", ptr - str1);
    } else {
        printf("Substring not found\n");
    }

    return 0;
}
```


### searching
```c
#include <stdio.h>
#include <string.h>  // Required for strchr

int main() {
    char str[100] = "Hello World";  // String to search in
    char ch;                         // Character to search for
    char *ptr;                       

    // Ask user for character to search
    printf("Enter a character to search: ");
    scanf("%c", &ch);

    // strchr searches for the first occurrence of ch in str
    ptr = strchr(str, ch);

    if(ptr != NULL) {
        // Pointer arithmetic to get position
        printf("Character '%c' found at position: %ld\n", ch, ptr - str);
    } else {
        printf("Character '%c' not found in string.\n", ch);
    }

    return 0;
}
```


### strlen and strtok
```c
#include <stdio.h>
#include <string.h>  // For strlen and strtok

int main() {
    char str[100] = "C programming is fun";  // Original string
    char *token;                             // Pointer to store each token

    // =============================
    // 1️⃣ strlen - Find length of string
    // =============================
    size_t len = strlen(str);  
    // strlen returns the number of characters in the string (excluding '\0')
    printf("Length of string: %lu\n", len);

    // =============================
    // 2️⃣ strtok - Split string into tokens
    // =============================
    // strtok modifies the original string
    // Split by space " "
    token = strtok(str, " ");  

    while(token != NULL) {
        printf("Token: %s\n", token);  
        token = strtok(NULL, " ");  
        // Continue getting next token
        // Pass NULL in subsequent calls
    }

    return 0;
}
```

### character arrays, pointers, and pointer arithmetic with strings
```c
#include <stdio.h>

int main() {
    // ---------------------------
    // 1️⃣ Character array declaration
    // ---------------------------
    char str[10];                  // Declares array of 10 chars (uninitialized)

    // ---------------------------
    // 2️⃣ Initialize with braces
    // ---------------------------
    char str2[10] = {'H','e','l','l','o','\0'};  
    // str2 contains "Hello" with null terminator

    // ---------------------------
    // 3️⃣ Initialize using string literal
    // ---------------------------
    char str3[] = "Hello";  
    // Size automatically determined (6: 5 chars + '\0')

    printf("str2 = %s\n", str2);
    printf("str3 = %s\n", str3);

    // ---------------------------
    // 4️⃣ Pointer to character array
    // ---------------------------
    char *p = str3;  // Pointer p points to first element of str3

    // ---------------------------
    // 5️⃣ Modify array via pointer
    // ---------------------------
    *(p + 1) = 'a';  // Change second character: 'e' → 'a'
    printf("After modification, str3 = %s\n", str3); // Hallo

    // ---------------------------
    // 6️⃣ Pointer arithmetic iteration
    // ---------------------------
    printf("Iterating through str3 using pointer: ");
    p = str3;                // Reset pointer to start
    while(*p != '\0') {      // Loop until null terminator
        printf("%c", *p);    // Print current character
        p++;                 // Move to next character
    }
    printf("\n");

    return 0;
}
```


### Character Array
```c
#include <stdio.h>

int main() {
    char arr[6] = "Hello";  // Character array, size 6 (5 letters + '\0')
    
    printf("Array: %s\n", arr);
    arr[0] = 'h';           // You can modify array elements
    printf("Modified array: %s\n", arr);

    return 0;
}
```
Key Points:

Stored in stack memory
Size fixed at compile-time (if declared with size)
Can be modified element by element
arr acts as pointer to first element (&arr[0])
Null terminator '\0' marks end of string


### Character Pointer
```c
#include <stdio.h>

int main() {
    char *p = "Hello";   // Pointer to string literal
    
    printf("Pointer: %s\n", p);
    // p[0] = 'h';       // ❌ Error: modifying string literal is undefined

    return 0;
}
```

Key Points:

Points to string literal in read-only memory
Cannot modify contents (undefined behavior if you try)
Pointer can be reassigned to another string: p = "World";
Useful for passing around strings without copying



### Character Pointers vs. Character Arrays
It is important to differentiate between character pointers and character arrays. A character pointer
can be reassigned to point to different strings during runtime, while an array’s name always refers
to the same memory location.
```c
char *p1 = "Hello";
char p2[] = "Hello";
p1 = "World"; // valid
p2 = "World"; // invalid
```

### Array bound violation
```c
#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    // Accessing within bounds (OK)
    printf("arr[2] = %d\n", arr[2]);

    // Accessing out of bounds (undefined behavior)
    printf("arr[5] = %d\n", arr[5]);  // ❌ arr[5] does not exist
    printf("arr[10] = %d\n", arr[10]); // ❌ Definitely out of bounds

    return 0;
}
```


### Example with Character Array (String)
```c
#include <stdio.h>

int main() {
    char str[5] = "Hello";  // 'H','e','l','l','o','\0' → array too small

    printf("%s\n", str);   // ❌ Undefined behavior: array too small
    return 0;
}
```

### Null termination in strings
What is Null-Termination?

In C, strings are arrays of characters.
A string is terminated by a special character '\0' (null character).
'\0' has ASCII value 0 and signals the end of the string.
Without '\0', string functions like printf("%s"), strlen(), or strcpy() will read past the intended end, causing undefined behavior.

```c
#include <stdio.h>

int main() {
    char str[] = "Hello"; // Compiler automatically adds '\0' at the end
    // Memory: ['H','e','l','l','o','\0']

    printf("String: %s\n", str);           // Prints "Hello"
    printf("Length using strlen: %lu\n", strlen(str)); // 5 (excluding '\0')

    return 0;
}
```


### Manual null termination
```c
#include <stdio.h>

int main() {
    char str[6] = {'H', 'e', 'l', 'l', 'o', '\0'};  
    // You must explicitly add '\0' if initializing manually

    printf("%s\n", str); // Prints "Hello"

    return 0;
}
```

### Missing Null-Termination (Dangerous)
```c

#include <stdio.h>

int main() {
    char str[5] = {'H', 'e', 'l', 'l', 'o'};  
    // No '\0' → array too small for string literal

    printf("%s\n", str); // Undefined behavior: may print garbage or crash

    return 0;
}
```


### What is Buffer Overflow?

A buffer overflow happens when a program writes more data into a buffer (array) than it can hold.

In C, arrays have fixed size, and C does not check bounds at runtime.

Consequences:

Overwriting adjacent memory

Program crashes

Security vulnerabilities / exploits

Buffer overflow with character array
```c
#include <stdio.h>
#include <string.h>

int main() {
    char buffer[5];  // Can hold 4 characters + '\0'

    // User tries to input a longer string
    strcpy(buffer, "HelloWorld");  // ❌ Overflow: "HelloWorld" is 11 bytes

    printf("Buffer contains: %s\n", buffer); // Undefined behavior

    return 0;
}
```

### Safe Version Using fgets
```c
#include <stdio.h>

int main() {
    char buffer[5];  

    printf("Enter a string (max 4 chars): ");
    fgets(buffer, sizeof(buffer), stdin);  
    // fgets reads at most sizeof(buffer)-1 characters
    // Automatically adds '\0' at the end

    printf("You entered: %s\n", buffer);

    return 0;
}
```

Notes:

fgets prevents buffer overflow by limiting input size
Always check input size before writing to arrays

### Example with Integer Array Overflow
```c
#include <stdio.h>

int main() {
    int arr[3] = {1, 2, 3};

    arr[3] = 10;   // ❌ Out-of-bounds write
    arr[4] = 20;   // ❌ Another overflow

    for(int i = 0; i < 3; i++)
        printf("%d ", arr[i]); // May still print 1 2 3, but memory corrupted

    return 0;
}
```

### out-of-bounds access, uninitialized arrays, unsafe string handling, and pointer mistakes, with safe alternatives
```c
#include <stdio.h>

int main() {
    // =============================
    // 1️⃣ Out-of-Bounds Array Access
    // =============================
    int arr[5] = {1, 2, 3, 4, 5};

    printf("Incorrect loop (out-of-bounds):\n");
    for(int i = 0; i <= 5; i++) {  // ❌ Iterates 0..5 (arr[5] is out-of-bounds)
        printf("%d ", arr[i]);      // Undefined behavior on last iteration
    }
    printf("\n");

    printf("Correct loop:\n");
    for(int i = 0; i < 5; i++) {   // ✅ Iterates 0..4
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // =============================
    // 2️⃣ Uninitialized Arrays
    // =============================
    int arr2[5];                   // ❌ Not initialized
    printf("Uninitialized array:\n");
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr2[i]);    // May print garbage values
    }
    printf("\n");

    int arr3[5] = {0};             // ✅ Initialized to 0
    printf("Initialized array:\n");
    for(int i = 0; i < 5; i++) {
        printf("%d ", arr3[i]);    // Prints 0 0 0 0 0
    }
    printf("\n\n");

    // =============================
    // 3️⃣ Unsafe string input (gets)
    // =============================
    char str1[10];
    // gets(str1);                  // ❌ Avoid: no bounds checking

    // =============================
    // 4️⃣ Safe string input (fgets)
    // =============================
    printf("Enter a string (max 9 chars): ");
    fgets(str1, sizeof(str1), stdin);  
    // fgets reads at most sizeof(str1)-1 characters
    // Includes newline if present
    str1[strcspn(str1, "\n")] = '\0'; // Remove trailing newline

    printf("You entered: %s\n\n", str1);

    // =============================
    // 5️⃣ Pointer usage with arrays
    // =============================
    char *p = str1;               // Pointer to first element of array
    printf("Iterating using pointer:\n");
    while(*p != '\0') {           // Loop until null terminator
        printf("%c ", *p);        // Print each character
        p++;
    }
    printf("\n");

    return 0;
}
```


### structure
```c
#include <stdio.h>
#include <string.h>

// =============================
// 1️⃣ Traditional Structure
// =============================
struct Point {
    int x;
    int y;
};  // Must use 'struct Point' to declare variables

int main() {
    struct Point p1, p2;        // Declaring traditional structure variables
    p1.x = 10; p1.y = 20;
    p2.x = 30; p2.y = 40;

    printf("Traditional struct:\n");
    printf("p1 = (%d, %d)\n", p1.x, p1.y);
    printf("p2 = (%d, %d)\n\n", p2.x, p2.y);

    // =============================
    // 2️⃣ Typedef with Structure
    // =============================
    typedef struct {
        int x;
        int y;
    } Point;                     // 'Point' is now a type alias

    Point p3, p4;                // Can use 'Point' directly
    p3.x = 50; p3.y = 60;
    p4.x = 70; p4.y = 80;

    printf("Typedef struct:\n");
    printf("p3 = (%d, %d)\n", p3.x, p3.y);
    printf("p4 = (%d, %d)\n\n", p4.x, p4.y);

    // =============================
    // 3️⃣ Nested Structures
    // =============================
    struct Date {
        int day;
        int month;
        int year;
    };

    struct Employee {
        char name[50];
        int id;
        struct Date dateOfJoining;  // Nested structure
    };

    struct Employee emp;
    strcpy(emp.name, "Alice");
    emp.id = 101;
    emp.dateOfJoining.day = 15;
    emp.dateOfJoining.month = 2;
    emp.dateOfJoining.year = 2026;

    printf("Nested struct:\n");
    printf("Employee: %s, ID: %d, Joining Date: %02d-%02d-%04d\n",
        emp.name, emp.id,
        emp.dateOfJoining.day,
        emp.dateOfJoining.month,
        emp.dateOfJoining.year);

    return 0;
}
```

### accessing structure members using dot (.) and arrow (->) operators
```c
#include <stdio.h>

struct Point {
    int x;
    int y;
};

int main() {
    // =============================
    // 1️⃣ Accessing members with dot operator
    // =============================
    struct Point p;   // Declare structure variable

    p.x = 10;         // Set x using dot operator
    p.y = 20;         // Set y using dot operator

    printf("Point coordinates (dot): (%d, %d)\n", p.x, p.y); // Access members

    // =============================
    // 2️⃣ Accessing members with arrow operator
    // =============================
    struct Point *ptr; // Declare pointer to structure
    ptr = &p;          // Point to existing structure variable

    ptr->x = 30;       // Set x using arrow operator
    ptr->y = 40;       // Set y using arrow operator

    printf("Point coordinates (arrow): (%d, %d)\n", ptr->x, ptr->y); // Access via pointer

    return 0;
}
```

#### structure member access, pointer access (->), nested structures, and looping through arrays of structures,
```c
#include <stdio.h>

// =============================
// Structure Definitions
// =============================
struct Point {
    int x;
    int y;
};

struct Circle {
    struct Point center;  // Nested structure
    float radius;
};

int main() {
    // =============================
    // 1️⃣ Pointer access to structure
    // =============================
    struct Point p;
    struct Point *ptr = &p;

    ptr->x = 30;  // Equivalent to (*ptr).x
    ptr->y = 40;  // Equivalent to (*ptr).y

    printf("Updated point coordinates: (%d, %d)\n", ptr->x, ptr->y);
    // Output: Updated point coordinates: (30, 40)

    // =============================
    // 2️⃣ Accessing nested structure members
    // =============================
    struct Circle c;

    // Using dot operator for nested members
    c.center.x = 15;
    c.center.y = 25;
    c.radius = 5.0;

    printf("Circle center: (%d, %d), Radius: %.1f\n",
           c.center.x, c.center.y, c.radius);
    // Output: Circle center: (15, 25), Radius: 5.0

    // Using pointer to nested structure
    struct Circle *c_ptr = &c;

    c_ptr->center.x = 35;  // Arrow operator for pointer access
    c_ptr->center.y = 45;
    c_ptr->radius = 10.0;

    printf("Updated circle center: (%d, %d), Radius: %.1f\n",
           c_ptr->center.x, c_ptr->center.y, c_ptr->radius);
    // Output: Updated circle center: (35, 45), Radius: 10.0

    // =============================
    // 3️⃣ Looping through array of structures
    // =============================
    struct Point points[3];  // Array of 3 Points

    // Initialize using loop
    for(int i = 0; i < 3; i++) {
        points[i].x = i * 10;
        points[i].y = i * 20;
    }

    // Print all points
    printf("Points array:\n");
    for(int i = 0; i < 3; i++) {
        printf("Point %d: (%d, %d)\n", i, points[i].x, points[i].y);
    }

    return 0;
}
```


### structure initialization, designated initializers, partial initialization, and nested structures
```c
#include <stdio.h>
#include <string.h>

// =============================
// Structure Definitions
// =============================
struct Book {
    char title[50];
    char author[50];
    int pages;
    float price;
};

struct Publication {
    struct Book bookInfo; // Nested structure
    int year;
};

int main() {
    // =============================
    // 1️⃣ Initialization at Declaration
    // =============================
    struct Book myBook1 = {"The C Programming Language", "Brian W. Kernighan", 272, 35.50};

    printf("Book 1: %s by %s, Pages: %d, Price: $%.2f\n",
           myBook1.title, myBook1.author, myBook1.pages, myBook1.price);

    // =============================
    // 2️⃣ Designated Initializers (C99)
    // =============================
    struct Book myBook2 = {.author = "Dennis Ritchie",
                           .pages = 300,
                           .title = "C Programming",
                           .price = 29.99};

    printf("Book 2: %s by %s, Pages: %d, Price: $%.2f\n",
           myBook2.title, myBook2.author, myBook2.pages, myBook2.price);

    // =============================
    // 3️⃣ Partially Initialized Structure
    // =============================
    struct Book myBook3 = {.title = "Learn C Quickly"}; // Other members auto-zeroed

    printf("Book 3: %s by %s, Pages: %d, Price: $%.2f\n",
           myBook3.title, myBook3.author, myBook3.pages, myBook3.price);
    // author: "", pages: 0, price: 0.0

    // =============================
    // 4️⃣ Nested Structure Initialization
    // =============================
    struct Publication pub = {{ "Effective C", "Robert C. Seacord", 400, 49.99 }, 2022};
    // Outer braces: Publication, Inner braces: Book

    printf("Publication: %s by %s, Pages: %d, Price: $%.2f, Year: %d\n",
           pub.bookInfo.title, pub.bookInfo.author,
           pub.bookInfo.pages, pub.bookInfo.price,
           pub.year);

    return 0;
}
```


### Arrays of structure
```c
#include <stdio.h>
#include <string.h>

// =============================
// Structure Definition
// =============================
struct Book {
    char title[50];
    char author[50];
    int pages;
    float price;
};

int main() {
    // =============================
    // 1️⃣ Array of Structures
    // =============================
    struct Book library[3];  // Array to store 3 books

    // =============================
    // 2️⃣ Initialize members individually
    // =============================
    strcpy(library[0].title, "The C Programming Language");
    strcpy(library[0].author, "Brian W. Kernighan");
    library[0].pages = 272;
    library[0].price = 35.50;

    strcpy(library[1].title, "C Programming: A Modern Approach");
    strcpy(library[1].author, "K. N. King");
    library[1].pages = 960;
    library[1].price = 50.00;

    strcpy(library[2].title, "Learn C Quickly");
    strcpy(library[2].author, "John Doe");
    library[2].pages = 200;
    library[2].price = 20.00;

    // =============================
    // 3️⃣ Loop through array to print books
    // =============================
    for(int i = 0; i < 3; i++) {
        printf("Book %d: %s by %s, Pages: %d, Price: $%.2f\n",
               i+1,
               library[i].title,
               library[i].author,
               library[i].pages,
               library[i].price);
    }

    // =============================
    // 4️⃣ Optional: Array of structures using initialization at declaration
    // =============================
    struct Book library2[2] = {
        {"Effective C", "Robert C. Seacord", 400, 49.99},
        {"Programming in C", "Stephen G. Kochan", 800, 55.00}
    };

    printf("\nLibrary2:\n");
    for(int i = 0; i < 2; i++) {
        printf("Book %d: %s by %s, Pages: %d, Price: $%.2f\n",
               i+1,
               library2[i].title,
               library2[i].author,
               library2[i].pages,
               library2[i].price);
    }

    return 0;
}
```



### Structure and function
```c
#include <stdio.h>
#include <string.h>

// =============================
// Structure Definition
// =============================
struct Book {
    char title[50];
    char author[50];
    int pages;
    float price;
};

// =============================
// Function 1: Print book details (pass by value)
// =============================
void printBook(struct Book b) {
    printf("Book: %s by %s, Pages: %d, Price: $%.2f\n",
           b.title, b.author, b.pages, b.price);
}

// =============================
// Function 2: Update book price (pass by pointer)
// =============================
void updatePrice(struct Book *b, float newPrice) {
    b->price = newPrice;  // Arrow operator for pointer to structure
}

// =============================
// Function 3: Create and return a Book (return structure)
// =============================
struct Book createBook(const char *title, const char *author, int pages, float price) {
    struct Book b;
    strcpy(b.title, title);
    strcpy(b.author, author);
    b.pages = pages;
    b.price = price;
    return b;  // Returns a copy of the structure
}

int main() {
    // =============================
    // 1️⃣ Declare and initialize a structure
    // =============================
    struct Book myBook = {"The C Programming Language", "Brian W. Kernighan", 272, 35.50};

    // Print using function (pass by value)
    printBook(myBook);

    // =============================
    // 2️⃣ Update price using pointer
    // =============================
    updatePrice(&myBook, 40.00);  // Pass address of structure
    printf("After price update:\n");
    printBook(myBook);

    // =============================
    // 3️⃣ Create a new book using function that returns a structure
    // =============================
    struct Book newBook = createBook("Effective C", "Robert Seacord", 400, 49.99);
    printf("New book created:\n");
    printBook(newBook);

    return 0;
}
```


### pointers to structures
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =============================
// Structure Definition
// =============================
struct Book {
    char title[50];
    char author[50];
    int pages;
    float price;
};

// =============================
// Function: Print book details via pointer
// =============================
void printBook(struct Book *b) {
    // Use arrow operator -> to access members via pointer
    printf("Book: %s by %s, Pages: %d, Price: $%.2f\n",
           b->title, b->author, b->pages, b->price);
}

// =============================
// Function: Update book price via pointer
// =============================
void updatePrice(struct Book *b, float newPrice) {
    b->price = newPrice;  // Modify original structure
}

int main() {
    // =============================
    // 1️⃣ Pointer to existing structure
    // =============================
    struct Book myBook = {"The C Programming Language", "Brian W. Kernighan", 272, 35.50};
    struct Book *ptr = &myBook;  // Pointer to structure

    // Access members via pointer
    printf("Original book:\n");
    printf("Title: %s, Author: %s\n", ptr->title, ptr->author);

    // Update price using pointer
    updatePrice(ptr, 40.00);
    printf("After price update using pointer:\n");
    printBook(ptr);

    // =============================
    // 2️⃣ Dynamic allocation of a structure
    // =============================
    struct Book *dynBook = (struct Book *)malloc(sizeof(struct Book)); // Allocate memory
    if(dynBook == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Initialize members
    strcpy(dynBook->title, "Effective C");
    strcpy(dynBook->author, "Robert C. Seacord");
    dynBook->pages = 400;
    dynBook->price = 49.99;

    printf("Dynamically allocated book:\n");
    printBook(dynBook);

    free(dynBook);  // Free dynamically allocated memory
    dynBook = NULL;  // Avoid dangling pointer

    return 0;
}
```


### Unions
```c
#include <stdio.h>
#include <string.h>

// =============================
// Structure with a Union
// =============================
struct MixedData {
    int id;        // Unique identifier
    char type;     // Stores type info: 'i', 'f', 's'
    union {        // Union can store either int, float, or string
        int i;
        float f;
        char str[20];
    } data;        // Union member named 'data'
};

int main() {
    struct MixedData m;  // Declare a variable of type MixedData

    // =============================
    // 1️⃣ Store an integer in union
    // =============================
    m.id = 1;
    m.type = 'i';        // Indicates the union holds an integer
    m.data.i = 100;      // Access union member 'i'

    printf("ID: %d, Type: %c, Value: %d\n", m.id, m.type, m.data.i);
    // Output: ID: 1, Type: i, Value: 100

    // =============================
    // 2️⃣ Store a float in the same union
    // =============================
    m.type = 'f';        // Now the union holds a float
    m.data.f = 98.76;    // Overwrites previous 'i' value

    printf("ID: %d, Type: %c, Value: %.2f\n", m.id, m.type, m.data.f);
    // Output: ID: 1, Type: f, Value: 98.76

    // =============================
    // 3️⃣ Store a string in the same union
    // =============================
    m.type = 's';        // Now the union holds a string
    strcpy(m.data.str, "Hello");  // Overwrites previous float

    printf("ID: %d, Type: %c, Value: %s\n", m.id, m.type, m.data.str);
    // Output: ID: 1, Type: s, Value: Hello

    return 0;
}
```

### unions for different sensor readings,
```c
#include <stdio.h>

// =============================
// Union Definition
// =============================
union SensorReading {
    int temperature;   // Temperature in integer
    float voltage;     // Voltage in float
    char status;       // Status as a character
};

int main() {
    union SensorReading reading;  // Declare a union variable

    // =============================
    // 1️⃣ Assign integer temperature
    // =============================
    reading.temperature = 25;     // Stores temperature in union
    printf("Temperature: %d°C\n", reading.temperature);
    // Output: Temperature: 25°C

    // =============================
    // 2️⃣ Assign float voltage
    // =============================
    reading.voltage = 3.3;        // Overwrites previous temperature
    printf("Voltage: %.2fV\n", reading.voltage);
    // Output: Voltage: 3.30V

    // =============================
    // 3️⃣ Assign char status
    // =============================
    reading.status = 'A';         // Overwrites previous voltage
    printf("Status: %c\n", reading.status);
    // Output: Status: A

    return 0;
}
```


### compiler errors and type-punning with unions
```c
#include <stdio.h>

union Data {
    int i;
    float f;
};

int main() {
    union Data d;

    // =============================
    // Type-punning: store int, read as float
    // =============================
    d.i = 1065353216;   // integer representation of 1.0f in IEEE 754
    printf("Interpreted as float: %f\n", d.f); // Type-punning

    // =============================
    // ⚠️ Note: Some compilers may warn or optimize unpredictably
    // Strict-aliasing rules in C can cause undefined behavior
    // when accessing a union member as a different type than it was last written.
    // =============================

    return 0;
}
```


### key differences between structures and unions in C
```c
#include <stdio.h>

// =============================
// Structure Example
// =============================
struct ExampleStruct {
    int a;       // 4 bytes
    float b;     // 4 bytes
    char c;      // 1 byte
};

// =============================
// Union Example
// =============================
union ExampleUnion {
    int a;       // 4 bytes
    float b;     // 4 bytes
    char c;      // 1 byte
};

int main() {
    // =============================
    // Structure Memory Allocation
    // =============================
    struct ExampleStruct s;
    printf("Size of structure: %zu bytes\n", sizeof(s));
    // Output might be >= 12 due to alignment (4+4+1 + padding)

    // =============================
    // Union Memory Allocation
    // =============================
    union ExampleUnion u;
    printf("Size of union: %zu bytes\n", sizeof(u));
    // Output will be size of largest member (4 bytes in this case)

    // =============================
    // Member Access
    // =============================
    s.a = 10; s.b = 3.14; s.c = 'A';
    printf("Struct members: a=%d, b=%.2f, c=%c\n", s.a, s.b, s.c);

    u.a = 10;          // Writing to union member a
    printf("Union member a: %d\n", u.a);
    u.b = 3.14;        // Overwrites previous member
    printf("Union member b: %.2f\n", u.b);
    u.c = 'A';         // Overwrites previous member
    printf("Union member c: %c\n", u.c);

    return 0;
}
```


### explanation and example of bit fields in C
```c
#include <stdio.h>

// =============================
// Structure with Bit Fields
// =============================
struct BitFieldExample {
    unsigned int field1 : 3;  // 3 bits → can store 0 to 7
    unsigned int field2 : 5;  // 5 bits → can store 0 to 31
    unsigned int field3 : 2;  // 2 bits → can store 0 to 3
};

int main() {
    struct BitFieldExample bitFieldStruct;

    // =============================
    // Assign values within range
    // =============================
    bitFieldStruct.field1 = 5;   // OK: 3 bits can hold 0-7
    bitFieldStruct.field2 = 31;  // OK: 5 bits can hold 0-31
    bitFieldStruct.field3 = 2;   // OK: 2 bits can hold 0-3

    printf("field1: %u\n", bitFieldStruct.field1);  // Output: 5
    printf("field2: %u\n", bitFieldStruct.field2);  // Output: 31
    printf("field3: %u\n", bitFieldStruct.field3);  // Output: 2

    // =============================
    // Assign a value exceeding bit field size
    // =============================
    bitFieldStruct.field1 = 9;  // 9 = 1001 in binary → only 3 bits stored → 001 = 1
    printf("field1 after overflow: %u\n", bitFieldStruct.field1); // Output: 1 (truncated)

    return 0;
}
```


### Files I/O 
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;  // File pointer

    // =============================
    // 1️⃣ Opening a file
    // =============================
    fp = fopen("example.txt", "w"); // Open for writing (creates file if not exists)
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // =============================
    // 2️⃣ Writing to a file
    // =============================
    fprintf(fp, "Hello, File I/O!\n"); // Write formatted text
    fputs("Writing another line with fputs\n", fp); // Write string
    const char data[] = "Binary data example";
    fwrite(data, 1, sizeof(data), fp); // Write raw bytes

    // =============================
    // 3️⃣ Closing the file
    // =============================
    if (fclose(fp) != 0) {
        perror("Error closing file");
        return 1;
    }

    // =============================
    // 4️⃣ Reading from a file
    // =============================
    fp = fopen("example.txt", "r"); // Open for reading
    if (fp == NULL) {
        perror("Error opening file for reading");
        return 1;
    }

    // Read using fgetc (character by character)
    int c;
    printf("Reading using fgetc:\n");
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }
    fclose(fp);

    // Read using fgets (line by line)
    fp = fopen("example.txt", "r");
    char buffer[100];
    printf("\nReading using fgets:\n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    fclose(fp);

    // =============================
    // 5️⃣ File positioning
    // =============================
    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    fseek(fp, 10, SEEK_SET); // Move file pointer to 10th byte from start
    printf("\nAfter fseek (10th byte):\n");
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }
    fclose(fp);

    return 0;
}
```


```text
TL;DR Notes on File I/O in C

File Pointer: FILE *fp; is used to represent and manage a file.

Opening a file: fopen(filename, mode)

"r" → read, "w" → write, "a" → append

"r+", "w+", "a+" → read/write modes

Always check for NULL.

Closing a file: fclose(fp)

Ensures buffers are flushed and resources released.

Reading:

fgetc → single character

fgets → string/line

fread → binary/block read

Writing:

fprintf → formatted text

fputs → string

fwrite → raw/binary data

File Positioning: fseek(fp, offset, origin)

SEEK_SET → start of file

SEEK_CUR → current position

SEEK_END → end of file
```


### TL;DR summary of C File I/O, combining opening, closing, reading, writing, and error handling

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *filePointer;  // Declare a file pointer

    // =============================
    // 1️⃣ Open file for reading and writing
    // =============================
    filePointer = fopen("example.txt", "w+"); // "w+" = read & write, creates file if not exists
    if (filePointer == NULL) {               // Always check fopen success
        perror("Error opening file");
        return -1;
    }

    // =============================
    // 2️⃣ Writing to the file
    // =============================
    fprintf(filePointer, "Hello, File I/O!\n");       // Formatted text
    fputs("Another line using fputs\n", filePointer); // String
    const char buffer[] = "Binary data example";
    size_t written = fwrite(buffer, 1, sizeof(buffer), filePointer); // Binary write
    if (written != sizeof(buffer)) {
        perror("Error writing to file");
    }

    // =============================
    // 3️⃣ File positioning
    // =============================
    fseek(filePointer, 0, SEEK_SET); // Move pointer back to beginning
    long position = ftell(filePointer); // Get current pointer position
    printf("File pointer position after fseek: %ld\n", position);

    // =============================
    // 4️⃣ Reading from the file
    // =============================
    int c;
    printf("\nReading using fgetc:\n");
    while ((c = fgetc(filePointer)) != EOF) { // Read character by character
        putchar(c);
    }

    // Move pointer to beginning again for fgets
    fseek(filePointer, 0, SEEK_SET);
    char line[100];
    printf("\nReading using fgets:\n");
    while (fgets(line, sizeof(line), filePointer) != NULL) { // Read line by line
        printf("%s", line);
    }

    // =============================
    // 5️⃣ Reading binary data using fread
    // =============================
    fseek(filePointer, 0, SEEK_SET); // Move pointer to start
    char binaryBuffer[50];
    size_t bytesRead = fread(binaryBuffer, 1, sizeof(binaryBuffer), filePointer);
    printf("\nBytes read using fread: %zu\n", bytesRead);

    // =============================
    // 6️⃣ Close the file
    // =============================
    if (fclose(filePointer) != 0) { // Always close files
        perror("Error closing file");
        return -1;
    }

    return 0;
}
```


#### opening, reading, writing, positioning, and error handling
```c
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main() {
    // -------------------------------
    // 1️⃣ Opening a File
    // -------------------------------
    FILE *fp = fopen("example.txt", "w+"); // open for read/write, create if not exists
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    // -------------------------------
    // 2️⃣ Writing to the File
    // -------------------------------
    fprintf(fp, "Name: %s\nAge: %d\n", "John Doe", 30);  // formatted text
    fputs("Hello World!\n", fp);                        // string
    fputc('A', fp);                                     // single character

    int data[5] = {1, 2, 3, 4, 5};
    if (fwrite(data, sizeof(int), 5, fp) != 5) {       // binary data
        perror("Error writing binary data");
        fclose(fp);
        return -1;
    }

    // -------------------------------
    // 3️⃣ File Positioning
    // -------------------------------
    if (fseek(fp, 0, SEEK_SET) != 0) {                // move to start for reading
        perror("fseek error");
        fclose(fp);
        return -1;
    }

    // -------------------------------
    // 4️⃣ Reading from the File
    // -------------------------------
    char buffer[256];

    // read line by line
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    // check for errors during reading
    if (ferror(fp)) {
        perror("Error reading file");
        clearerr(fp); // reset error indicator
    }

    // -------------------------------
    // 5️⃣ Using fgetc to read characters
    // -------------------------------
    if (fseek(fp, 0, SEEK_SET) != 0) {
        perror("fseek error");
        fclose(fp);
        return -1;
    }
    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    // -------------------------------
    // 6️⃣ Using fread for binary data
    // -------------------------------
    if (fseek(fp, 0, SEEK_END) != 0) { // move to end to determine position
        perror("fseek error");
        fclose(fp);
        return -1;
    }
    long file_size = ftell(fp);
    if (file_size == -1L) {
        perror("ftell error");
        fclose(fp);
        return -1;
    }
    printf("\nFile size: %ld bytes\n", file_size);

    // rewind to beginning for demonstration
    rewind(fp);

    // -------------------------------
    // 7️⃣ Closing the File
    // -------------------------------
    if (fclose(fp) != 0) {
        perror("Error closing file");
        return -1;
    }

    printf("File operations completed successfully.\n");
    return 0;
}
```


### C code block demonstrating formatted I/O, error handling, and binary file operations including structs:
```c
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

struct Record {
    int id;
    float value;
    char name[20];
};

int main() {
    // -------------------------------
    // 1️⃣ Formatted Output to a File
    // -------------------------------
    FILE *file = fopen("students.txt", "w");
    if (file == NULL) {
        perror("Error opening students.txt for writing");
        return -1;
    }

    int id = 123;
    char name[] = "Alice";
    float gpa = 3.75;

    // Write formatted data
    if (fprintf(file, "ID: %d\nName: %s\nGPA: %.2f\n", id, name, gpa) < 0) {
        perror("Error writing formatted data");
        fclose(file);
        return -1;
    }

    fclose(file);

    // -------------------------------
    // 2️⃣ Formatted Input from a File
    // -------------------------------
    file = fopen("students.txt", "r");
    if (file == NULL) {
        perror("Error opening students.txt for reading");
        return -1;
    }

    int readId;
    char readName[50];
    float readGpa;

    // Read formatted data with error checking
    if (fscanf(file, "ID: %d\nName: %s\nGPA: %f\n", &readId, readName, &readGpa) != 3) {
        perror("Error reading formatted data");
        fclose(file);
        return -1;
    }

    fclose(file);
    printf("Read from file:\nID: %d\nName: %s\nGPA: %.2f\n", readId, readName, readGpa);

    // -------------------------------
    // 3️⃣ Binary File Writing
    // -------------------------------
    char data[10] = {'H','e','l','l','o',' ','W','o','r','l'};
    file = fopen("example.bin", "wb");
    if (file == NULL) {
        perror("Error opening example.bin for writing");
        return -1;
    }

    if (fwrite(data, sizeof(char), 10, file) != 10) {
        perror("Error writing binary data");
        fclose(file);
        return -1;
    }

    fclose(file);

    // -------------------------------
    // 4️⃣ Binary File Reading
    // -------------------------------
    char buffer[10];
    file = fopen("example.bin", "rb");
    if (file == NULL) {
        perror("Error opening example.bin for reading");
        return -1;
    }

    size_t result = fread(buffer, sizeof(char), 10, file);
    if (result != 10) {
        if (feof(file)) {
            printf("End of file reached.\n");
        } else if (ferror(file)) {
            perror("Error reading binary data");
        }
    } else {
        printf("Binary data read: ");
        for (size_t i = 0; i < result; ++i) {
            putchar(buffer[i]);
        }
        printf("\n");
    }

    fclose(file);

    // -------------------------------
    // 5️⃣ Binary I/O with Structs
    // -------------------------------
    struct Record record = {1, 23.5, "Sample"};

    // Write struct to a binary file
    file = fopen("record.bin", "wb");
    if (file == NULL) {
        perror("Error opening record.bin for writing");
        return -1;
    }

    if (fwrite(&record, sizeof(struct Record), 1, file) != 1) {
        perror("Error writing struct to binary file");
        fclose(file);
        return -1;
    }

    fclose(file);

    // Read struct back from binary file
    struct Record readRecord;
    file = fopen("record.bin", "rb");
    if (file == NULL) {
        perror("Error opening record.bin for reading");
        return -1;
    }

    if (fread(&readRecord, sizeof(struct Record), 1, file) != 1) {
        perror("Error reading struct from binary file");
        fclose(file);
        return -1;
    }

    fclose(file);

    printf("Struct read from binary file:\nID: %d\nValue: %.2f\nName: %s\n",
           readRecord.id, readRecord.value, readRecord.name);

    return 0;
}
```


### Random Access & 10.11 Common Pitfalls – TL;DR

Random Access with Files:

Use fseek() to move the file pointer to any position:

SEEK_SET → from start

SEEK_CUR → from current position

SEEK_END → from end of file

Use ftell() to get current pointer position (returns -1L on error).

rewind() resets pointer to the beginning of the file.

Random access allows reading/writing specific records directly (e.g., nth record in a binary file).

Error-check return values of fseek(), ftell(), and fread()/fwrite() to ensure correct file positioning.

Common File I/O Pitfalls:

Not checking file open success: Always check fopen() returns NULL.

Not closing files: Always fclose() after operations to avoid resource leaks.

Incorrect file modes: Use "r", "w", "a", "rb", "wb", etc., appropriately.

Mixing standard I/O and low-level I/O: Avoid combining fread()/fwrite() with read()/write().

Text vs binary mode mismatch: Text files → default mode, binary → "b" in mode string.

Buffer overflows: Ensure read buffers are large enough (e.g., fgets(buffer, sizeof(buffer), file)).

Ignoring read/write return values: Check fread(), fwrite(), fprintf(), etc., for success.

Mismanagement of file positions: Use fseek() and ftell() carefully to avoid reading/writing wrong locations.

Unsynchronized buffered output: Ensure fclose() or fflush() is called to flush buffers.

Key Takeaway:
Always check return values, handle errors, and manage file pointers carefully for robust, portable file operations. Random access and proper error handling are crucial for data integrity.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* Define a struct to store student data */
struct Student {
    int id;
    char name[50];
    float gpa;
};

int main() {
    FILE *file;
    struct Student students[3] = {
        {101, "Alice", 3.75},
        {102, "Bob", 3.50},
        {103, "Charlie", 3.90}
    };
    struct Student read_student;

    /* ------------------- */
    /* 1. Writing formatted text to a file */
    /* ------------------- */
    file = fopen("students.txt", "w");
    if (!file) {
        perror("Error opening students.txt for writing");
        return -1;
    }

    for (int i = 0; i < 3; i++) {
        if (fprintf(file, "ID: %d\nName: %s\nGPA: %.2f\n\n", 
                    students[i].id, students[i].name, students[i].gpa) < 0) {
            perror("Error writing to students.txt");
            fclose(file);
            return -1;
        }
    }

    if (fclose(file) != 0) {
        perror("Error closing students.txt");
        return -1;
    }

    /* ------------------- */
    /* 2. Reading formatted text from a file */
    /* ------------------- */
    file = fopen("students.txt", "r");
    if (!file) {
        perror("Error opening students.txt for reading");
        return -1;
    }

    printf("Reading formatted text file:\n");
    while (fscanf(file, "ID: %d\nName: %49s\nGPA: %f\n\n", 
                  &read_student.id, read_student.name, &read_student.gpa) == 3) {
        printf("ID: %d, Name: %s, GPA: %.2f\n", 
               read_student.id, read_student.name, read_student.gpa);
    }

    if (ferror(file)) {
        perror("Error reading students.txt");
        clearerr(file);
    }

    fclose(file);

    /* ------------------- */
    /* 3. Writing structs to a binary file */
    /* ------------------- */
    file = fopen("students.bin", "wb");
    if (!file) {
        perror("Error opening students.bin for writing");
        return -1;
    }

    if (fwrite(students, sizeof(struct Student), 3, file) != 3) {
        perror("Error writing to students.bin");
        fclose(file);
        return -1;
    }

    if (fclose(file) != 0) {
        perror("Error closing students.bin");
        return -1;
    }

    /* ------------------- */
    /* 4. Random access reading from binary file */
    /* ------------------- */
    file = fopen("students.bin", "rb");
    if (!file) {
        perror("Error opening students.bin for reading");
        return -1;
    }

    /* Jump directly to the 2nd student (index 1) */
    if (fseek(file, sizeof(struct Student) * 1, SEEK_SET) != 0) {
        perror("Error seeking in students.bin");
        fclose(file);
        return -1;
    }

    if (fread(&read_student, sizeof(struct Student), 1, file) != 1) {
        if (feof(file)) {
            printf("End of file reached unexpectedly.\n");
        } else if (ferror(file)) {
            perror("Error reading from students.bin");
        }
        fclose(file);
        return -1;
    }

    printf("\nRandom access reading (2nd student) from binary file:\n");
    printf("ID: %d, Name: %s, GPA: %.2f\n", 
           read_student.id, read_student.name, read_student.gpa);

    fclose(file);

    /* ------------------- */
    /* 5. Demonstrating fgetc/fputc and error handling */
    /* ------------------- */
    file = fopen("example.txt", "w+");
    if (!file) {
        perror("Error opening example.txt");
        return -1;
    }

    /* Write characters */
    const char *msg = "Hello, File I/O!\n";
    for (size_t i = 0; i < strlen(msg); i++) {
        if (fputc(msg[i], file) == EOF) {
            perror("Error writing character");
            fclose(file);
            return -1;
        }
    }

    /* Reset pointer to beginning and read */
    rewind(file);
    int ch;
    printf("\nReading example.txt character by character:\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    if (ferror(file)) {
        perror("Error reading example.txt");
        clearerr(file);
    }

    fclose(file);

    return 0;
}
```


### Summary 
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Example 1: Copying a text file */
void copy_text_file() {
    FILE *srcFile = fopen("source.txt", "r");
    if (!srcFile) {
        perror("Cannot open source.txt");
        return;
    }

    FILE *destFile = fopen("destination.txt", "w");
    if (!destFile) {
        perror("Cannot open destination.txt");
        fclose(srcFile);
        return;
    }

    int ch;
    while ((ch = fgetc(srcFile)) != EOF) {
        if (fputc(ch, destFile) == EOF) {
            perror("Error writing to destination.txt");
            break;
        }
    }

    fflush(destFile);  // Ensure buffered output is written
    fclose(srcFile);
    fclose(destFile);

    printf("Contents copied to destination.txt\n");
}

/* Example 2: Reading integers from a binary file and calculating average */
void calculate_average_binary() {
    FILE *binFile = fopen("data.bin", "rb");
    if (!binFile) {
        perror("Cannot open data.bin");
        return;
    }

    int num, sum = 0, count = 0;
    while (fread(&num, sizeof(int), 1, binFile) == 1) {
        sum += num;
        count++;
    }

    if (ferror(binFile)) {
        perror("Error reading data.bin");
    } else if (count == 0) {
        printf("No data in the file.\n");
    } else {
        printf("Average: %.2f\n", (double)sum / count);
    }

    fclose(binFile);
}

/* Example 3: Appending to a text file */
void append_log_file() {
    FILE *file = fopen("logfile.txt", "a");
    if (!file) {
        perror("Cannot open logfile.txt");
        return;
    }

    if (fprintf(file, "New log entry: Program executed successfully.\n") < 0) {
        perror("Error writing to logfile.txt");
    }

    fflush(file);  // Ensure the data is flushed
    fclose(file);

    printf("Log entry appended to logfile.txt\n");
}

/* Example 4: Reading structured binary records */
typedef struct {
    char title[50];
    char author[50];
} Book;

void read_books_file() {
    FILE *file = fopen("books.dat", "rb");
    if (!file) {
        perror("Cannot open books.dat");
        return;
    }

    Book book;
    while (fread(&book, sizeof(Book), 1, file) == 1) {
        printf("Title: %s, Author: %s\n", book.title, book.author);
    }

    if (ferror(file)) {
        perror("Error reading books.dat");
    }

    fclose(file);
}

int main() {
    printf("=== Example 1: Copy text file ===\n");
    copy_text_file();

    printf("\n=== Example 2: Binary average calculation ===\n");
    calculate_average_binary();

    printf("\n=== Example 3: Append log file ===\n");
    append_log_file();

    printf("\n=== Example 4: Read structured records ===\n");
    read_books_file();

    return 0;
}
```



### #ifdef
In C, #ifdef DEBUG (or #if DEBUG) is commonly used to include debug-only code that can be enabled or disabled at compile time.
```c
#include <stdio.h>

int main() {
    int x = 10;

#ifdef DEBUG
    printf("Debug: x = %d\n", x);
#endif

    printf("Program running...\n");
    return 0;
}
```

Compile with debug enabled:
```bash
gcc -DDEBUG program.c -o program
```

Compile without debug:
```bash
gcc program.c -o program
```
If DEBUG is defined (-DDEBUG), the debug printf runs. Otherwise, it is completely removed during preprocessing.

### Using #if DEBUG (when DEBUG has a value)
```c
#define DEBUG 1

#if DEBUG
    printf("Debug mode enabled\n");
#endif
```

```bash
gcc -DDEBUG=1 program.c
```

And disable:
```bash
gcc -DDEBUG=0 program.c
```


### Notes
Avoid defining variables in header files. If you
define a variable in a header file, and that header file is included in multiple
source files, you will end up with multiple definitions of the same variable,
which is an error in C. If you need to share a variable between multiple
source files, declare it as an `extern` in the header file and define it in one
source file. This tells the compiler that the variable is defined somewhere
else, without creating multiple definitions.
3. Preventing Double Inclusion: Use `#ifndef` and `#define` to prevent


**Preventing Double Inclusion**: Use `#ifndef` and `#define` to prevent
double inclusion of header files. Double inclusion can happen when one
header file includes another header file that it has already included. This can
lead to errors and confusion, as it can result in the same declarations
appearing multiple times. To prevent this, you can use an
`#ifndef`/`#define` guard at the beginning of your header file, like this:

```c

#ifndef HEADER_FILE_H
#define HEADER_FILE_H
// contents of the header file go here
#endif
```


### C compiler
When compiling a C program (e.g., with GCC), you can use command-line switches to control how the compiler behaves:

Optimization (-O0 to -O3) – Controls how much the compiler optimizes your code.

Warnings (-Wall) – Enables helpful warnings about potential code issues.

Debug info (-g) – Adds debugging information for use with debuggers.

Link libraries (-l) – Links external libraries your program depends on.

Define macros (-D) – Defines preprocessor macros from the command line.

/*
========================================================
STATIC vs DYNAMIC LIBRARIES IN C
========================================================

A library is a collection of precompiled object files
that you can reuse in multiple programs.

There are TWO main types:

1) STATIC LIBRARY (.a on Linux, .lib on Windows)
2) DYNAMIC (SHARED) LIBRARY (.so on Linux, .dll on Windows)

--------------------------------------------------------
STATIC LIBRARY
--------------------------------------------------------

✔ Code is copied INTO your executable at link time.
✔ Larger executable size.
✔ No external dependency needed at runtime.
✔ Faster startup.
✔ If the library changes, you must recompile the program.

Static libraries are also called:
- Archives
- Collections of object (.o) files

--------------------------------------------------------
STEP-BY-STEP: CREATE AND USE A STATIC LIBRARY
--------------------------------------------------------

Assume we want a simple math library.

--------------------------------------------------------
1) Create the source file (mymath.c)
--------------------------------------------------------

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

--------------------------------------------------------
2) Compile into object file
--------------------------------------------------------

gcc -c mymath.c
// Produces: mymath.o

--------------------------------------------------------
3) Create static library archive
--------------------------------------------------------

ar rcs libmymath.a mymath.o

// ar = archive tool
// r = replace or add files
// c = create if not exists
// s = create index

Now we have: libmymath.a

--------------------------------------------------------
4) Create header file (mymath.h)
--------------------------------------------------------

#ifndef MYMATH_H
#define MYMATH_H

int add(int a, int b);
int multiply(int a, int b);

#endif

--------------------------------------------------------
5) Use the static library in main.c
--------------------------------------------------------

#include <stdio.h>
#include "mymath.h"

int main() {
    printf("%d\n", add(2, 3));
    printf("%d\n", multiply(4, 5));
    return 0;
}

--------------------------------------------------------
6) Compile and link with static library
--------------------------------------------------------

gcc main.c -L. -lmymath -o app

// -L.        -> look in current directory for libraries
// -lmymath   -> links libmymath.a (lib + name + .a)
// -o app     -> output executable

The library code is now INSIDE the executable.

========================================================
DYNAMIC (SHARED) LIBRARY
========================================================

✔ Code is NOT copied into executable.
✔ Smaller executable.
✔ Library loaded at runtime.
✔ Must exist on system when program runs.
✔ Can update library without recompiling program.

--------------------------------------------------------
STEP-BY-STEP: CREATE SHARED LIBRARY
--------------------------------------------------------

1) Compile with position independent code:

gcc -fPIC -c mymath.c

2) Create shared library:

gcc -shared -o libmymath.so mymath.o

Now we have: libmymath.so

--------------------------------------------------------
3) Compile program using shared library
--------------------------------------------------------

gcc main.c -L. -lmymath -o app

4) Run (if library not installed system-wide):

export LD_LIBRARY_PATH=.
./app

========================================================
KEY DIFFERENCE SUMMARY
========================================================

STATIC:
- Linked at compile time
- Bigger executable
- No runtime dependency

DYNAMIC:
- Linked at runtime
- Smaller executable
- Requires .so file at runtime

========================================================
INTERVIEW SUMMARY
========================================================

Static library:
    Code becomes part of executable.

Dynamic library:
    Code stays separate and is loaded when program runs.

========================================================
*/


ECreating and Using a Static Library in C
What is a Static Library?

A static library:
Is also called an archive
Is a collection of object files (.o)
Has extension:
.a (Linux/macOS)
.lib (Windows)

Gets copied into the executable at link time
Does NOT require the library file at runtimex 2: 

### Step 1 — Write the Header File
mathlib.h
```c
#ifndef MATHLIB_H
#define MATHLIB_H

double add(double a, double b);
double subtract(double a, double b);

#endif
```
✔ Header contains function declarations only
✔ Uses include guards to prevent multiple inclusion

Step 2 — Write the Source File
```c
#include "mathlib.h"

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}
```

✔ Source file contains function definitions

### Step 3 — Compile to Object File
```bash
gcc -c mathlib.c
```
-c = compile only (do NOT link)
Produces: mathlib.o

### Step 4 — Create the Static Library (Archive)
```bash
ar rcs libmathlib.a mathlib.o
```
Explanation of ar rcs:

r → insert/replace files
c → create archive if it doesn’t exist
s → create index (for faster linking)
This creates:
```bash
libmathlib.a
```
Note:
Library naming convention:
```bash
lib + name + .a
```

### Step 5 — Use the Library in Your Program
main.c
```c
#include <stdio.h>
#include "mathlib.h"

int main() {
    double result = add(1.0, 2.3);
    printf("Result: %.2f\n", result);
    return 0;
}
```

### Step 6 — Compile and Link the Library
```bash
gcc main.c -L. -lmathlib -o main
```
Explanation:

-L. → look in current directory for libraries
-lmathlib → links libmathlib.a
You do NOT write lib
You do NOT write .a
-o main → output executable name

Important Rule to Remember
When using -l:
```c
libmathlib.a  →  -lmathlib
```
GCC automatically adds:
```bash
lib
.a
```

### Dynamic libraries
A dynamic library (also called a shared library) :

Has extension:
.so (Linux)
.dll (Windows)
Is NOT copied into the executable
Is loaded at runtime
Makes executable smaller
Must exist on the system when the program runs

### Step 1 — Write the Header File
mathlib.h
```c
#ifndef MATHLIB_H
#define MATHLIB_H

double add(double a, double b);
double subtract(double a, double b);

#endif
```

Step 2 — Write the Source File
mathlib.c
```c
#include "mathlib.h"

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}
```

### Step 3 — Compile with Position Independent Code (IMPORTANT)
Dynamic libraries require position-independent code (PIC).
```bash
gcc -fPIC -c mathlib.c
```
-fPIC → generate position-independent code
Produces: mathlib.o

### Step 4 — Create the Shared Library
```c
gcc -shared -o libmathlib.so mathlib.o
```
Explanation:

-shared → create shared library
-o libmathlib.so → output file name
Now you have:
```bash
libmathlib.so
```

### Step 5 — Create Your Main Program
main.c
```c
#include <stdio.h>
#include "mathlib.h"

int main() {
    double result = add(5.0, 3.0);
    printf("Result: %.2f\n", result);
    return 0;
}
```

### Step 6 — Compile and Link Against the Shared Library
```bash
gcc main.c -L. -lmathlib -o main
```

Same linking rule as static libraries:
```bash
libmathlib.so  →  -lmathlib
```

### Step 7 — Run the Program (Very Important)
Because the library is loaded at runtime, the system must be able to find it.
If it's in the current directory:
```bash
export LD_LIBRARY_PATH=.
./main
```

Or temporarily:
```bash
LD_LIBRARY_PATH=. ./main
```

Static vs Dynamic — Quick Comparison

| Feature                             | Static Library | Dynamic Library |
| ----------------------------------- | -------------- | --------------- |
| Extension                           | `.a`           | `.so`           |
| When linked                         | Compile time   | Runtime         |
| Executable size                     | Larger         | Smaller         |
| Needs library at runtime?           | ❌ No           | ✅ Yes           |
| Update library without recompiling? | ❌ No           | ✅ Yes           |
