#include "main.h"

/**
 * _strncat - concatenates two strings using at most n bytes from src
 * @dest: pointer to the destination string
 * @src: pointer to the source string
 * @n: maximum number of bytes to append from src
 *
 * Return: a pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	char *start;
	int i;

	/* Save the anchor after all declarations are complete */
	start = dest;

	/* Phase 1: Advance dest until it points to its own null byte */
	while (*dest != '\0')
	{
		dest++;
	}

	/* Phase 2: Stream from src but stop if we hit '\0' OR copy n bytes */
	for (i = 0; i < n && *src != '\0'; i++)
	{
		*dest = *src;
		dest++;
		src++;
	}

	/* Seal the combined string with a final null terminator */
	*dest = '\0';

	/* Return the anchored original starting address */
	return (start);
}
