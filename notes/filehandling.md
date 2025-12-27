# File Opening Modes in C

File opening modes (also called **access modes**) specify the allowed operations on a file.
They are passed as the second argument to the `fopen()` function.

---

## Common File Opening Modes

| Opening Mode | Description                                                                                                                                                                           |
| ------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `r`          | Opens a file for **reading** in text mode. The file must exist. If successful, the file pointer is set to the **beginning** of the file. Returns `NULL` if the file cannot be opened. |
| `rb`         | Opens a file for **reading** in **binary** mode. The file must exist. Returns `NULL` if the file cannot be opened.                                                                    |
| `w`          | Opens a file for **writing** in text mode. If the file exists, its contents are **overwritten**. If the file does not exist, a **new file is created**. Returns `NULL` on failure.    |
| `wb`         | Opens a file for **writing** in **binary** mode. If the file exists, its contents are **overwritten**. If the file does not exist, it is created.                                     |
| `a`          | Opens a file for **appending** in text mode. Data is written at the **end** of the file. If the file does not exist, a new file is created. Returns `NULL` on failure.                |
| `ab`         | Opens a file for **appending** in **binary** mode. Data is added to the end of the file. If the file does not exist, it is created.                                                   |
| `r+`         | Opens a file for **reading and writing** in text mode. The file must exist. The file pointer is set to the **beginning**. Returns `NULL` on failure.                                  |
| `rb+`        | Opens a file for **reading and writing** in **binary** mode. The file must exist. Returns `NULL` on failure.                                                                          |
| `w+`         | Opens a file for **reading and writing** in text mode. If the file exists, its contents are **overwritten**. If it does not exist, a new file is created. Returns `NULL` on failure.  |
| `wb+`        | Opens a file for **reading and writing** in **binary** mode. If the file exists, its contents are **overwritten**. If it does not exist, a new file is created.                       |
| `a+`         | Opens a file for **reading and appending** in text mode. Reading is allowed, but writing always happens at the **end** of the file. If the file does not exist, it is created.        |
| `ab+`        | Opens a file for **reading and appending** in **binary** mode. Writing occurs at the end of the file. If the file does not exist, it is created.                                      |

---

## Example Usage

```c
#include <stdio.h>

int main() {
    FILE *fp = fopen("example.txt", "a+");

    if (fp == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    fprintf(fp, "Hello, file!\n");
    fclose(fp);

    return 0;
}
```

# Write to a File in C

File write operations in C are commonly performed using `fprintf()` and `fputs()`.
C also provides several other functions for writing data to files.

---

## Common File Write Functions

| Function    | Description                                                                                                    |
| ----------- | -------------------------------------------------------------------------------------------------------------- |
| `fprintf()` | Similar to `printf()`. Uses a formatted string and variable argument list to write formatted output to a file. |
| `fputs()`   | Writes a string to the file. Does **not** automatically add a newline unless explicitly included.              |
| `fputc()`   | Writes a single character to the file.                                                                         |
| `fputw()`   | Writes an integer to the file. _(Non-standard, compiler dependent)_                                            |
| `fwrite()`  | Writes a specified number of bytes to a binary file. Commonly used for binary data.                            |

---

## Examples

### Using `fprintf()`

```c
#include <stdio.h>

int main() {
    FILE *fp = fopen("data.txt", "w");

    if (fp == NULL) {
        return 1;
    }

    fprintf(fp, "Age: %d\n", 25);
    fprintf(fp, "Score: %.2f\n", 98.5);

    fclose(fp);
    return 0;
}
```

# Reading From a File in C

File read operations in C can be performed using functions such as `fscanf()` and `fgets()`.
These functions work similarly to `scanf()` and `gets()`, but with an additional **file pointer** parameter.

C also provides other functions for reading data from a file, as listed below.

---

## Common File Read Functions

| Function   | Description                                                                             |
| ---------- | --------------------------------------------------------------------------------------- |
| `fscanf()` | Uses a formatted string and variable argument list to read formatted input from a file. |
| `fgets()`  | Reads an entire line from a file (including the newline character, if present).         |
| `fgetc()`  | Reads a single character from a file.                                                   |
| `fgetw()`  | Reads an integer from a file. _(Non-standard, compiler dependent)_                      |
| `fread()`  | Reads a specified number of bytes from a binary file.                                   |

