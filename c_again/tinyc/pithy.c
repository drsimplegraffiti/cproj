#include <stdio.h>  // Provides file handling and input/output functions
#include <stdlib.h> // Provides malloc() and exit()
#include <string.h> // Provides strlen() and strcpy()

#define BSIZE 256 // Defines the buffer size

int main(void) {

    const char filename[] = "pithy.txt"; // Name of the file to read

    FILE *fp;           // File pointer
    char buffer[BSIZE]; // Temporary storage for each line read
    char *r, *entry;    // Pointers for fgets() result and allocated memory
    int items;          // Counts the number of lines read

    fp = fopen(filename, "r"); // Opens the file in read-only mode

    if (fp == NULL) { // Checks whether the file opened successfully
        fprintf(stderr, "Unable to open file %s\n", filename);
        exit(1); // Terminates if the file cannot be opened
    }

    items = 0; // Initializes the line counter

    while ((r = fgets(buffer, BSIZE, fp)) != NULL) {

        // Allocates enough memory for the string and its null terminator
        entry = malloc(sizeof(char) * (strlen(buffer) + 1));

        if (entry == NULL) { // Checks whether memory allocation failed
            fprintf(stderr, "Unable to allocate memory\n");
            fclose(fp);
            exit(1);
        }

        strcpy(entry,
               buffer); // Copies the buffer contents into allocated memory

        printf("%d: %s", items,
               entry); // Prints the line number and its contents

        items++; // Increments the line counter

        free(entry); // Releases the allocated memory
    }

    fclose(fp); // Closes the file

    return 0; // Indicates successful execution
}

/* #include <stdio.h>  // Provides file handling and input/output functions */
/* #include <stdlib.h> // Provides exit() for terminating the program */

/* #define BSIZE 256 // Defines the maximum number of characters to read at once
 */

/* int main(void) { // Program execution starts here */

/*     const char filename[] = "pithy.txt"; // Stores the name of the file to
 * read */

/*     FILE *fp;           // Declares a file pointer to manage the opened file
 */
/*     char buffer[BSIZE]; // Creates a character array to temporarily store
 * file */
/*                         // contents */
/*     char *r;            // Stores the return value of fgets() */

/*     fp = fopen(filename, "r"); // Opens the file in read-only mode */

/*     if (fp == NULL) { // Checks whether the file was successfully opened */
/*         fprintf(stderr, "Unable to open file %s\n", */
/*                 filename); // Prints error to stderr */
/*         exit(1);           // Terminates the program with an error status */
/*     } */

/*     while ((r = fgets(buffer, BSIZE, fp)) != */
/*            NULL) {            // Reads one line until EOF or an error */
/*         printf("%s", buffer); // Prints the contents read into the buffer */
/*     } */

/*     fclose(fp); // Closes the file and releases associated resources */

/*     return 0; // Terminates successfully */
/* } */

/* cat > pithy.txt <<'EOF' */
/* Simplicity is the ultimate sophistication. */

/* Programs must be written for people to read, */
/* and only incidentally for machines to execute. */

/* First, solve the problem. Then, write the code. */

/* The best way to learn C is to write C. */
/* EOF */
