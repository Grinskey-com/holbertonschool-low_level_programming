#include "main.h"
#include <stddef.h>

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: pointer to the string to search
 * @accept: pointer to the string containing target bytes to match
 *
 * Return: a pointer to the byte in s that matches one of the bytes in accept,
 * or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	char *scan;

	/* Stream through the primary string byte-by-byte */
	while (*s != '\0')
	{
		scan = accept;

		/* Scan through the target match list for the current character */
		while (*scan != '\0')
		{
			if (*s == *scan)
			{
				return (s); /* Instant match found, return the address */
			}
			scan++;
		}

		s++; /* Slide the cursor finger forward 1 byte */
	}

	/* Return NULL if no matching elements were found in the entire stream */
	return (NULL);
}
