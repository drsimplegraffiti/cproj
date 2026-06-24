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

// primary data type in C : int, char, double, float
// complex data types in C are : arrays, structs, pointers


    printf("hello world \n"); // statements end with semicolons
    return 0;
}
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

// function prototype
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
  printf("Value through pointer: %d\n", *ptr);

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


