# 8. Bitwise Operations, Bit Fields, Binary Files & Basic Algorithms

## 8.1 Bitwise Operators
| Operator | Name | Example | Result |
|---|---|---|---|
| `&` | AND | `5 & 3` | `1` (0101 & 0011 = 0001) |
| `\|` | OR | `5 \| 3` | `7` (0101 \| 0011 = 0111) |
| `^` | XOR | `5 ^ 3` | `6` (0101 ^ 0011 = 0110) |
| `~` | NOT (complement) | `~5` | `-6` (flips all bits) |
| `<<` | Left shift | `5 << 1` | `10` (multiply by 2 per shift) |
| `>>` | Right shift | `5 >> 1` | `2` (divide by 2 per shift, for unsigned/positive) |

**Note:** shifting negative numbers right is implementation-defined (arithmetic vs
logical shift) — be cautious; prefer unsigned types when doing bit manipulation.

## 8.2 Common Bit-Manipulation Idioms
```c
// Set bit n
x |= (1 << n);

// Clear bit n
x &= ~(1 << n);

// Toggle bit n
x ^= (1 << n);

// Check bit n
if (x & (1 << n)) { /* bit is set */ }

// Extract lowest set bit
int lowest = x & (-x);

// Count set bits (Brian Kernighan's algorithm)
int count = 0;
while (x) {
    x &= (x - 1);   // clears the lowest set bit each iteration
    count++;
}

// Swap two variables without a temp (XOR swap — clever but rarely necessary)
a ^= b;
b ^= a;
a ^= b;
```

## 8.3 Bit Fields in Structs
Bit fields let you specify the exact number of bits a struct member occupies,
useful for packing flags/small values tightly (e.g., hardware registers, protocol
headers, memory-constrained data).

```c
struct Flags {
    unsigned int isActive : 1;   // 1 bit  (0 or 1)
    unsigned int isAdmin  : 1;   // 1 bit
    unsigned int level    : 4;   // 4 bits (0-15)
    unsigned int reserved : 2;   // 2 bits, unused padding
};   // total: 8 bits, likely packed into 1 byte of storage (compiler-dependent)
```

**Caveats:**
- The exact memory layout (order of bits, padding, whether fields cross byte
  boundaries) is **implementation-defined** — not portable across compilers/platforms.
- You cannot take the address of a bit field (`&flags.isActive` is illegal).
- Best used for internal packing where portability across systems doesn't matter, or
  when explicitly matching a known hardware/protocol layout (in which case, combine
  with careful testing on the target platform).

## 8.4 Working with Images/Pixels as Binary Data
A simple grayscale image can be represented as a 2D array of pixel values
(0–255, i.e. `unsigned char`), and color images typically store 3 (RGB) or 4 (RGBA)
bytes per pixel.

```c
typedef struct {
    unsigned char r, g, b;
} Pixel;

Pixel image[HEIGHT][WIDTH];

// Writing raw pixel data to a binary file
FILE *fp = fopen("image.bin", "wb");
fwrite(image, sizeof(Pixel), HEIGHT * WIDTH, fp);
fclose(fp);

// Reading it back
FILE *fp = fopen("image.bin", "rb");
fread(image, sizeof(Pixel), HEIGHT * WIDTH, fp);
fclose(fp);
```

Common exercises:
- Convert to grayscale: `gray = (r + g + b) / 3` (or a weighted luminance formula).
- Invert colors: `r = 255 - r`, etc.
- Flip/rotate the image by manipulating array indices.
- Simple formats like **PPM** (`.ppm`) have a plain-text header describing width,
  height, and max value, followed by raw or ASCII pixel data — a common practice
  target for combining structs, files, and loops.

## 8.5 Basic Algorithms (Common Course Capstone Topics)

### Searching
```c
// Linear search — O(n)
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++)
        if (arr[i] == target) return i;
    return -1;
}

// Binary search — O(log n), requires SORTED array
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
```

### Sorting
```c
// Bubble sort — O(n^2), simple but slow
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

// Selection sort — O(n^2)
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx]) minIdx = j;
        swap(&arr[i], &arr[minIdx]);
    }
}
```

### Recursion Basics
```c
int factorial(int n) {
    if (n <= 1) return 1;          // base case
    return n * factorial(n - 1);    // recursive case
}

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```
Every recursive function needs a **base case** (to stop) and a **recursive case**
(that moves toward the base case) — otherwise it recurses infinitely and overflows
the stack.

## 8.6 Quick Complexity Reference
| Algorithm | Best | Average | Worst |
|---|---|---|---|
| Linear Search | O(1) | O(n) | O(n) |
| Binary Search | O(1) | O(log n) | O(log n) |
| Bubble Sort | O(n) | O(n²) | O(n²) |
| Selection Sort | O(n²) | O(n²) | O(n²) |
