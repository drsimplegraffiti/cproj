// Using if-else
//
// In C, error handling is done manually since there is no built-in try-catch
// block like in other programming languages. To manage errors, we can use
// if-else statements to check for conditions and handle any potential errors
// that may occur during program execution.
//
// Example:

```c
#include <errno.h>
#include <stdio.h>

int main() {
  FILE *fp;

  // opening a file which does not exist
  fp = fopen("gfg.txt", "r");

  if (fp == NULL) {
    printf("File openning error");
  } else {
    printf("File open successfully");
  }
  return 0;
}
```

2. perror()

The perror() function is used to print an error message to the standard error stream (stderr). It helps to display the error string based on the global errno variable, which stores the error code set by system calls and library functions.

Example

```c
#include <errno.h>
#include <stdio.h>
#include <string.h>

int main(){
    FILE* fp;

    // Try opening a non-existent file, which sets errno
    fp = fopen("gfg.txt", "r");

    // Print the errno value after failed file opening
    printf("Value of errno: %d\n", errno);
    perror("Message from perror");

    return 0;
}
```


3. strerror()

The strerror() function is also used to show the error description. This function returns a pointer to the textual representation of the current errno value.
```c
#include <errno.h>
#include <stdio.h>
#include <string.h>

int main() {
    FILE* fp;

    // Try opening a non-existent file, setting errno
    fp = fopen("gfg.txt", "r");

    // Print errno value and corresponding error message
    printf("Value of errno: %d\n", errno);
    printf("The error message is : %s", strerror(errno));

    return 0;
}
```


4. ferror()

The ferror() function is used to check if an error occurred during a file operation. It returns a non-zero value if there was an error during the file operation.

Example
```c
#include <stdio.h>

int main() {
    FILE *fptr = fopen("gfg.txt", "w");

    // Write data to the file
    fprintf(fptr, "Hello, GFG!");

  	// Check error after writing data into file
    if(ferror(fptr)==0)
        printf("Data written successfully.");
    fclose(fptr);
    return 0;
}
```

5. feof()

The feof() function checks whether the end of a file has been reached during reading operations. It helps to identify when there is no more data to read from the file.

Example
```c
#include <stdio.h>

int main () {
    FILE *fp = fopen("gfg.txt","r");
    if (fp == NULL)
      return 0;

    do {
        // Taking input single character at a time
        char c = fgetc(fp);

        // Checking for end of file
        if (feof(fp))
            break ;

        printf("%c", c);
    }while(1);

    fclose(fp);
    return(0);
}
```


clearerr()

The clearerr() function is used to clear the error and EOF flags for a stream. It allows recovery from errors and allows the stream to be reused for further operations.

Example
```c
#include <stdio.h>

int main() {
    FILE *fptr = fopen("gfg.txt", "w+");
    fprintf(fptr, "GeeksForGeeks!");
    while (fgetc(fptr) != EOF);

    if(feof(fptr)){
        printf("EOF ancounter \n");
    }

  	// Reset EOF using clearerr
    clearerr(fptr);
    if(!feof(fptr)){
        printf("Reset the EOF successfully");
    }

    fclose(fptr);
    return 0;
}
```

Exit Status

C programs use the exit() function to terminate the program and return a status code to the operating system. The C standard specifies two constants: EXIT_SUCCESS and EXIT_FAILURE, that may be passed to exit() to indicate successful or unsuccessful termination, respectively. These are macros defined in <stdlib.h> header file.

Example
```c
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE* fp;

    // Attempt to open a non-existent file in binary mode
    fp = fopen("gfg.txt", "rb");

    if (fp == NULL) {
        printf("Value of errno: %d\n", errno);
        printf("Error opening the file: %s\n", strerror(errno));
        perror("Error printed by perror");

        // Exit the program with failure status
        exit(EXIT_FAILURE);

        // This line will not be printed because of exit()
        printf("I will not be printed\n");
    }

     // If the file is opened successfully
    else {
        fclose(fp);
        exit(EXIT_SUCCESS);
        printf("I will not be printed\n");
    }
    return 0;
}
```
