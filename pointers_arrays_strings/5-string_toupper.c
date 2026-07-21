#include "main.h"

/**
 * string_toupper - changes all lowercase letters of a string to uppercase
 * @str: pointer to the string to modify
 *
 * Return: a pointer to the modified string
 */
char *string_toupper(char *str)
{
	char *start;

	/* Save the anchor */
	start = str;

	/* Stream through the string until reaching the null terminator */
	while (*str != '\0')
	{
		/* Check if the character sits in the lowercase ASCII zone */
		if (*str >= 'a' && *str <= 'z')
		{
			/* Subtract 32 to shift it directly into uppercase territory */
			*str = *str - 32;
		}

		str++; /* Slide the cursor finger forward 1 byte */
	}

	/* Return the anchored original starting address */
	return (start);
}
