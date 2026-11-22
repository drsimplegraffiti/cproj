atomic_int x = 0;

thread1() {
    x += 3;   // ATOMIC!
}
