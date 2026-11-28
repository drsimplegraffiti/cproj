#include <stdio.h>

int main(void) {
    int i;
    int a[5] = {22, 37, 3490, 18, 95};

    for (i = 0; i < 10; i++) { // BAD NEWS: printing too many elements!
        printf("%d\n", a[i]);
    }
}

/* ~/Downloads/cprog main wip !8 ?10 ❯ ./main   system  */
/* 22 */
/* 37 */
/* 3490 */
/* 18 */
/* 95 */
/* 32767 */
/* 2108226816 */
/* 674642850 */
/* -378233760 */
/* 32767 */
