

/*
 * usefulheaders.c
 *
 * A practical reference to useful C standard library headers.
 *
 * Compile:
 *     gcc -std=c23 -Wall -Wextra -Wpedantic usefulheaders.c -o usefulheaders
 *
 * Or use C17:
 *     gcc -std=c17 -Wall -Wextra -Wpedantic usefulheaders.c -o usefulheaders
 */

#include <assert.h>    // assert
#include <complex.h>   // double complex, creal, cimag, cabs
#include <ctype.h>     // isalpha, isdigit, isspace, toupper, tolower
#include <errno.h>     // errno, EINVAL, ERANGE
#include <fenv.h>      // feclearexcept, fetestexcept, FE_DIVBYZERO
#include <float.h>     // FLT_MAX, FLT_MIN, DBL_MAX, DBL_EPSILON
#include <inttypes.h>  // PRId32, PRIu64, SCNd32
#include <iso646.h>    // alternative operator tokens (C95)
#include <limits.h>    // INT_MAX, INT_MIN, CHAR_BIT, LONG_MAX
#include <locale.h>    // setlocale, localeconv
#include <math.h>      // sqrt, pow, sin, cos, floor, ceil, fabs
#include <setjmp.h>    // setjmp, longjmp
#include <signal.h>    // signal, raise, SIGINT, SIGTERM
#include <stdalign.h>  // alignas, alignof (C11)
#include <stdarg.h>    // va_list, va_start, va_arg, va_end
#include <stdatomic.h> // atomic_int, atomic_load, atomic_store (C11)
#include <stdbool.h>   // bool, true, false
#include <stddef.h>    // size_t, ptrdiff_t, NULL, offsetof
#include <stdint.h>    // int8_t, int16_t, int32_t, int64_t, uint32_t
#include <stdio.h>     // printf, scanf, fopen, fclose, fgets, fprintf, fread
#include <stdlib.h>    // malloc, calloc, realloc, free, exit, rand, qsort, atoi
#include <stdnoreturn.h> // noreturn (C11)
#include <string.h>  // strlen, strcpy, strncpy, strcmp, strcat, memcpy, memset
#include <threads.h> // thrd_create, thrd_join, mtx_lock (C11)
#include <time.h>    // time, clock, difftime, localtime, strftime
#include <uchar.h>   // char16_t, char32_t, mbrtoc16
#include <wchar.h>   // wchar_t, wprintf, wcslen, wcscpy
#include <wctype.h>  // iswalpha, towupper, towlower

