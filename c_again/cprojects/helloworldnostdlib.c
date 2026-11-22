#include <unistd.h>

int main() {
    const char msg[] = "Hello world\n";

    /* used the write syscall directly. */
    /* man 2 write */
    /* system calls manual */
    write(1, msg, sizeof(msg) - 1);
    return 0;
}
