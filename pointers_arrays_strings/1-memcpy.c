#include "main.h"

/**
 * _memcpy - copies memory area
 * @dest: pointer to the destination memory area
 * @src: pointer to the source memory area
 * @n: the total number of bytes to copy
 *
 * Return: a pointer to the destination area dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *start;
	unsigned int i;

	/* Save the anchor after all declarations are complete */
	start = dest;

	/* Stream through both memory areas, copying elements up to the n limit */
	for (i = 0; i < n; i++)
	{
		*dest = *src;
		dest++;
		src++;
	}

	/* Return the anchored original starting address */
	return (start);
}
