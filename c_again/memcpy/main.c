#include <stdio.h>
#include <string.h>

void *my_memcpy(void *dest, void *src, int byte_count) {
    // Convert void*s to char*s
    char *s = src, *d = dest;

    // Now that we have char*s, we can dereference and copy them
    while (byte_count--) {
        *d++ = *s++;
    }

    // Most of these functions return the destination, just in case
    // that's useful to the caller.
    return dest;
}

int main(void) {
    char s[] = "goat";
    char t[100];

    memcpy(t, s, 7); // 7 reps how many bytes to copy
    printf("%s\n", t);

    int a[] = {11, 22, 33};
    int b[3];
    memcpy(b, a, 3 * sizeof(int)); // Copy 3 ints of data

    printf("%d\n", b[1]); // 22
                          //
                          //

    my_memcpy(t, s, 7);
    printf("%s\n", t);
    return 0;
}
