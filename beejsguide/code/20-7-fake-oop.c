struct parent {
    int a, b;
};

struct child {
    struct parent super;  // MUST be first
    int c, d;
};
