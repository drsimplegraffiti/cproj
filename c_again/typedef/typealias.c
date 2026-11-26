#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

/*
 * SIGNED INTEGER TYPES
 *
 * i8  = 8-bit signed integer
 * i16 = 16-bit signed integer
 * i32 = 32-bit signed integer
 * i64 = 64-bit signed integer
 */

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

/*
 * UNSIGNED INTEGER TYPES
 *
 * u8  = 8-bit unsigned integer
 * u16 = 16-bit unsigned integer
 * u32 = 32-bit unsigned integer
 * u64 = 64-bit unsigned integer
 */

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

/*
 * FLOATING-POINT TYPES
 */

typedef float f32;
typedef double f64;

/*
 * BOOLEAN TYPE
 */

typedef bool boolean;

/*
 * SIZE AND POINTER DIFFERENCE TYPES
 */

typedef size_t usize;
typedef ptrdiff_t isize;

/*
 * CHARACTER TYPES
 */

typedef char c8;
typedef unsigned char byte;

/*
 * CONSTANTS
 */

#define TRUE true
#define FALSE false

int main(void) {

    /* Signed integers */
    i8 small_number = -100;
    i16 medium_number = -30000;
    i32 number = -200000;
    i64 large_number = -9000000000LL;

    /* Unsigned integers */
    u8 small_unsigned = 255;
    u16 medium_unsigned = 60000;
    u32 unsigned_number = 4000000000U;
    u64 large_unsigned = 18000000000ULL;

    /* Floating-point numbers */
    f32 price = 19.99f;
    f64 balance = 150000.75;

    /* Boolean */
    boolean is_active = TRUE;

    /* Size and pointer difference */
    usize array_size = 10;
    isize difference = -5;

    /* Character and byte */
    c8 letter = 'A';
    byte raw_byte = 255;

    printf("===== SIGNED INTEGERS =====\n");
    printf("i8:  %d\n", small_number);
    printf("i16: %d\n", medium_number);
    printf("i32: %d\n", number);
    printf("i64: %lld\n", (long long)large_number);

    printf("\n===== UNSIGNED INTEGERS =====\n");
    printf("u8:  %u\n", (unsigned)small_unsigned);
    printf("u16: %u\n", (unsigned)medium_unsigned);
    printf("u32: %u\n", unsigned_number);
    printf("u64: %llu\n", (unsigned long long)large_unsigned);

    printf("\n===== FLOATING POINT =====\n");
    printf("f32: %.2f\n", price);
    printf("f64: %.2f\n", balance);

    printf("\n===== BOOLEAN =====\n");
    printf("Active: %s\n", is_active ? "true" : "false");

    printf("\n===== SIZE AND POINTER =====\n");
    printf("usize: %zu\n", array_size);
    printf("isize: %td\n", difference);

    printf("\n===== CHARACTER AND BYTE =====\n");
    printf("Character: %c\n", letter);
    printf("Byte: %u\n", (unsigned)raw_byte);

    return 0;
}