/*
 * 1. stdio.h
 *
 * Standard input/output.
 *
 * printf()    - formatted output
 * scanf()     - formatted input
 * puts()      - print a string
 * getchar()   - read one character
 * putchar()   - output one character
 * fgets()     - read a line
 * fopen()     - open a file
 * fclose()    - close a file
 * fprintf()   - formatted file output
 * fscanf()    - formatted file input
 * fread()     - read binary data
 * fwrite()    - write binary data
 * fseek()     - move file position
 * ftell()     - get file position
 * rewind()    - reset file position
 * feof()      - check end-of-file indicator
 * perror()    - print error message
 *
 * 2. stdlib.h
 *
 * General utilities and memory management.
 *
 * malloc()    - allocate memory
 * calloc()    - allocate zero-initialized memory
 * realloc()   - resize allocated memory
 * free()      - release allocated memory
 * exit()      - terminate program
 * abort()     - abnormal termination
 * atexit()    - register exit handler
 * qsort()     - sort an array
 * bsearch()   - binary search
 * rand()      - generate pseudo-random number
 * srand()     - seed random generator
 * strtol()    - convert string to long
 * strtod()    - convert string to double
 * getenv()    - retrieve environment variable
 * system()    - execute a system command
 *
 * 3. string.h
 *
 * String and memory manipulation.
 *
 * strlen()    - string length
 * strcpy()    - copy string
 * strncpy()   - copy up to n characters
 * strcat()    - concatenate strings
 * strcmp()    - compare strings
 * strncmp()   - compare first n characters
 * strchr()    - find character
 * strstr()    - find substring
 * strtok()    - tokenize string
 * memcpy()    - copy memory (non-overlapping)
 * memmove()   - copy memory (overlapping allowed)
 * memset()    - fill memory
 * memcmp()    - compare memory
 *
 * 4. stdint.h
 *
 * Fixed-width integer types.
 *
 * int8_t      - signed 8-bit integer
 * int16_t     - signed 16-bit integer
 * int32_t     - signed 32-bit integer
 * int64_t     - signed 64-bit integer
 * uint8_t     - unsigned 8-bit integer
 * uint16_t    - unsigned 16-bit integer
 * uint32_t    - unsigned 32-bit integer
 * uint64_t    - unsigned 64-bit integer
 *
 * INT32_MAX, INT32_MIN, UINT64_MAX
 *
 * 5. inttypes.h
 *
 * Portable formatting and conversion for fixed-width integers.
 *
 * PRId32      - printf format for int32_t
 * PRIu64      - printf format for uint64_t
 * PRIx32      - hexadecimal format for uint32_t
 * SCNd32      - scanf format for int32_t
 *
 * 6. stdbool.h
 *
 * Boolean values (C99).
 *
 * bool
 * true
 * false
 *
 * 7. stddef.h
 *
 * Common definitions.
 *
 * size_t       - unsigned size type
 * ptrdiff_t    - pointer difference type
 * NULL         - null pointer constant
 * offsetof()   - member offset in a structure
 * max_align_t  - fundamental alignment type
 *
 * 8. limits.h
 *
 * Integer type limits.
 *
 * CHAR_BIT    - bits in a byte
 * CHAR_MAX    - maximum char value
 * INT_MAX     - maximum int
 * INT_MIN     - minimum int
 * LONG_MAX    - maximum long
 * LONG_MIN    - minimum long
 * SHRT_MAX    - maximum short
 * UCHAR_MAX   - maximum unsigned char
 *
 * 9. float.h
 *
 * Floating-point characteristics.
 *
 * FLT_MAX       - maximum float
 * FLT_MIN       - minimum positive normalized float
 * FLT_DIG       - decimal precision of float
 * FLT_EPSILON   - float precision near 1.0
 * DBL_MAX       - maximum double
 * DBL_MIN       - minimum positive normalized double
 * DBL_DIG       - decimal precision of double
 * DBL_EPSILON   - double precision near 1.0
 * LDBL_MAX      - maximum long double
 *
 * 10. math.h
 *
 * Mathematical operations.
 *
 * sqrt()      - square root
 * pow()       - exponentiation
 * sin()       - sine
 * cos()       - cosine
 * tan()       - tangent
 * log()       - natural logarithm
 * log10()     - base-10 logarithm
 * exp()       - exponential
 * floor()     - round down
 * ceil()      - round up
 * round()     - round to nearest
 * fabs()      - absolute floating-point value
 * fmod()      - floating-point remainder
 * hypot()     - hypotenuse
 * isnan()     - test for NaN
 * isinf()     - test for infinity
 *
 * 11. ctype.h
 *
 * Character classification and conversion.
 *
 * isalpha()   - alphabetic character?
 * isdigit()   - decimal digit?
 * isalnum()   - alphabetic or numeric?
 * isspace()   - whitespace?
 * islower()   - lowercase?
 * isupper()   - uppercase?
 * ispunct()   - punctuation?
 * isprint()   - printable?
 * isxdigit()  - hexadecimal digit?
 * tolower()   - convert to lowercase
 * toupper()   - convert to uppercase
 *
 * IMPORTANT: Pass EOF or a value representable as unsigned char
 * to the ctype classification and conversion functions.
 *
 * 12. errno.h
 *
 * Error reporting.
 *
 * errno       - error number
 * EINVAL      - invalid argument
 * ERANGE      - result out of range
 * ENOMEM      - insufficient memory
 * EDOM        - domain error
 *
 * 13. assert.h
 *
 * Runtime assertions.
 *
 * assert()    - verify a condition during development
 *
 * Example:
 * assert(ptr != NULL);
 *
 * Define NDEBUG before including assert.h to disable assertions.
 *
 * 14. time.h
 *
 * Date and time.
 *
 * time()      - current calendar time
 * clock()     - processor time
 * difftime()  - difference between times
 * localtime() - convert to local time
 * gmtime()    - convert to UTC
 * mktime()    - convert broken-down time to time_t
 * strftime()  - format date and time
 *
 * 15. stdarg.h
 *
 * Variadic functions.
 *
 * va_list     - argument list type
 * va_start()  - initialize argument traversal
 * va_arg()    - retrieve next argument
 * va_end()    - finish argument traversal
 * va_copy()   - copy argument traversal state
 *
 * 16. signal.h
 *
 * Signal handling.
 *
 * signal()    - register signal handler
 * raise()     - raise a signal
 * SIGINT      - interrupt signal
 * SIGTERM     - termination request
 * SIGABRT     - abnormal termination
 *
 * 17. setjmp.h
 *
 * Non-local jumps.
 *
 * setjmp()    - save execution environment
 * longjmp()   - jump back to saved environment
 *
 * 18. locale.h
 *
 * Localization.
 *
 * setlocale() - set program locale
 * localeconv()- retrieve locale formatting information
 *
 * 19. wchar.h
 *
 * Wide-character operations.
 *
 * wchar_t     - wide character type
 * wprintf()   - wide-character output
 * wcslen()    - wide string length
 * wcscpy()    - copy wide string
 * wcscmp()    - compare wide strings
 *
 * 20. wctype.h
 *
 * Wide-character classification.
 *
 * iswalpha()  - check wide alphabetic character
 * iswdigit()  - check wide digit
 * iswspace()  - check wide whitespace
 * towupper()  - convert to uppercase
 * towlower()  - convert to lowercase
 *
 * 21. complex.h
 *
 * Complex number arithmetic (C99).
 *
 * double complex - complex double type
 * creal()        - real component
 * cimag()        - imaginary component
 * cabs()         - magnitude
 * carg()         - phase angle
 * conj()         - complex conjugate
 *
 * 22. fenv.h
 *
 * Floating-point environment.
 *
 * feclearexcept() - clear floating-point exceptions
 * fetestexcept()  - test floating-point exceptions
 * feraiseexcept() - raise floating-point exceptions
 * FE_DIVBYZERO    - division by zero exception
 * FE_INVALID      - invalid operation exception
 * FE_OVERFLOW     - overflow exception
 *
 * 23. stdalign.h
 *
 * Alignment support (C11).
 *
 * alignas()    - specify alignment
 * alignof()    - query alignment
 *
 * 24. stdatomic.h
 *
 * Atomic operations (C11).
 *
 * atomic_int
 * atomic_load()
 * atomic_store()
 * atomic_fetch_add()
 * atomic_exchange()
 * atomic_compare_exchange_strong()
 *
 * 25. threads.h
 *
 * Standard C threading (C11, optional implementation support).
 *
 * thrd_create() - create thread
 * thrd_join()   - wait for thread
 * thrd_exit()   - terminate thread
 * mtx_init()    - initialize mutex
 * mtx_lock()    - lock mutex
 * mtx_unlock()  - unlock mutex
 * cnd_wait()    - wait on condition variable
 *
 * 26. uchar.h
 *
 * Unicode character types and conversions (C11).
 *
 * char16_t
 * char32_t
 * mbrtoc16()
 * c16rtomb()
 * mbrtoc32()
 * c32rtomb()
 *
 * 27. iso646.h
 *
 * Alternative operator spellings (C95).
 *
 * and       - &&
 * or        - ||
 * not       - !
 * bitand    - &
 * bitor     - |
 * xor       - ^
 * compl     - ~
 *
 * 28. stdnoreturn.h
 *
 * C11 non-returning function support.
 *
 * noreturn
 *
 * Note: These C11 compatibility headers may be deprecated
 * in C23. Check the standard version when using them.
 */

int main(void) {
    puts("C Standard Library Header Reference");
    puts("See comments in this file for the complete reference.");

    return EXIT_SUCCESS;
}
