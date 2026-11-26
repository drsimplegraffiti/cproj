
/*
 * STRUCT PADDING IN C
 *
 * Struct padding is the extra unused memory the compiler adds between
 * structure members or at the end of a structure to satisfy memory
 * alignment requirements.
 */

#include <stddef.h>
#include <stdio.h>

/*
 * EXAMPLE 1: WITHOUT PADDING
 *
 * Each char occupies 1 byte.
 * Three chars = 3 bytes.
 *
 * Memory layout:
 *
 * | a | b | c |
 * | 1 | 1 | 1 |
 *
 * Total: 3 bytes.
 */

struct Data {
    char a;
    char b;
    char c;
};

/*
 * EXAMPLE 2: WITH PADDING
 *
 * On a typical system, int requires 4-byte alignment.
 *
 * Memory layout:
 *
 * | a | P | P | P | b | b | b | b | c | P | P | P |
 *
 * a = 1 byte
 * P = Padding
 * b = 4 bytes
 * c = 1 byte
 *
 * Total: 12 bytes.
 *
 * 3 bytes of padding before int b.
 * 3 bytes of padding at the end.
 */

struct DataWithPadding {
    char a;
    int b;
    char c;
};

/*
 * EXAMPLE 3: REDUCING PADDING
 *
 * We can reduce padding by rearranging structure members.
 *
 * Put members with larger alignment requirements first.
 *
 * Memory layout:
 *
 * | b | b | b | b | a | c | P | P |
 *
 * b = 4 bytes
 * a = 1 byte
 * c = 1 byte
 * P = Padding
 *
 * Total: 8 bytes.
 */

struct OptimizedData {
    int b;
    char a;
    char c;
};

/*
 * EXAMPLE 4: DIFFERENT DATA TYPES
 *
 * double commonly requires 8-byte alignment.
 * int commonly requires 4-byte alignment.
 * char requires 1-byte alignment.
 */

struct Person {
    char name;
    double salary;
    int age;
    char gender;
};

/*
 * EXAMPLE 5: OPTIMIZED PERSON STRUCTURE
 *
 * Rearranging members can reduce padding.
 */

struct OptimizedPerson {
    double salary;
    int age;
    char name;
    char gender;
};

/*
 * HOW TO INSPECT STRUCTURE MEMORY
 *
 * sizeof()
 * Returns the total size of a structure, including padding.
 *
 * offsetof()
 * Returns the byte offset of a particular member.
 *
 * _Alignof()
 * Returns the alignment requirement of a type (C11).
 */

int main(void) {

    struct Data d1;
    struct DataWithPadding d2;
    struct OptimizedData d3;
    struct Person p1;
    struct OptimizedPerson p2;

    /* Example 1 */
    printf("\n===== EXAMPLE 1: NO PADDING =====\n");

    printf("Size: %zu bytes\n", sizeof(d1));

    /* Example 2 */
    printf("\n===== EXAMPLE 2: WITH PADDING =====\n");

    printf("Size: %zu bytes\n", sizeof(d2));

    printf("Offset of a: %zu\n", offsetof(struct DataWithPadding, a));
    printf("Offset of b: %zu\n", offsetof(struct DataWithPadding, b));
    printf("Offset of c: %zu\n", offsetof(struct DataWithPadding, c));

    /* Example 3 */
    printf("\n===== EXAMPLE 3: OPTIMIZED STRUCT =====\n");

    printf("Size: %zu bytes\n", sizeof(d3));

    printf("Offset of b: %zu\n", offsetof(struct OptimizedData, b));
    printf("Offset of a: %zu\n", offsetof(struct OptimizedData, a));
    printf("Offset of c: %zu\n", offsetof(struct OptimizedData, c));

    /* Example 4 */
    printf("\n===== EXAMPLE 4: PERSON STRUCT =====\n");

    printf("Size: %zu bytes\n", sizeof(p1));

    printf("Offset of name: %zu\n", offsetof(struct Person, name));
    printf("Offset of salary: %zu\n", offsetof(struct Person, salary));
    printf("Offset of age: %zu\n", offsetof(struct Person, age));
    printf("Offset of gender: %zu\n", offsetof(struct Person, gender));

    /* Example 5 */
    printf("\n===== EXAMPLE 5: OPTIMIZED PERSON =====\n");

    printf("Size: %zu bytes\n", sizeof(p2));

    printf("Offset of salary: %zu\n", offsetof(struct OptimizedPerson, salary));
    printf("Offset of age: %zu\n", offsetof(struct OptimizedPerson, age));
    printf("Offset of name: %zu\n", offsetof(struct OptimizedPerson, name));
    printf("Offset of gender: %zu\n", offsetof(struct OptimizedPerson, gender));

    /*
     * CHECK STRUCTURE ALIGNMENT
     *
     * _Alignof() is available in C11 and later.
     */

    printf("\n===== STRUCT ALIGNMENT =====\n");

    printf("Data alignment: %zu\n", _Alignof(struct Data));
    printf("DataWithPadding alignment: %zu\n",
           _Alignof(struct DataWithPadding));
    printf("OptimizedData alignment: %zu\n", _Alignof(struct OptimizedData));

    return 0;
}

/*
 * IMPORTANT NOTES:
 *
 * 1. Padding is automatically added by the compiler.
 *
 * 2. sizeof() includes both internal and trailing padding.
 *
 * 3. Rearranging structure members can reduce padding.
 *
 * 4. offsetof() helps inspect where each member is stored.
 *
 * 5. _Alignof() tells you the alignment requirement.
 *
 * 6. Actual structure sizes depend on the compiler and platform.
 *
 * 7. Avoid manually removing padding using packed structures unless
 *    you have a specific reason. Unaligned memory access can affect
 *    performance and portability.
 *
 * COMPILE:
 *
 * gcc -Wall -Wextra -Werror -std=c11 main.c -o main
 *
 * RUN:
 *
 * ./main
 */
