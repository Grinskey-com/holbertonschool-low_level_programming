#include "main.h"
#include <stdlib.h>

/**
 * array_range - Creates an array of integers from min to max
 * @min: Minimum value (included)
 * @max: Maximum value (included)
 *
 * Return: Pointer to newly created array, or NULL if min > max or malloc fails
 */
int *array_range(int min, int max)
{
	int *array;
	int size, i;

	/* Guard for invalid range */
	if (min > max)
		return (NULL);

	/* Calculate size*/
	size = (max - min) + 1;

	/* Allocate memory for 'size' integers */
	array = malloc(sizeof(int) * size);
	if (array == NULL)
		return (NULL);

	/* Populate the array with values from min to max */
	for (i = 0; i < size; i++)
	{
		array[i] = min + i;
	}

	return (array);
}
