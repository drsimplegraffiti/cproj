#include <float.h>  // Floating point limits
#include <limits.h> // Integer limits
#include <stdint.h> // Fixed-width integers
#include <stdio.h>

int main() {

  /*
  ========================================================
  1) FLOATING POINT TYPES
  ========================================================
  */

  // float: usually 4 bytes, ~6-7 decimal digits precision
  float f1 = 3.1415926f;
  printf("float value: %f\n", f1);
  printf("FLT_MAX: %e\n", FLT_MAX);         // Maximum float value
  printf("FLT_MIN: %e\n", FLT_MIN);         // Minimum positive float
  printf("FLT_EPSILON: %e\n", FLT_EPSILON); // Smallest difference

  // double: usually 8 bytes, ~15-16 decimal digits precision
  double d1 = 3.141592653589793;
  printf("double value: %lf\n", d1);
  printf("DBL_MAX: %e\n", DBL_MAX);         // Maximum double
  printf("DBL_MIN: %e\n", DBL_MIN);         // Minimum positive double
  printf("DBL_EPSILON: %e\n", DBL_EPSILON); // Smallest difference

  // long double: extended precision (platform dependent)
  long double ld1 = 3.141592653589793238L;
  printf("long double value: %Lf\n", ld1);
  printf("LDBL_MAX: %Le\n", LDBL_MAX);
  printf("LDBL_MIN: %Le\n", LDBL_MIN);

  /*
  ========================================================
  2) INTEGER TYPES AND FIXED-WIDTH INTEGERS
  ========================================================
  */

  // Regular integers
  int i = 1000;
  long l = 100000L;
  long long ll = 10000000000LL;

  unsigned int ui = 4000000000U;   // unsigned int
  unsigned long ul = 1000000000UL; // unsigned long

  printf("\nint: %d\n", i);
  printf("long: %ld\n", l);
  printf("long long: %lld\n", ll);
  printf("unsigned int: %u\n", ui);
  printf("unsigned long: %lu\n", ul);

  // Fixed-width integers
  // // Fixed-width integers = exact size guaranteed (portable across systems)
  int8_t a = -120;              // 8-bit signed
  uint8_t b = 250;              // 8-bit unsigned
  int16_t c = -32000;           // 16-bit signed
  uint16_t d = 60000;           // 16-bit unsigned
  int32_t e = -2000000000;      // 32-bit signed
  uint32_t f = 4000000000U;     // 32-bit unsigned
  int64_t g = -900000000000LL;  // 64-bit signed
  uint64_t h = 180000000000ULL; // 64-bit unsigned
                                // intN_t → signed integer with exactly N bits

  // uintN_t → unsigned integer with exactly N bits
  // Found in <stdint.h>
  // Used when size matters (networking, file formats, embedded systems)
  // Suffixes:
  // U → unsigned
  // LL → long long
  // ULL → unsigned long long

  printf("\nint8_t: %d\n", a);
  printf("uint8_t: %u\n", b);
  printf("int16_t: %d\n", c);
  printf("uint16_t: %u\n", d);
  printf("int32_t: %d\n", e);
  printf("uint32_t: %u\n", f);
  printf("int64_t: %lld\n", g);
  printf("uint64_t: %llu\n", h);

  /*
  ========================================================
  3) SIZE OF TYPES
  ========================================================
  */

  printf("\nSizes in bytes:\n");
  printf("float: %zu\n", sizeof(float));
  printf("double: %zu\n", sizeof(double));
  printf("long double: %zu\n", sizeof(long double));
  printf("int: %zu\n", sizeof(int));
  printf("long: %zu\n", sizeof(long));
  printf("long long: %zu\n", sizeof(long long));
  printf("int8_t: %zu\n", sizeof(int8_t));
  printf("int16_t: %zu\n", sizeof(int16_t));
  printf("int32_t: %zu\n", sizeof(int32_t));
  printf("int64_t: %zu\n", sizeof(int64_t));

  /*
  ========================================================
  NOTES:
  ========================================================
  - FLT_MAX, DBL_MAX, LDBL_MAX: largest positive values
  - FLT_MIN, DBL_MIN, LDBL_MIN: smallest positive values
  - FLT_EPSILON, DBL_EPSILON: smallest difference between 1 and next value
  - Fixed-width integers guarantee the exact number of bits
  - sizeof() gives the size of each type in bytes
  ========================================================
  */

  return 0;
}
