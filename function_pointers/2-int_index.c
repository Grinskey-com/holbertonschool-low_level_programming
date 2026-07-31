#include <stdio.h>
#include "function_pointers.h"

/**
 * int_index - searches for an int in array
 * @array: pointer to int array
 * @size: number of elemets in the array
 * @cmp: func pointer comparing values
 * Return: index of first match, or -1 on failure/no match
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;
	/* NULL guard */
	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);
	/* looping thru array */
	for (i = 0; i < size; i++)
	{	/* return index on first non-zero return from cmp */
		if (cmp(array[i]) != 0)
			return (i);
	}

	return (-1);
}
