atomic_int x = 0;

thread1() {
    x = x + 3;  // NOT atomic!
}
