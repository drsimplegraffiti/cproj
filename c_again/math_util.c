#include "math_util.h"
#include <stdio.h>

int add(int x, int y) {
    printf("result is %d\n", x + y);
    return x + y;
}

void hello(const char *name) { printf("Hello %s\n", name); }
