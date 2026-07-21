#include "main.h"

/**
 * reverse_array - reverses the content of an array of integers
 * @a: pointer to the array of integers
 * @n: the number of elements in the array
 *
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int temp;
	int *left;
	int *right;

	/* Initialize the tracking */
	left = a;
	right = a + (n - 1);

	/* Run inward until the two pointer positions meet or cross in the middle */
	while (left < right)
	{
		/* The cup swap engine */
		temp = *left;
		*left = *right;
		*right = temp;

		/* Move the tracking fingers inward toward each other */
		left++;
		right--;
	}
}
