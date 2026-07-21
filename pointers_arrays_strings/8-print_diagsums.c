#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals
 * of a square matrix of integers
 * @a: pointer to the flat memory representation of the matrix
 * @size: the length of one side of the square matrix
 *
 * Return: Nothing.
 */
void print_diagsums(int *a, int size)
{
	int i;
	int sum1 = 0;
	int sum2 = 0;

	/* Stream through the matrix row by row using a single tracking loop */
	for (i = 0; i < size; i++)
	{
		/* Primary diagonal element offset: row * size + row */
		sum1 += a[i * size + i];

		/* Secondary diagonal element offset: row * size + (size - 1 - row) */
		sum2 += a[i * size + (size - 1 - i)];
	}

	printf("%d, %d\n", sum1, sum2);
}
