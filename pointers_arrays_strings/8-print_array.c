#include "main.h"
#include <stdio.h>

/**
 * print_array - prints n elements of an array of integers
 * @a: pointer to the first element of the integer array
 * @n: number of elements to print
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		/* 1. Look inside the current address and print the integer */
		printf("%d", *a);

		/* 2. Only print the separator if not last element */
		if (i < n - 1)
		{
			printf(", ");
		}

		/* 3. move pointer forward to the next integer in memory */
		a++;
	}

	printf("\n");
}
