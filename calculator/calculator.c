#include <stdio.h>
#include "calculator.h"

/**
 * main - Entry point for the program
 *        It continuously prompts the user for an operator and two
 *        operands, performs the corresponding operation, and displays
 *        the result. The program terminates when the user enters 'x'.
 *
 * @operator: Type char - operator character
 * @num1: Type int - first operand
 * @num2: Type int - second operand
 *
 * Return - 0 on successful execution, non-zero on error
 */


double performCalculation(char operator, double num1, double num2);

int main(void)
{
    char operator;
    double num1, num2, result;

    printf("enter the first operand: ");
    scanf("%lf", &num1);

    printf("Enter the  operator: ");
    scanf(" %c", &operator);

    printf("enter the second operand: ");
    scanf("%lf", &num2);

    result = performCalculation(operator, num1, num2);

    if (result) {
        printf("\nThe result of your calculation is: %f\n", result);
    }

    return 0;
}

// Perform calculation based on operator
double performCalculation(char operator, double num1, double num2)
{
    switch (operator) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
                return 0.0;
            } else {
                return num1 / num2;
            }
    }
}

