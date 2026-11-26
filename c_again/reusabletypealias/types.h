#ifndef TYPES_H
#define TYPES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*
 * SIGNED INTEGER TYPES
 */
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

/*
 * UNSIGNED INTEGER TYPES
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
 * BOOLEAN
 */
typedef bool boolean;

/*
 * SIZE AND POINTER TYPES
 */
typedef size_t usize;
typedef ptrdiff_t isize;

/*
 * CHARACTER AND BYTE TYPES
 */
typedef char c8;
typedef unsigned char byte;

#endif /* TYPES_H */
