
#include <stdio.h>

int main(void) {
    /* Computers store every number as bits (0s and 1s).
     *
     * a = 6  -> binary 0110   (sometimes written 0b110)
     * b = 3  -> binary 0011   (sometimes written 0b11)
     *
     * Bit positions:  bit3  bit2  bit1  bit0   (values 8, 4, 2, 1)
     */
    unsigned int a = 6; // binary 0110
    unsigned int b = 3; // binary 0011

    /* -------------------------------------------------------------
     *  a & b (AND) -> 2
     *  Outputs 1 only where BOTH bits are 1.
     *
     *       bit3  bit2  bit1  bit0   (values 8, 4, 2, 1)
     *   a   0     1     1     0      (= 6)
     *   b   0     0     1     1      (= 3)
     *   ----  -----  -----  -----  -----
     *   &   0     0     1     0      (= 2)
     *
     *   Only bit1 is 1 in both a and b, and bit1 has value 2.
     *   Result: 0010 binary = 2 decimal.
     * ------------------------------------------------------------- */
    printf("a & b = %u\n", a & b); /* prints 2 */

    /* -------------------------------------------------------------
     *  a | b (OR) -> 7
     *  Outputs 1 where EITHER bit is 1.
     *
     *       bit3  bit2  bit1  bit0   (values 8, 4, 2, 1)
     *   a   0     1     1     0      (= 6)
     *   b   0     0     1     1      (= 3)
     *   ----  -----  -----  -----  -----
     *   |   0     1     1     1      (= 7)
     *
     *   Result: 0111 binary = 4 + 2 + 1 = 7 decimal.
     * ------------------------------------------------------------- */
    printf("a | b = %u\n", a | b); /* prints 7 */

    /* -------------------------------------------------------------
     *  a << 1 (shift left) -> 12
     *  Moves every bit one place to the left, fills the right with 0.
     *
     *       bit3  bit2  bit1  bit0   (values 8, 4, 2, 1)
     *   a   0     1     1     0      (= 6)
     *   << 1
     *   ----  -----  -----  -----  -----
     *       1     1     0     0      (= 12)
     *
     *   Old bit2 (value 4) moves to bit3 (value 8).
     *   Old bit1 (value 2) moves to bit2 (value 4).
     *   New bit0 is filled with 0.
     *   Result: 1100 binary = 8 + 4 = 12 decimal.  (Same as 6 * 2.)
     * ------------------------------------------------------------- */
    printf("a << 1 = %u\n", a << 1); /* prints 12 */

    /* -------------------------------------------------------------
     *  b >> 1 (shift right) -> 1
     *  Moves every bit one place to the right, fills the left with 0.
     *
     *       bit3  bit2  bit1  bit0   (values 8, 4, 2, 1)
     *   b   0     0     1     1      (= 3)
     *   >> 1
     *   ----  -----  -----  -----  -----
     *       0     0     0     1      (= 1)
     *
     *   Old bit1 (value 2) moves to bit0 (value 1).
     *   Old bit0 (value 1) falls off the end.
     *   New bit3 is filled with 0.
     *   Result: 0001 binary = 1 decimal.  (Same as 3 / 2 in integer math.)
     * ------------------------------------------------------------- */
    printf("b >> 1 = %u\n", b >> 1); /* prints 1 */

    return 0;
}
