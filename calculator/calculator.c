#include <stdio.h>
#include <stdlib.h>

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


int displayMenu();
char getOperator();
double getNumber();
double performCalculation(char operator, double num1, double num2);

int main(void) {
    char operator;
    double num1, num2, result;

    while (1) {
        operator = getOperator();
        if (operator == 'x' || operator == 'X') {
            break;
        }

        num1 = getNumber();
        num2 = getNumber();

        result = performCalculation(operator, num1, num2);
        printf("%.1lf %c %.1lf = %.1lf\n", num1, operator, num2, result);
    }

    printf("Exiting calculator...\n");
    return 0;
}

// Display the menu
int displayMenu() {
    printf("\nSimple Calculator\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Exit (x)\n");
    printf("Enter your choice: ");
    return 0;
}

// Get operator input from user
char getOperator() {
    char ch;

    do {
        displayMenu();
        scanf(" %c", &ch); // Read operator with a space before
    } while (ch < '1' || ch > '5' || ch == 'x' || ch == 'X');

    return ch;
}

// Function to get a number from the user
double getNumber() {
    double num;

    while (scanf("%lf", &num) != 1) {
        printf("Invalid input. Please enter a number: ");
        scanf("%*[^\n]"); // Clear the input buffer
    }

    return num;
}

// Perform calculation based on operator
double performCalculation(char operator, double num1, double num2) {
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
                return 0.0; // Or handle the error differently
            } else {
                return num1 / num2;
            }
        default:
            return 0.0; // Or handle invalid operator differently
    }
}

