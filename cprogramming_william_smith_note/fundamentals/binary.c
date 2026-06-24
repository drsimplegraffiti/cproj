#include <stdio.h>

/*
    NUMBER SYSTEM CONVERSIONS
    -------------------------
    Binary  : Base-2  (digits: 0,1)
    Decimal : Base-10 (digits: 0-9)
    Hex     : Base-16 (digits: 0-9, A-F)

    Decimal → Binary:
        Repeated division by 2.
        Store remainders and print in reverse.

    Binary → Decimal:
        Multiply each digit by powers of 2.
        (Implemented using base multiplier method)

    Decimal → Hexadecimal:
        Repeated division by 16.
        Remainder 10-15 converted to A-F.

    Hexadecimal → Decimal:
        Multiply each digit by powers of 16.
*/

// Decimal to Binary
void decimalToBinary(int num) {
  int binary[32];
  int i = 0;

  if (num == 0) {
    printf("Binary: 0\n");
    return;
  }

  while (num > 0) {
    binary[i] = num % 2;
    num /= 2;
    i++;
  }

  printf("Binary: ");
  for (int j = i - 1; j >= 0; j--)
    printf("%d", binary[j]);

  printf("\n");
}

// Binary to Decimal
int binaryToDecimal(long long binary) {
  int decimal = 0;
  int base = 1;

  while (binary > 0) {
    int remainder = binary % 10;
    decimal += remainder * base;
    base *= 2;
    binary /= 10;
  }

  return decimal;
}

// Decimal to Hexadecimal
void decimalToHex(int num) {
  char hex[32];
  int i = 0;

  if (num == 0) {
    printf("Hexadecimal: 0\n");
    return;
  }

  while (num > 0) {
    int remainder = num % 16;

    if (remainder < 10)
      hex[i] = remainder + '0';
    else
      hex[i] = remainder - 10 + 'A';

    num /= 16;
    i++;
  }

  printf("Hexadecimal: ");
  for (int j = i - 1; j >= 0; j--)
    printf("%c", hex[j]);

  printf("\n");
}

// Hexadecimal to Decimal
int hexToDecimal(char hex[]) {
  int decimal = 0;
  int base = 1;
  int i = 0;

  // Find length
  while (hex[i] != '\0')
    i++;

  for (int j = i - 1; j >= 0; j--) {
    if (hex[j] >= '0' && hex[j] <= '9')
      decimal += (hex[j] - '0') * base;
    else if (hex[j] >= 'A' && hex[j] <= 'F')
      decimal += (hex[j] - 'A' + 10) * base;
    else if (hex[j] >= 'a' && hex[j] <= 'f')
      decimal += (hex[j] - 'a' + 10) * base;

    base *= 16;
  }

  return decimal;
}

int main() {
  int choice;
  int decimal;
  long long binary;
  char hex[32];

  printf("\nNumber System Conversion Menu\n");
  printf("1. Decimal to Binary\n");
  printf("2. Binary to Decimal\n");
  printf("3. Decimal to Hexadecimal\n");
  printf("4. Hexadecimal to Decimal\n");
  printf("Enter choice: ");
  scanf("%d", &choice);

  switch (choice) {

  case 1:
    printf("Enter decimal number: ");
    scanf("%d", &decimal);
    decimalToBinary(decimal);
    break;

  case 2:
    printf("Enter binary number: ");
    scanf("%lld", &binary);
    printf("Decimal: %d\n", binaryToDecimal(binary));
    break;

  case 3:
    printf("Enter decimal number: ");
    scanf("%d", &decimal);
    decimalToHex(decimal);
    break;

  case 4:
    printf("Enter hexadecimal number: ");
    scanf("%s", hex);
    printf("Decimal: %d\n", hexToDecimal(hex));
    break;

  default:
    printf("Invalid choice!\n");
  }

  return 0;
}
// gcc binary.c -o main -lm
// -lm → links the math library (libm) where pow() is defined.
