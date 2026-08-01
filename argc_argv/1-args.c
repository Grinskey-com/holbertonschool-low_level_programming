#include <stdio.h>

/**
 * main - Prints the number of args passed, followed by a new line.
 * @argc: the number of command-line arguments (unused).
 * @argv: an array of pointers to the command-line arguments.
 *
 * return: always 0 (success).
 */
int main(int argc, char *argv[])
{
	(void)argv;

	printf("argc = %d\n", argc - 1);
	return (0);
}
