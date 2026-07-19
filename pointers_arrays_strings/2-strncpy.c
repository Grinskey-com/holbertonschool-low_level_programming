#include "main.h"

/**
 * _strncpy - copies a string up to n bytes, padding with nulls if needed
 * @dest: pointer to the destination buffer
 * @src: pointer to the source string
 * @n: total number of bytes to be written to dest
 *
 * Return: a pointer to the destination string dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *start;
	int i;

	/* Save the anchor */
	start = dest;
	i = 0;

	/* Phase 1: Stream from src to dest until src ends OR we hit n limit */
	while (i < n && *src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}

	/* Phase 2: If src ended early, pad the remaining space with null bytes */
	while (i < n)
	{
		*dest = '\0';
		dest++;
		i++;
	}

	/* Return the anchored original starting address */
	return (start);
}
