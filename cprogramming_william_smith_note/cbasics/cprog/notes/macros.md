In C programming, a macro is a symbolic name or constant that represents a value, expression, or code snippet. They are defined using the #define directive, and when encountered, the preprocessor substitutes it with its defined content.

Example

```go
#include <stdio.h>

#define LIMIT 5

int main(){
    printf("LIMIT: %d", LIMIT);
    return 0;

}
```

Output

LIMIT: 5

Explanation: In this code, a macro LIMIT is defined with the value 5 using the #define directive. The macro LIMIT is then used in the printf function to print its value, which is 5. The preprocessor replaces the macro LIMIT with its defined value before the code is compiled, so the output of the program will display the value 5.
Syntax

- The general syntax to define a macro is:

```go
#define MACRO_NAME value
```

where MACRO_NAME is the name of the macro and value is the code or value that replaces the macro name. It is to be noted that macros don't necessarily need to be in uppercase. Instead, it is a convention that makes it easy to recognize.

#### Types Of Macros in C

There are two types of macros in C language:

1. Object-Like Macros

Object-like macros are the simplest type of macros. They replace the macro name with a defined value or expression. These are used for constants or simple values.

```go
#include <stdio.h>
// Macro definition

#define DATE 31

int main(){
    // Print the message

    printf("Lockdown will be extended"

           " upto %d-MAY-2020",

           DATE);

    return 0;
}
```

Output

Lockdown will be extended upto 31-MAY-2020

Explanation: In this program, the object-like macro DATE is defined as 31. It is used in the printf function to insert the value 31 into the message, which the preprocessor replaces before compilation. 2.

#### Chain Macros


These macros involve chaining multiple macros together. This can be done by combining different macros in a single macro definition, allowing for more complex operations. In chain macros first of all parent macro is expanded then the child macro is expanded.

```go
#include <stdio.h>
// Macro definition

#define INSTAGRAM FOLLOWERS
#define FOLLOWERS 138

int main(){

    printf("Geeks for Geeks have %dK"

           " followers on Instagram",

           INSTAGRAM);
    return 0;
}
```

Output

Geeks for Geeks have 138K followers on Instagram

Explanation: INSTAGRAM is expanded first to produce FOLLOWERS. Then the expanded macro is expanded to produce the outcome as 138K. This is called the chaining of macros. 3. Multi-Line Macros

These macros span multiple lines for readability and organization. They are often used when you need a more complex expression or code block. To create a multi-line macro you have to use backslash \.

```go
#include <stdio.h>

// Multi-line Macro definition

#define ELE 1, \

            2, \

            3

int main(){
    // Array arr[] with elements
    // defined in macros

    int arr[] = { ELE };

    for (int i = 0; i < 3; i++) {

        printf("%d  ", arr[i]);

    }
    return 0;
}
```

Output

1 2 3

Explanation: In this program, a multi-line macro ELE is defined with the values 1, 2, 3, which is used to initialize the array arr[]. The preprocessor replaces ELE with these values. 4. Function-Like Macros

These macros take parameters and behave like functions, allowing you to define reusable logic for common operations. They are expanded at compile time. A function-like macro is only lengthened if and only if its name appears with a pair of parentheses after it. If we don't do this, the function pointer will get the address of the real function and lead to a syntax error.

```go
#include <stdio.h>
// Function-like Macro definition

#define min(a, b) (((a) < (b)) ? (a) : (b))

int main(){
    // Given two number a and b
    int a = 18, b = 76;
    printf("Minimum: %d", min(a, b));
    return 0;
}

```
Output

Minimum: 18

Explanation: In this code, the function-like macro min(a, b) compares two values and returns the smaller using the ternary operator. The values 18 and 76 are passed to the macro, which returns 18.
