#include <stdio.h>
#include <stdlib.h>

/**
 * main - addition of args 1 and 2.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the command-line arguments.
 *
 * Return:  0 on success, 1 if error (not two arguments).
 */
int main(int argc, char *argv[])
{
	int i, j;
	int sum = 0;

	/* no number passed */
	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}
	/* Loop scanning through args */
	for (i = 1; i < argc; i++)
	{
		/* Inner loop checking each char */
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			/* checking for digit via ascii */
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}
		/* addtion of args using atoi */
		sum += atoi(argv[i]);
	}
	printf("%d\n", sum);
	return (0);
}
