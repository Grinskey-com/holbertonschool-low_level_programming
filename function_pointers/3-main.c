#include "3-calc.h"

/**
 * main - Entry point for command line calculator.
 * @argc: Argument count from command line.
 * @argv: Array of argument string pointers.
 *
 * Return: Always 0 on success. Exits with status codes on error:
 *         98 - Wrong number of arguments
 *         99 - Invalid operator passed
 *         100 - Division or modulo by zero attempted
 */
int main(int argc, char *argv[])
{
	int num1, num2;
	char *op;
	int (*func)(int, int);

	/* Ensure exactly 3 arguments passed: program, num1, operator, num2 */
	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	/* Convert string inputs to integers and store operator string */
	num1 = atoi(argv[1]);
	op = argv[2];
	num2 = atoi(argv[3]);

	/* Lookup function matching the operator string */
	func = get_op_func(op);

	/* Validate operator - exit if  NULL */
	if (func == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	/* Guard against division or modulo by zero */
	if ((*op == '/' || *op == '%') && num2 == 0)
	{
		printf("Error\n");
		exit(100);
	}

	/* Execute function pointer dynamically and print result */
	printf("%d\n", func(num1, num2));

	return (0);
}
