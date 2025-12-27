#### Preprocessors:

are programs that process the source code before the actual compilation begins. They are not part of the compilation process but operate separately, allowing programmers to modify the code before compilation.

It is the first step that the C source code goes through when being converted into an executable file.
Main types of Preprocessor Directives are Macros, File Inclusion, Conditional Compilation and Other directives like #undef, #pragma, etc.
Mainly these directives are used to replace a given section of C code with another C code. For example, if we write "#define PI 3.14", then PI is replaced with 3.14 by the preprocessor.

### Types of C Preprocessors

All the above preprocessors can be classified into 4 types:
Macros

Macros are used to define constants or create functions that are substituted by the preprocessor before the code is compiled. The two preprocessors #define and #undef are used to create and remove macros in C.

    #define token value
    #undef token

where after preprocessing, the token will be expanded to its value in the program.

Example:

```go
#include <stdio.h>
// Macro Definition

#define LIMIT 5

int main(){

    for (int i = 0; i < LIMIT; i++) {

        printf("%d \n", i);

    }

    return 0;

}

```

Output

0
1
2
3
4

In the above program, before the compilation begins, the word LIMIT is replaced with 5. The word 'LIMIT' in the macro definition is called a macro template and '5' is macro expansion.

Note There is no semi-colon (;) at the end of the macro definition. Macro definitions do not need a semi-colon to end.

There are also some Predefined Macros in C which are useful in providing various functionalities to our program.

#### Macro

A macro defined previously can be undefined using #undef preprocessor. For example, in the above code,

```go
#include <stdio.h>
// Macro Definition

#define LIMIT 5

// Undefine macro

#undef LIMIT

int main(){

    for (int i = 0; i < LIMIT; i++) {

        printf("%d \n", i);

    }

    return 0;

}
```

Output:

./Solution.c: In function 'main':
./Solution.c:13:28: error: 'MAX' undeclared (first use in this function)
printf("MAX is: %d\n", MAX);
^
./Solution.c:13:28: note: each undeclared identifier is reported only once for each function it appears in

#### Macros With Arguments

We can also pass arguments to macros. These macros work similarly to functions. For example,

    #define foo(a, b) a + b
    #define func(r) r * r

Let us understand this with a program:

```go
#include <stdio.h>

// macro with parameter

#define AREA(l, b) (l \* b)

int main() {

  int a = 10, b = 5;
  // Finding area using above macro

  printf("%d", AREA(a, b));

  return 0;
}
```

Output

Area of rectangle is: 50

Explanation: In the above program, the macro AREA(l, b) is defined to calculate the area of a rectangle by multiplying its length (l) and breadth (b). When AREA(a, b) is called, it expands to (a \* b), and the result is computed and printed.


### File Inclusion

File inclusion allows you to include external files (header files, libraries, etc.) into the current program. This is typically done using the #include directive, which can include both system and user-defined files.

Syntax

There are two ways to include header files.

    #include <file_name>
    #include "filename"

The '<' and '>' brackets tell the compiler to look for the file in the standard directory while double quotes ( " " ) tell the compiler to search for the header file in the source file's directory.

Example:

```go
// Includes the standard I/O library

#include <stdio.h>

int main() {

    printf("Hello World");
    return 0;
}

```
Output

Hello World

#### Conditional Compilation

Conditional compilation allows you to include or exclude parts of the code depending on certain conditions. This is useful for creating platform-specific code or for debugging. There are the following conditional preprocessor directives: #if, #ifdef, #ifndef, else, #elif and #endif

Syntax

The general syntax of conditional preprocessors is:

    #if
        // some code
    #elif
        // some more code
    #else
        // Some more code
    #endif

#endif directive is used to close off the #if, #ifdef, and #ifndef opening directives.

Example

```go
#include <stdio.h>

// Defining a macro for PI

#define PI 3.14159


int main(){
// Check if PI is defined using #ifdef
#ifdef PI
    printf("PI is defined\n");
#elif defined(SQUARE)
    printf("Square is defined\n");
// If neither PI nor SQUARE is defined, trigger an error
#else
    #error "Neither PI nor SQUARE is defined"
#endif

// Check if SQUARE is not defined using #ifndef
#ifndef SQUARE
    printf("Square is not defined");
// If SQUARE is defined, print that it is defined

#else
    printf("Square is defined");

#endif
    return 0;
}
```

Output

PI is defined
Square is not defined

Explanation: This code uses conditional preprocessor directives (#ifdef, #elif, and #ifndef) to check whether certain macros (PI and SQUARE) are defined. Since PI is defined, the program prints "PI is defined", then checks if SQUARE is not defined and prints "Square is not defined".
Other Directives

Apart from the primary preprocessor directives, C also provides other directives to manage compiler behaviour and debugging.

### #pragma:

Provides specific instructions to the compiler to control its behaviour. It is used to disable warnings, set alignment, etc.

Syntax

    #pragma directive

Some of the #pragma directives are discussed below:

    #pragma startup: These directives help us to specify the functions that are needed to run before program startup (before the control passes to main()).
    #pragma exit: These directives help us to specify the functions that are needed to run just before the program exit (just before the control returns from main()).

Example

```go
#include <stdio.h>
void func1();
void func2();

// specifying funct1 to execute at start
#pragma startup func1

// specifying funct2 to execute before end
#pragma exit func2
void func1() { printf("Inside func1()\n"); }
void func2() { printf("Inside func2()\n"); }

int main(){
    void func1();
    void func2();
    printf("Inside main()\n");
    return 0;
}
```

Output

Inside main()

The above code will produce the output as given above when run on GCC compilers while the expected output was:

Expected Output

```bash
Inside func1()
Inside main()
Inside func2()

```
This happens because GCC does not support #pragma startup or exit. However, you can use the below code for the expected output on GCC compilers.

```go
#include <stdio.h>


void func1();
void func2();


void **attribute**((constructor)) func1();
void **attribute**((destructor)) func2();


void func1()

{
    printf("Inside func1()\n");
}


void func2()

{
    printf("Inside func2()\n");

}


int main()

{
    printf("Inside main()\n");
    return 0;

}

```
Output

Inside func1()
Inside main()
Inside func2()

In the above program, we have used some specific syntaxes so that one of the functions executes before the main function and the other executes after the main function.
