#include <float.h>
#include <stdio.h>

int main(void) {
    printf("Float:\n");
    printf("Minimum: %e\n", FLT_MIN);
    printf("Maximum: %e\n", FLT_MAX);
    printf("Precision: %d\n", FLT_DIG);
    printf("Epsilon: %e\n", FLT_EPSILON);

    printf("\nDouble:\n");
    printf("Minimum: %e\n", DBL_MIN);
    printf("Maximum: %e\n", DBL_MAX);
    printf("Precision: %d\n", DBL_DIG);
    printf("Epsilon: %e\n", DBL_EPSILON);

    printf("\nLong Double:\n");
    printf("Minimum: %Le\n", LDBL_MIN);
    printf("Maximum: %Le\n", LDBL_MAX);
    printf("Precision: %d\n", LDBL_DIG);

    return 0;
}
