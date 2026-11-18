#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int main(void) {
//   double num1, num2, result;
//   char operator;
//   char choice;
//
//   do {
//     printf("Enter expression (e.g. 3.5 * 2): ");
//
//     if (scanf("%lf %c %lf", &num1, &operator, & num2) != 3) {
//       printf("Invalid input.\n");
//
//       int c;
//       while ((c = getchar()) != '\n' && c != EOF)
//         ;
//
//       continue;
//     }
//
//     result = calculator(num1, operator, num2);
//
//     printf("Result: %.2f\n", result);
//
//     printf("Do you want to calculate another expression? (y/n): ");
//     scanf(" %c", &choice);
//
//   } while (choice == 'y' || choice == 'Y');
//
//   return 0;
// }

#define MAX_INPUT 100
int main(void) {

  char input[MAX_INPUT]; // this 

  while (1) {
    printf("Enter expression or type 'exit' to quit: e.g (1 + 3 - 7 * 3) ");

    fgets(input, MAX_INPUT, stdin);
    if (strncmp(input, "exit", 4) == 0)
      break;
    double result = evaluate_expression(input);
    printf("Result %.2f\n", result);
  }
}
