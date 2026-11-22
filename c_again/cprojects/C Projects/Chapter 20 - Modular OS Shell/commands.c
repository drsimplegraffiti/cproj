/*
 * Chapter 20 - Modular OS Shell
 * commands.c - command processing module (ls, hello, etc.)
 */

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>

#include "commands.h"
#include "memory.h"

void process_command(const char* input) {
    if (strcmp(input, "hello") == 0) {
        printf("Hello, User!\n");
    } else if (strcmp(input, "ls") == 0) {
        DIR* d = opendir(".");
        if (d) {
            struct dirent* dir;
            while ((dir = readdir(d)) != NULL) {
                printf("%s\n", dir->d_name);
            }
            closedir(d);
        } else {
            perror("opendir");
        }
    } else if (strncmp(input, "alloc ", 6) == 0) {
        int n = atoi(input + 6);
        if (n <= 0) {
            printf("Usage: alloc <positive number>\n");
            return;
        }
        void* ptr = my_malloc(n);
        if (ptr) {
            printf("Allocated %d bytes at %p\n", n, ptr);
            my_free(ptr);
            printf("Memory freed.\n");
        } else {
            printf("Allocation failed.\n");
        }
    } else {
        printf("Unknown command: %s (type 'help' for help)\n", input);
    }
}
