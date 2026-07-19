#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: pointer to the destination string
 * @src: pointer to the source string to append
 *
 * Return: a pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	char *start;

	/* Save the anchor*/
	start = dest;

	/* Advance dest until null byte */
	while (*dest != '\0')
	{
		dest++;
	}

	/* Stream characters from src into the end of dest */
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	/* Seal the combined string with a final null terminator */
	*dest = '\0';

	/* Return to the anchor */
	return (start);
}
