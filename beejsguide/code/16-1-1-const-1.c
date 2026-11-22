void foo(const int x)
{
    printf("%d\n", x + 30);  // OK, doesn't modify "x"
}
