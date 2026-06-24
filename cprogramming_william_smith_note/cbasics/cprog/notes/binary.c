// Read and Write in a Binary File
//
// Till now, we have only discussed text file operations. The operations on a
// binary file are similar to text file operations with little difference.
// Opening a Binary File
//
// To open a file in binary mode, we use the rb, rb+, ab, ab+, wb, and wb+
// access mode in the fopen() function. We also use the .bin file extension in
// the binary filename.
//
// Example:
#include <stdio.h>
#include <stdlib.h>

struct threeNum {
  int n1, n2, n3;
};

int main() {
  int n = 1;

  // Structure variable declared.
  struct threeNum num;
  FILE *fptr;
  fptr = fopen("binaryFile.bin", "wb");
  int flag = 0;
  num.n1 = n;
  num.n2 = 5 * n;
  num.n3 = 5 * n + 1;

  // Write the Structure data
  // to binary file.
  flag = fwrite(&num, sizeof(struct threeNum), 1, fptr);

  // Checking if the data is written.
  if (!flag)
    printf("Write Operation Failure");
  else
    printf("Write Operation Successful");
  fclose(fptr);
  return 0;
}

// Reading from Binary File
//
// The fread() function can be used to read data from a binary file in C. The
// data is read from the file in the same form as it is stored i.e. binary form.
// #include <stdio.h>
// #include <stdlib.h>
//
// // Structure that store
// // binary file data
// struct threeNum {
//     int n1, n2, n3;
// };
//
// int main() {
//     int n;
//     struct threeNum num;
//     FILE* fptr;
//     fptr = fopen("binaryFile.bin", "rb");
//
//     // Read the data from binary
//     // file and print that data
//     fread(&num, sizeof(struct threeNum), 1, fptr);
//     printf("n1: %d\tn2: %d\tn3: %d\n", num.n1, num.n2,
//            num.n3);
//     fclose(fptr);
//     return 0;
// }