---

## Examples

### Using `fscanf()`

```c
#include <stdio.h>

int main() {
    FILE *fp = fopen("data.txt", "r");
    int age;

    if (fp == NULL) {
        return 1;
    }

    fscanf(fp, "%d", &age);
    printf("Age: %d\n", age);

    fclose(fp);
    return 0;
}
```

#### Closing a File

The fclose() function is used to close the file. After successful file operations, you must always close a file to remove it from the memory.

### file handling exceptions

Error Handling Techniques

Below are some standard error handling techniques:

1. File Not Found Error

A file not found error can occur when opening a file in read mode (r) or append mode (a). Use fopen() and check for NULL. If it is, the error message can be printed using perror() function.

```c
#include <stdio.h>

int main() {

    // Try to open file in
    // read mode
    FILE *file = fopen("file.txt", "r");

  	// Check if the file
  	// is opened/found
    if (file == NULL) {
        perror("Error");
        return 1;
    }
    fclose(file);
    return 0;
}
```


2. Handle Permission Denied Error

If the file exists but the program lacks the required permissions, fopen() will fail and return NULL pointer. We can change the perror() output to "permission denied" as shown in the below snippet.

```c
FILE *file = fopen("/restricted/file.txt", "w");
if (file == NULL) {
    perror("Permission denied");
}
```

3. Handle Disk Full Error

When writing to a file, ensure the disk has enough space. Errors during file operations can be detected using ferror(). In the below program, we assume that there is no space in memory to store any data.

```c
#include <stdio.h>

int main() {
    FILE *fptr = fopen("file.txt", "w");
    if (fptr == NULL) {
        perror("Error opening file");
        return 1;
    }

    fprintf(fptr, "Writing to file");

    // Check error after performing
    // write operation
    if (ferror(fptr)) {
        perror("Error writing to file");
    }
    fclose(fptr);
    return 0;
}
```


Output

Error writing to file: Permission Denied

4. Handle File Already Exists

When creating a new file with fopen() in w mode, the existing file will be overwritten. To avoid this, we open a new file in wx mode because if file is already present then fopen() return NULL and set the EEXIST value to the errno. In the below program, we assume that "test.text" file is already present in current directory.

```c
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
int main() {
    FILE *fptr;

    // Try to open the file in
    // write mode
    fptr = fopen("test.text", "wx");

    if (fptr == NULL) {

        // Check if the error is
        // due to file already existing
        if (errno == EEXIST)
            printf("File already exist");
    }

    // If we reach here, the file
    // was created successfully
    fprintf(fptr, "This is a new file.");
    fclose(fptr);
    return 0;
}


```
Output

File already exist

5. Handle Invalid File Pointer

Always verify that the file pointer is not NULL before performing operations like reading or writing.

```c
FILE *file = NULL;

if (file == NULL) {

    printf("Invalid file pointer. File operations cannot proceed.\n");

}
```

6. Handle End-of-File (EOF)

When we are reading data from a file and the file pointer reaches the end of the file, we can use the feof() function to handle the end of the file.

```c
#include <stdio.h>

int main() {
    FILE *file = fopen("test.txt", "r");

  	// Check for eof while reading
    char ch;
    while ((ch = fgetc(file)) != EOF)
        putchar(ch);

  	// Use feof() to make sure
  	// EOF occurred or not
    if (feof(file))
        printf("End of file reached.");
    else if (ferror(file))
        printf("Error reading the file.");
    fclose(file);
    return 0;
}


```
Output

End of file reached.

7. Handle File Not Open

Whenever we attempt to open a file and the file cannot be opened due to some error, the fopen() function returns NULL. We can handle this easily using an if-else statement.

```c
#include <stdio.h>
int main() {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("File could not be opened.\n");
    } else {
        printf("File opened successfully.\n");
        fclose(file);
    }

    return 0;
}

```
Output

File could not be opened.

File Closing Error

Sometimes, when we are closing a file using the fclose() function and it fails to close the file due to an error, it returns -1.

```c
#include <stdio.h>

int main() {

    FILE *fptr = fopen("test.txt", "w");



    fprintf(fptr, "Writing to file");



    // Check file close properly

    if(fclose(fptr) == -1)

        printf("File closing error");

    else

        printf("File closed");

    return 0;

}
```

Output
