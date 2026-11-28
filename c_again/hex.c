#include <stdio.h>

int main(void) {
    // If you lead a number with 0x, it is read as a hex number:
    int a = 0x1A2B; // Hexadecimal
    int b = 0x1a2b; // Case doesn't matter for hex digits

    printf("%x\n", a); // Print a hex number, "1a2b"

    // If you lead a number with a 0, it is read as an octal number:
    int aa = 012;
    printf("%o\n", aa); // Print an octal number, "12"

    // An unofficial extension104 in many C compilers allows you to represent a
    // binary number with a 0b prefix:
    int x = 0b101010; // Binary 101010

    printf("%d\n", x); // Prints 42 decimal

    return 0;
}
