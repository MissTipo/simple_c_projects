## Simple Calculator in C

This project implements a simple calculator program written in C. It allows users to perform basic arithmetic operations like addition, subtraction, multiplication, and division.

### Features:

User-friendly menu for selecting operations.
Accepts single-character operators (+, -, \*, /).
Handles double-precision numbers for calculations.
Displays error messages for invalid operators or division by zero.
Getting Started

### Prerequisites:

A C compiler (e.g., gcc)
Compiling the Code:

Save the C source code (calculator.c) and the Makefile in the same directory.
Open a terminal in that directory.
Run the command make. This will compile the code and create an executable named calculator.
Running the Calculator:

In the terminal, type ./calculator and press Enter.
The calculator will display a menu with options for different operations and exiting.
Select the desired operation by entering the corresponding number (1 for addition, 2 for subtraction, etc.).
Enter two space-separated numbers as operands.
The calculator will perform the calculation and display the result.
Example:

Simple Calculator

1. Addition (+)
2. Subtraction (-)
3. Multiplication (\*)
4. Division (/)
5. Exit (x)
   Enter your choice: 1
   Enter two numbers (first and second): 5 3
   5.00 + 3.00 = 8.00

Simple Calculator

1. Addition (+)
2. Subtraction (-)
3. Multiplication (\*)
4. Division (/)
5. Exit (x)
   Enter your choice: /
   Enter two numbers (first and second): 10 2
   10.00 / 2.00 = 5.00

Simple Calculator

1. Addition (+)
2. Subtraction (-)
3. Multiplication (\*)
4. Division (/)
5. Exit (x)
   Enter your choice: x
   Exiting calculator...

### Additional Notes:

You can modify the Makefile to customize the compiler or output filename.
For more advanced features, consider implementing support for additional operations, parentheses for expression evaluation, or error handling for invalid expressions.
