/*
 * Chapter 1 - Why C Still Matters
 * Project: Hello from Bare Metal
 *
 * Prints "Hello, World!" using the write() system call directly,
 * bypassing stdio/printf. Shows how a program talks to the OS kernel
 * through file descriptors rather than high-level library functions.
 */

#include <unistd.h>   /* write() POSIX system call */

int main(void) {
    const char msg[] = "Hello, World!\n";
    /* write to stdout (file descriptor 1), length minus the null terminator */
    write(1, msg, sizeof(msg) - 1);
    return 0;
}
