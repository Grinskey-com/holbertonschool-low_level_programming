#include "main.h"
#include <stdlib.h>
/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 *	which contains a copy of the string given as a parameter
 * @str: the string duplicated
 * Return: pointer to duplicated string, or null if str = NULLor malloc fails
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int len = 0;
	unsigned int i;

	/* Check if the input pointer is NULL */
	if (str == NULL)
		return (NULL);

	/* Measure length of str using a for loop */
	for (len = 0; str[len] != '\0'; len++)
	{
	/* intentionally left empty */
	}

	/* Allocate memory for len +1 */
	dup = malloc(sizeof(char) * (len + 1));

	/* check for any malloc failure */
	if (dup == NULL)
		return (NULL);

	/* Copy char from str to dup */
	for (i = 0; i < len; i++)
	{
		dup[i] = str[i];
	}

	/* add the null byte at index len */
	dup[len] = '\0';

	/* Return pointer to dup */
	return (dup);
}
