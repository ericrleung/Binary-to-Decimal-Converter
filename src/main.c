/*
 * C program to convert a given binary number into decimal or vice versa.
 * Inspiration taken from: 
 * https://www.sanfoundry.com/c-program-binary-number-into-decimal/
 */
#include <stdio.h>
#include <ctype.h>

/*
 * Function to convert a given number from binary to decimal.
 * Assign the remainder to be the remainder of the number divided by
 * the base you wish to convert to
 * Update the decimal value to be the sum of itself
 * with the product of the remainder and the base.
 * Algorithm is to continuously divide the num by 10.
 * and update the base to be the base * whatever base the original number is in.
 */
int binary_to_decimal(int num)
{
	// Initialize local variable decimal value to store the value to be returned.
	// Initialize the base to 1.
	// Declare a variable to store the remainder.
	int decimal_val = 0, base = 1, remainder;
	// While loop to process the number.
	while (num > 0) {
		// Update the remainder to be "num % 10".
		remainder = num % 10;
		// Update the decimal value to be itself + the remainder multiplied
		// by the current base.
		decimal_val = decimal_val + remainder * base;
		// Assign the number to be the quotient of itself divided by 10.
		num = num / 10;
		// Update the base to be itself * 2.
		base = base * 2;
	}
	return decimal_val;
}

/*
 * Function to convert a given number from decimal to binary.
 * Assign the remainder to be the remainder of the number divided by
 * the base you wish to convert to
 * Update the binary value to be the sum of itself
 * with the product of the remainder and the base.
 * Algorithm is to continuously divide the num by 2.
 * and update the base to be the base * whatever base the original number is in.
 */
int decimal_to_binary(int num)
{
	int binary_val = 0, base = 1, remainder;
	while (num > 0) {
		remainder = num % 2;
		binary_val = binary_val + remainder * base;
		num = num / 2;
		base = base * 10;
	}
	return binary_val;
}

/*
 * A helper function that is used to display the menu.
 * This was put in a separate function to allow for modularity
 * such as if the program was expanded and needed to call the menu elsewhere.
 */
char *show_menu(void)
{
	return "B)inary to Decimal\nD)ecimal to Binary\nQ)uit ?\n";
}

/*
 * Main function to execute behaviour of program using an infinite while loop.
 */
int main(void)
{
	while (1) {
		// Declare int variables to store the number taken from user input,
		// the binary_value of the number
		// and the decimal_value of the number.
		int num, binary_val, decimal_val;
		// Declare a character variable that will be used to store
		// the users input.
		char userInput;
		// Display the menu to the user.
		printf("%s", show_menu());
		// Use scanf to get user input
		scanf(" %c", &userInput);
		// All checks are made using tolower
		// So that 'B' and 'b' are treated the same for example.
		// This is done in order to simplify input for the user
		// (not case sensitive).
		if (tolower(userInput) == 'b') {
			// if the userInput is b that means binary to decimal
			printf("Enter a binary number(1s and 0s) \n");
			// Ask for user to enter a number and store it in num using scanf.
			scanf("%d", &num);	/* maximum five digits */
			// Since user chose binary to decimal the value is interpreted
			// as being in binary, therefore assign num to binary_val.
			binary_val = num;
			// Assign the result of calling binarty_to_decimal(num)
			// to decimal_val.
			decimal_val = binary_to_decimal(num);
			// Display the original binary value
			printf("The Binary number is = %d \n", binary_val);
			// and the decimal equivalent.
			printf("Its decimal equivalent is = %d \n", decimal_val);
			// Another case where user wants to go from decimal to binary.
		} else if (tolower(userInput) == 'd') {
			// Ask for decimal number and store in num using scanf.
			printf("Enter a decimal number(0-9) \n");
			scanf("%d", &num);	/* maximum five digits */
			// In this case, the decimal_val is the number entered by the user
			decimal_val = num;
			// and the binary_val must be calculated by calling the
			// decimal_to_binary converter function defined above.
			binary_val = decimal_to_binary(decimal_val);
			// Print the original decimal value
			printf("The Decimal number is = %d \n", decimal_val);
			// and the binary equivalent.
			printf("Its binary equivalent is = %d \n", binary_val);
			// Otherwise if the user specifies q, exit program.
		} else if (tolower(userInput) == 'q') {
			return 0;
			// Otherwise unknown command.
		} else {
			printf("No such command\n");
		}
	}
}
