#include <stdio.h>
#include "function_pointers.h"

/**
 * array_iterator - executes a function on each element
 * @array: pointer to the int array
 * @size: size of the array
 * @action: pointer to the function
 *
 * Return: nothing
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	/* NULL guard */
	if (array == NULL || action == NULL)
		return;

	/* Loop through each element until you reach the end */
	for (i = 0; i < size; i++)
	{
		(*action)(array[i]);
	}
}
