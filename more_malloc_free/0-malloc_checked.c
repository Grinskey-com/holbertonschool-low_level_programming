#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - Allocates memory using malloc
 * @b: Number of bytes to allocate
 *
 * Return: A pointer to the allocated memory.
 *         If malloc fails, terminates process with status 98.
 */
void *malloc_checked(unsigned int b)
{
	/* declare a pointer variable to hold the address */
	void *ptr;

	/* Call to malloc for bytes 'b' */
	ptr = malloc(b);
	/* NULL check */
	if (ptr == NULL)
	{
		exit(98); /* termination status 98 */
	}
	/* Return the ptr */
	return (ptr);
}
