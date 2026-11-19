#include "math_util.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* fixed width */
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint8_t u8;
typedef uint16_t u16;

typedef float f32;
typedef double f64;

typedef i8 b8;
typedef i32 b32;

typedef struct {
    f32 x;
    f32 y;
} vec2f;

/* string8 = a custom string type that stores a pointer to the string + its
 * length. */
typedef struct {
    u8 *str;  // Pointer to string data
    u64 size; // String length in bytes
} string8;

// preprocessor
#define PI 3.14
#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) ((a) < (b) ? (a) : (b))

#define KiB(n) ((u64)(n) << 10)
#define MiB(n) ((u64)(n) << 20)
#define GiB(n) ((u64)(n) << 30)

int main() {

    string8 name = {.str = (u8 *)"Yomi", .size = 4};
    printf("Name: %.*s\n", (int)name.size, name.str);
    printf("Size: %lu bytes\n", (unsigned long)name.size);

    hello("james");

    int16_t s16 = 128;
    printf("size si is %d\n", s16);

    i8 tall = 1;
    printf("is tall?: %d\n", tall);

    vec2f v = {0.1, 0.2};
    printf("%f %f\n", v.x, v.y);

    vec2f v2 = {.y = 1.3, .x = 9.1}; // designated initializer
    printf("%f %f\n", v2.x, v2.y);

    printf("2 + 2 is %d\n", 4);

    // pointer
    i32 num = 9;
    i32 *ptr = &num;
    printf("val is %d and pointer is %p\n", num, (void *)ptr);

    *ptr = 89; // dereferecing
    printf("new num is %d\n", *ptr);

    // void pointer
    /* void *vptr = NULL; */

    vec2f *pv = &v;
    (*pv).x = 90;
    (*pv).y = 80;
    printf("ACCESS %f\n", pv->x);
    printf("ACCESS %f\n", pv->y);

    pv->x = 18; // shortcut. dereferecing and accessing it
    pv->y = 19;

    printf("ACCESS %f\n", pv->x);
    printf("ACCESS %f\n", pv->y);

    // arrays
    int nums[] = {2, 3, 4, 5};
    for (u32 i = 0; i < 3; i++) {
        printf(" %d", nums[i]);
    }
    printf("\n");
    *nums = 6; // arrays decays to a pointer, this changes the first value of
               // the array

    for (u32 i = 0; i < 3; i++) {
        printf(" %d", nums[i]);
    }

    printf("\n");

    // pointer arithmetic
    *(nums + 1) = 2; // we are moving the cycle up by one
    *(nums + 2) = 12;

    for (u32 i = 0; i < 3; i++) {
        printf(" %d", nums[i]);

        /* printf(" %d", *(nums + i)); */ // same as above
    }
    printf("\n");

    u32 num_vectors = 10;
    vec2f *vectors = (vec2f *)malloc(sizeof(vec2f) * num_vectors);

    for (u32 i = 0; i < num_vectors; i++) {
        vectors[i].x = i * 1;
        vectors[i].y = i * 2;

        printf("vec %f\n", vectors[i].x);
    }

    free(vectors);

    i32 sum = add(2, 3);
    printf("sum is %d\n", sum);

    printf("PI Is %f\n", PI);

    i32 rr = MIN(1, 4);
    printf("respnd : %d\n", rr);

    printf("%ld\n", KiB(2));
    return 0;
}

// gcc sandbox.c -g -Wall -Wextra -Werror  -std=c2x -fsanitize=address,undefined
// -pedantic -o main && ./main
//
// Compile differently
// gcc -c sandbox.c
// gcc -c math_util.c
// gcc sandbox.o math_util.o -o main
// ./main
//
// The correct order matters too in the // gcc sandbox.o math_util.o -o main
