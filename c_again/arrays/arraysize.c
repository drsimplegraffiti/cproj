#include <stdio.h>

int main(void) {
    int x[12]; // 12 ints

    printf("%zu\n", sizeof x);    // 48 total bytes i.e we have 12 * 4 bytes
    printf("%zu\n", sizeof(int)); // 4 bytes per int

    printf("%zu\n", sizeof x / sizeof(int)); // 48/4 = 12 ints!

    /* when you “pass” arrays to functions, you’re only passing a pointer to the
     * first element, and that’s what sizeof measures */

    /* It’s a common shortcut to see this in an initializer when you want to set
     * an entire array to zero: */

    /* Which means, “Make the first element zero, and then automatically make
     * the rest zero, as well.” */
    int a[4] = {0};
    int len = sizeof(a) / sizeof(int);

    printf("len is %d\n", len);
    for (int i = 0; i < len; i++) {
        printf("%d\n", a[i]);
    }

    /* You can set specific array elements in the initializer, as well, by
     * specifying an index for the value! When you do this, C will happily keep
     * initializing subsequent values for you until the initializer runs out,
     * filling everything else with 0. */

    /* To do this, put the index in square brackets with an = after, and then
     * set the value. */

    printf("==========================================\n");
    /* Here’s an example where we build an array: */
    int b[10] = {0, 11, 22, [5] = 55, 66, 77};

    for (int i = 0; i < len; i++) {
        printf("%d\n", b[i]);
    }

    return 0;
}
