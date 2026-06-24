#include <stdio.h>

int main() {
  // ---------------- NUMERAL SYSTEMS ----------------
  int decimal = 13; // Decimal number

  // Decimal to Binary (manual method)
  // Repeated division by 2
  int n = decimal;
  int binary[8]; // store up to 8 bits
  int i = 0;
  while (n > 0) {
    binary[i++] = n % 2; // remainder
    n = n / 2;           // quotient
  }
  printf("Decimal %d in binary: ", decimal);
  for (int j = i - 1; j >= 0; j--) {
    printf("%d", binary[j]); // print remainders in reverse
  }
  printf("\n");

  // Binary to Decimal (example binary 1011)
  int binNum = 1011; // binary as decimal digits
  int decValue = 0;
  int power = 1;
  while (binNum > 0) {
    decValue += (binNum % 10) * power; // multiply bit by 2^position
    binNum /= 10;
    power *= 2;
  }
  printf("Binary 1011 in decimal: %d\n", decValue);

  // Decimal to Hexadecimal
  int dec2hex = 255;
  char hex[10];
  sprintf(hex, "%X", dec2hex); // %X converts decimal to uppercase hex
  printf("Decimal %d in Hexadecimal: %s\n", dec2hex, hex);

  // Hexadecimal to Decimal
  char hexNum[] = "AF"; // Hex string
  int decFromHex;
  sscanf(hexNum, "%X", &decFromHex); // convert hex string to decimal
  printf("Hexadecimal %s in Decimal: %d\n", hexNum, decFromHex);

  // ---------------- BITWISE OPERATIONS ----------------
  int a = 12; // 1100 in binary
  int b = 13; // 1101 in binary

  int andRes = a & b; // Bitwise AND -> 1100 -> 12
  int orRes = a | b;  // Bitwise OR  -> 1101 -> 13
  int xorRes = a ^ b; // Bitwise XOR -> 0001 -> 1
  int notA = ~a;      // Bitwise NOT -> flips bits (2's complement -> -13)

  printf("a & b = %d\n", andRes);
  printf("a | b = %d\n", orRes);
  printf("a ^ b = %d\n", xorRes);
  printf("~a = %d\n", notA);

  // Left shift and Right shift
  int leftShift = 3 << 2;   // 00000011 << 2 -> 00001100 -> 12
  int rightShift = 12 >> 2; // 00001100 >> 2 -> 00000011 -> 3
  printf("3 << 2 = %d\n", leftShift);
  printf("12 >> 2 = %d\n", rightShift);

  // Setting, Clearing, and Toggling bits
  unsigned int x = 9; // 00001001
  x = x | (1 << 1);   // Set 2nd bit -> 00001011
  printf("After setting 2nd bit: %u\n", x);

  x = x & ~(1 << 3); // Clear 4th bit -> 00000011
  printf("After clearing 4th bit: %u\n", x);

  x = x ^ (1 << 0); // Toggle 1st bit -> 00000010
  printf("After toggling 1st bit: %u\n", x);

  return 0;
}
