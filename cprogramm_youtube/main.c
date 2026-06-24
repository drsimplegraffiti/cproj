#include <stdio.h>
#include <stdlib.h>

int main() {

    // Error -> when something goes wrong with your program
    // 1. Compilation Error:
    // this happens before the program runs, the compilers catches this error.
    // GCC/ Clang
    // int age = "hello";
    // printf("hello\n")
    // printf("printf\\");

    // 2. Runtime error
    // this kind of error happens when the program is running
    // int a = 10/0;
    // int *p = NULL;
    // *p = 10;
    // printf("%p\n", p);

    // 3. Logical error
    // if (x = 8)
    //   printf("something\n");
    // }

    // Error handling: in C error handling is manual
    // 1. Return codes: (0, 1, EXIT_FAILURE, EXIT_SUCCESS)

    // int denominator = 10;
    // if (denominator == 0) {
    //   printf("Error: division by zero \n");
    //   return EXIT_FAILURE;
    // }
    //
    // printf("all good\n");
    // return EXIT_SUCCESS; // anything non-zero is any error

    // 2. perror (system level error) --> print error
    // use when a system/library calls failes and set errno
    // FILE *file = fopen("data.txt", "r");
    // if(file == NULL){
    //     perror("failed to open file");
    // }
    //
    // fclose(file);
    // return EXIT_SUCCESS;

    // 3. Custom error
// int denominator = 0;
// if(denominator == 0){
//     fprintf(stderr, "invalid input\n");
// }
// return 0;

// 4. exit() immediate termination

int denominator = 0;
if(denominator == 0){
    fprintf(stderr, "FATAL ERROR\n");
    exit(EXIT_FAILURE);
}

// return 0;
}
