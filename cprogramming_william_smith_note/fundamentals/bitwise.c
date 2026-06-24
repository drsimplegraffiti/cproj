#include <stdio.h>

int main() {
  /*  ==========================================================
    3.2 BIT MANIPULATION TECHNIQUES – COMPLETE EXAM SUMMARY
    ==========================================================

    Bit manipulation works directly on the binary representation
    of integers (bits: 0 and 1). It is fast and memory-efficient.
    Common in:
       - Systems programming
       - Embedded systems
       - Device drivers
       - Performance-critical code

    ----------------------------------------------------------
    BINARY BASICS
    ----------------------------------------------------------
    - Each bit represents a power of 2.
    - Rightmost bit = Least Significant Bit (LSB) = 2^0
    - Leftmost bit  = Most Significant Bit (MSB)
    - Most systems use Two's Complement for signed integers.
    */

  /*

  ----------------------------------------------------------
  BITWISE OPERATORS IN C
  ----------------------------------------------------------

  1) Bitwise AND (&)
     - Compares each corresponding bit.
     - Result bit = 1 only if BOTH bits are 1.
     - Used for: clearing bits, masking.
     Example:
       1100
     & 1101
     -------
       1100  (12)

  2) Bitwise OR (|)
     - Result bit = 1 if ANY bit is 1.
     - Used for: setting bits.
     Example:
       1100
     | 1101
     -------
       1101  (13)

  3) Bitwise XOR (^)
     - Result bit = 1 if bits are DIFFERENT.
     - Used for: toggling bits.
     Example:
       1100
     ^ 1101
     -------
       0001  (1)

  4) Bitwise NOT (~)
     - Flips every bit (1→0, 0→1).
     - In signed integers (two's complement),
       ~x = -(x + 1)
     Example:
       ~12 = -13 (in 32-bit system)

  ----------------------------------------------------------
  SHIFT OPERATORS
  ----------------------------------------------------------

  5) Left Shift (<<)
     - Shifts bits left.
     - Fills zeros from right.
     - Equivalent to multiplying by 2^n.
     Example:
       3 << 2 → 12

  6) Right Shift (>>)
     - Shifts bits right.
     - Unsigned: fills 0 from left.
     - Signed: fills sign bit.
     - Equivalent to dividing by 2^n.

  ----------------------------------------------------------
  COMMON BIT TECHNIQUES
  ----------------------------------------------------------

  Set a bit:
      x = x | (1 << n);

  Clear a bit:
      x = x & ~(1 << n);

  Toggle a bit:
      x = x ^ (1 << n);

  Check a bit:
      if (x & (1 << n))

  ==========================================================
  */

  // ------------------------------
  // 1. Multiplication by powers of two using left shift (<<)
  // ------------------------------
  int x = 5;         // Binary: 00000101
  int mult = x << 3; // Shift left 3 positions -> multiply by 2^3 = 8
  printf("Multiplication: %d << 3 = %d\n", x, mult); // Output: 40

  // ------------------------------
  // 2. Division by powers of two using right shift (>>)
  // ------------------------------
  int y = 16;       // Binary: 00010000
  int div = y >> 2; // Shift right 2 positions -> divide by 2^2 = 4
  printf("Division: %d >> 2 = %d\n", y, div); // Output: 4

  // ------------------------------
  // 3. Addition of powers of two using bitwise OR (|)
  // ------------------------------
  int a = 10;      // Binary: 00001010
  int add = a | 4; // 4 is 2^2 -> 00000100, OR sets the 3rd bit
  // 00001010 | 00000100 = 00001110 -> decimal 14
  printf("Addition by OR: %d | 4 = %d\n", a, add); // Output: 14

  // ------------------------------
  // 4. Subtraction / Toggling using bitwise XOR (^)
  // ------------------------------
  int b = 15;      // Binary: 00001111
  int sub = b ^ 8; // 8 is 2^3 -> 00001000, XOR toggles the 4th bit
  // 00001111 ^ 00001000 = 00000111 -> decimal 7
  printf("Subtraction by XOR: %d ^ 8 = %d\n", b, sub); // Output: 7

  return 0;
}
