#include "main.h"
#include <stdlib.h>

/**
 * _calloc - Allocates memory for an array and initialises it to 0
 * @nmemb: Number of elements
 * @size: Size in bytes of each element
 *
 * Return: Pointer to allocated memory, or NULL if it fails or inputs are 0
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int total_size, i;

	/* Check edge cases */
	if (nmemb == 0 || size == 0)
		return (NULL);

	/* Calculate total bytes */
	total_size = nmemb * size;

	/* Allocate raw memory */
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);

	/* 0 out all bytes */
	for (i = 0; i < total_size; i++)
	{
		ptr[i] = 0;
	}

	return ((void *)ptr);
}
