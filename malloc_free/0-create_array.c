#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * create_array - Creates an array of chars and initializes it with a char
 * @size: The size of the array to create
 * @c: The character to initialize the array with
 *
 * Return: Pointer to the array, or NULL if size = 0 or allocation fails
 */
char *create_array(unsigned int size, char c)
{
	char *array; /* Pointer holds the address of the memory */
	unsigned  int i;

	/* Guard against size 0 */
	if (size == 0)
		return (NULL);
	/* Allocate heap memory */
	array = malloc(sizeof(char) * size);

	/* Check for malloc failure */
	if (array == NULL)
		return (NULL);

	/* Fill array with character 'c' */
	for (i = 0; i < size; i++)
	{
		array[i] = c;
	}

	return (array);
}
