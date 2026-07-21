#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 *
 * Return: an integer less than, equal to, or greater than zero
 */
int _strcmp(char *s1, char *s2)
{
	/* Advance pointers as long as characters match and s1 hasn't ended */
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	/* Return the mathematical difference between the first non-matching bytes */
	return (*s1 - *s2);
}
