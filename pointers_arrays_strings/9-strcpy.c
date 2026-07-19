#include "main.h"

/**
 * _strcpy - copies the string pointed to by src to dest
 * @dest: pointer to the destination buffer
 * @src: pointer to the source string
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	char *start;

	/* Initialize after all declarations are complete */
	start = dest;

	/* Stream characters from src to dest until hitting the null terminator */
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	/* Dont forget! copy the final null terminator */
	*dest = '\0';

	/* Return the original starting address */
	return (start);
}
