
#include "panic.h"
#include <stdio.h>
#include <stdlib.h>

void c_panic(char *message) {
    puts(message);
    exit(1);
}
