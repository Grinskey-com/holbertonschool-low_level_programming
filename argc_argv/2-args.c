#include <stdio.h>

/**
 * main - prints all args inlc the first one
 * @argc: the number of command-line arguments
 * @argv: an array of pointers to the command-line arguments
 *
 * return: always 0 (success).
 */
int main(int argc, char *argv[])
{
	int i;

	for(i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	return (0);
}

