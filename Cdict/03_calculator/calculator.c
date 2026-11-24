#include <stdio.h>

int main() {

    double numberOne;
    double numberTwo;
    char operator;
    double result;

    printf("Enter first number: ");
    scanf("%lf", &numberOne);

    printf("Enter second number: ");
    scanf("%lf", &numberTwo);

    printf("Enter operator: ");
    scanf(" %c", &operator);

    switch (operator) {
    case '+':
        result = numberOne + numberTwo;
        printf("Result of %lf + %lf = %.2lf\n", numberOne, numberTwo, result);
        break;
    case '-':
        result = numberOne - numberTwo;
        printf("Result of %lf - %lf = %.2lf\n", numberOne, numberTwo, result);
        break;
    case '*':
        result = numberOne * numberTwo;
        printf("Result of %lf * %lf = %.2lf\n", numberOne, numberTwo, result);
        break;
    case '/':
        if (numberTwo != 0) {
            result = numberOne * numberTwo;
            printf("Result of %lf * %lf = %.2lf\n", numberOne, numberTwo,
                   result);
            break;
        } else {
            printf("not divisible \n");
        }
    default:
        printf("invalid operator entered \n");
    }

    return 0;
}

//
// #include <stdbool.h>
// #include <stdio.h>
//
// void print(double rs) { printf("result is %f\n", rs); }
//
// bool condition(double num1) {
//     if (num1 < 1) {
//         printf("num1 is less than 1\n");
//         return true;
//     }
//
//     return false;
// }
//
// void calc(double num, double num1, char op) {
//     double result;
//
//     switch (op) {
//         case '+':
//             result = condition(num1) ? 0 : num + num1;
//             print(result);
//             break;
//
//         case '-':
//             result = condition(num1) ? 0 : num - num1;
//             print(result);
//             break;
//
//         case '/':
//             result = condition(num1) ? 0 : num / num1;
//             print(result);
//             break;
//
//         default:
//             printf("unknown operator\n");
//     }
// }
//
// int main(void) {
//     printf("Enter first number(e.g 1.2): ");
//     double first, second;
//     char op;
//     scanf("%lf", &first);
//     printf("enter first number(e.g 1.2): ");
//     scanf("%lf", &second);
//
//     printf("enter op(e.g *, -, +, /): ");
//     scanf(" %c", &op);
//
//     calc(first, second, op);
//     return 0;
// }
