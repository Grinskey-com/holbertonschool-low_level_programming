#include "main.h"
#include <stddef.h>

/**
 * _strchr - locates a character in a string
 * @s: pointer to the string to search
 * @c: the character to locate
 *
 * Return: a pointer to the first occurrence of c, or NULL if not found
 */
char *_strchr(char *s, char c)
{
	/* Stream through the string including the null terminator */
	while (1)
	{
		/* If the current character matches the target, return this address */
		if (*s == c)
		{
			return (s);
		}

		/* If we hit the end of the string without a match, break out */
		if (*s == '\0')
		{
			break;
		}

		s++;
	}

	/* Return NULL if the character was completely missing from the stream */
	return (NULL);
}
