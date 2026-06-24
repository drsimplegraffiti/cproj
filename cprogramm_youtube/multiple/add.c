#include "add.h"

int add(int a, int b, char op) {
    if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else {
        return 0;
    }
}
