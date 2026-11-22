#include <unistd.h>

int main() {

    const char msg[] = "hello, world!\n";
    write(1, msg, sizeof(msg) - 1); /* write to stdout (file descriptor 1),
                                       length minus the null terminator */
    return 0;
}
