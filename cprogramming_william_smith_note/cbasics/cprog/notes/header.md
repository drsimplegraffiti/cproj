n C programming, a header file is a file that ends with the .h extension and contains features like functions, data types, macros, etc that can be used by any other C program by including that particular header file using "#include" preprocessor.

C language uses header files to provide the standard libraries and their components for use in programs.

```go
// Adding standard input and output library by
// including stdio.h header file
#include <stdio.h>

int main() {

  	// printf() function from stdio.h header file
    printf("Hello");
    return 0;
}```

#### Include Header Files

We have to include header files in our C program to use its features. There are two ways to do that:

```go
// for header files in system/default
// directory
#include <filename.h>

// for Header files in same directory as
// source file
#include "filename.h"
```


