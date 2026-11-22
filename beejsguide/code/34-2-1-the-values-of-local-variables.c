int x = 20;

if (setjmp(env) == 0) {
    x = 30;
}
