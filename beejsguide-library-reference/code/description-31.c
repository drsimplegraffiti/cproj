atomic_int x = 10;
int prev = (x += 20);
printf("%d %d\n", prev, x);  // 30 30
