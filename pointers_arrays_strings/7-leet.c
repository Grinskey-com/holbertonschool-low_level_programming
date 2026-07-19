#include "main.h"

/**
 * leet - encodes a string into 1337
 * @str: pointer to the string to transform
 *
 * Return: a pointer to the modified string
 */
char *leet(char *str)
{
	char *start;
	int i;
	char targets[] = "aAeEoOtTlL";
	char replacements[] = "4433007711";

	/* Save the anchor after all declarations are complete */
	start = str;

	/* Loop 1: Stream through the string until reaching the null terminator */
	while (*str != '\0')
	{
		/* Loop 2: Cycle through the translation deck indices */
		for (i = 0; i < 10; i++)
		{
			/* The single allowed comparison gatekeeper */
			if (*str == targets[i])
			{
				*str = replacements[i];
			}
		}

		str++; /* Slide the cursor finger forward 1 byte */
	}

	/* Return the anchored original starting address */
	return (start);
}
