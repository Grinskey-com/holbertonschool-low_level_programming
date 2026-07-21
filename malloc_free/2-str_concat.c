#include "main.h"
#include <stdlib.h>
/**
 * str_concat - concatenates two strings into a new allocated memory heap
 * @s1 is the first string
 * @s2 is the second string to append
 *
 */
char *str_concat(char *s1, char *s2)
{
	char *concat;
	unsigned int len1 = 0;
	unsigned int len2 = 0;
	unsigned int i, j;

	/* Null treated at empty strings */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* measure length */
	for (len1 = 0; s1[len1] != '\0'; len1++)
	{

	}
	for (len2 = 0; s2[len2] != '\0'; len2++)
	{

	}

	/* Allocate */
	concat = malloc(sizeof(char) * (len1 + len2 + 1));

	/* check NULL */
	if (concat == NULL)
		return (NULL);

	/* copy into concat */
	for (i = 0; i < len1; i++)
	{
		concat[i] = s1[i];
	}
	/* copy into concat */
	for (j = 0; j < len2; j++)
	{
		concat[j] = s2[j];
	}
	/* add null byte to end */
	concat[i + j] = '\0';

	return (concat);
}
