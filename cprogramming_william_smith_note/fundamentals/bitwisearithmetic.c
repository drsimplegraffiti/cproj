/*
==========================================================
3.3 BITWISE OPERATORS IN CERTAIN MATHEMATICAL OPERATIONS
====================== TL;DR =============================
==========================================================

Bitwise operators can replace some arithmetic operations
when working with powers of two. These are faster and
commonly used in low-level or performance-critical code.

----------------------------------------------------------
1) MULTIPLICATION BY POWERS OF TWO
----------------------------------------------------------

Operator: Left Shift (<<)

Rule:
    x << n   ≡   x * (2^n)

Explanation:
- Shifts bits to the left by n positions.
- Zeros are filled from the right.
- Each left shift doubles the number.
- Shifting by 2 → multiply by 4
- Shifting by 3 → multiply by 8

Example:
    int x = 5;      // 00000101
    x << 3;         // 00101000 (40)

Important Notes:
- Works for signed and unsigned integers.
- Be careful with overflow.
- If shifted too far, data may be lost.
- For signed integers, overflow causes undefined behavior.

----------------------------------------------------------
2) DIVISION BY POWERS OF TWO
----------------------------------------------------------

Operator: Right Shift (>>)

Rule:
    x >> n   ≡   x / (2^n)   (for positive numbers)

Explanation:
- Shifts bits to the right by n positions.
- Bits on the right are discarded.
- Each right shift halves the number.

Example:
    int x = 16;     // 00010000
    x >> 2;         // 00000100 (4)

Important Notes:
- Unsigned integers:
      Left side filled with 0s (logical shift).
- Signed integers:
      Sign bit may be copied (arithmetic shift).
- For negative numbers, result may differ from
  normal division depending on implementation.

----------------------------------------------------------
3) ADDITION OF A POWER OF TWO
----------------------------------------------------------

Operator: Bitwise OR (|)

Rule:
    x | y
    (Where y is a power of two: only ONE bit set)

Effect:
- Sets the bit corresponding to that power of two.
- Equivalent to adding y IF that bit was previously 0.

Example:
    int x = 10;     // 00001010
    int y = 4;      // 00000100 (2^2)
    x | y;          // 00001110 (14)

Important:
- This works correctly ONLY if:
      y has exactly one bit set.
- If that bit is already 1, value will NOT change.
- Not general addition — only safe for single-bit powers of two.

----------------------------------------------------------
4) SUBTRACTION OF A POWER OF TWO
----------------------------------------------------------

Operator: Bitwise XOR (^)

Rule:
    x ^ y
    (Where y is a power of two)

Effect:
- Toggles the bit corresponding to that power of two.
- If bit was 1 → becomes 0 (acts like subtraction).
- If bit was 0 → becomes 1 (acts like addition).

Example:
    int x = 15;     // 00001111
    int y = 8;      // 00001000 (2^3)
    x ^ y;          // 00000111 (7)

Important:
- Works as subtraction ONLY if that bit was 1.
- If bit was 0, it will ADD instead.
- Not general subtraction — only safe for single-bit powers of two.

----------------------------------------------------------
CRITICAL EXAM NOTES
----------------------------------------------------------

✔ These tricks only work properly when:
     - The number involved is a power of two
     - Only ONE bit is set in that number

✔ Bit shifting is generally faster than * or /
  in low-level systems.

✔ Prefer unsigned integers for heavy bit operations
  to avoid sign-extension problems.

✔ These techniques are optimizations, not replacements
  for normal arithmetic in general cases.

==========================================================
END OF 3.3 SUMMARY
==========================================================
*/
