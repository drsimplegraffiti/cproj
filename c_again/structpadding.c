#include <stdio.h>

struct Example {
  char a; // 1 byte
  int b;  // 4 bytes
  char c; // 1 byte
};

// Reduce padding
/* Padding depends on the order of members in the struct. If you group larger
 * types first, you can make the struct smaller: */
struct Example2 {
  int b;  // 4 bytes
  char a; // 1 byte
  char c; // 1 byte
};

int main() {
  printf("Size of struct: %zu bytes\n", sizeof(struct Example));  // 12 bytes
  printf("Size of struct: %zu bytes\n", sizeof(struct Example2)); // 8 bytes
  return 0;
}

/* You might expect the size to be 1 + 4 + 1 = 6 bytes - but it will usually
 * print 12 bytes! */
/* The compiler adds padding bytes so that the int member (b) starts at a memory
 * address that's a */
/* multiple of 4. This helps the CPU read it faster. */

/* | Member    | Bytes | Notes                                    | */
/* |-----------|-------|------------------------------------------| */
/* | a         | 1     | Stored first                            | */
/* | *padding* | 3     | Added so `b` starts at a multiple of 4   | */
/* | b         | 4     | Aligned to 4-byte boundary               | */
/* | c         | 1     | Stored next                              | */
/* | *padding* | 3     | Added to make total size a multiple of 4 | */

/* Total = 1 + 3 + 4 + 1 + 3 = **12 bytes**. */
