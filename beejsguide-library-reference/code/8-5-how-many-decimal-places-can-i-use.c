#include <stdio.h>
#include <float.h>

int main(void)
{
    float pi = 3.1415926535897932384626433832795028841971;

    // With %g or %G, the precision refers to the number of significant
    // digits:

    printf("%.*g\n", FLT_DIG, pi);  // For me: 3.14159

    // But %f prints too many, since the precision is the number of
    // digits to the right of the decimal--it doesn't count the digits
    // to the left of it:

    printf("%.*f\n", FLT_DIG, pi);  // For me: 3.14159... 3 ???
}
