#include "main.h"

/**
 * _memset - fills memory with a constant byte
 * @s: pointer to the memory area to fill
 * @b: the constant byte value to inject
 * @n: the total number of bytes to be filled
 *
 * Return: a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	char *start;
	unsigned int i;

	/* Save the anchor after all declarations are complete */
	start = s;

	/* Stream through the memory area replacing bytes up to the n threshold */
	for (i = 0; i < n; i++)
	{
		*s = b;
		s++;
	}

	/* Return the anchored original starting address */
	return (start);
}
