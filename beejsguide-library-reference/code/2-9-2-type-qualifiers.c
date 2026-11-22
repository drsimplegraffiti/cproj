const int a = 10;        // Can't modify "a"

const int *p = &b        // Can't modify the thing "p" points to ("b")
int *const p = &b        // Can't modify "p"
const int *const p = &b  // Can't modify "p" or the thing it points to
