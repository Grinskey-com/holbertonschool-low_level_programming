#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: pointer to the string to evaluate
 * @accept: pointer to the string containing allowed characters
 *
 * Return: the number of bytes in the initial segment of s
 * consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	char *scan;
	int match;

	while (*s != '\0')
	{
		match = 0;
		scan = accept;

		/* Cycle through the accept guest list looking for *s */
		while (*scan != '\0')
		{
			if (*s == *scan)
			{
				count++;
				match = 1;
				break;
			}
			scan++;
		}

		/* If the current character in s was not found in accept, stop */
		if (match == 0)
		{
			break;
		}

		s++; /* Advance to the next character in the primary string */
	}

	return (count);
}
