#include <stdio.h>

/* The static keyword changes how a variable or function behaves in terms of
 * lifetime and visibility: */

/*     Static local variables keep their value between function calls. */
/*     Static global variables/functions are not visible outside their file. */
void count() {
    static int myNum = 0; // Keeps its value between calls
    myNum++;
    printf("num = %d\n", myNum);
}

int main() {
    count();
    count();
    count();
    count();
    return 0;
}
