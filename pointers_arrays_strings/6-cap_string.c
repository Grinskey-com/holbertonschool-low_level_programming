#include "main.h"

/**
 * cap_string - capitalises all words of a string
 * @str: pointer to the string to modify
 *
 * Return: a pointer to the modified string
 */
char *cap_string(char *str)
{
	char *start;
	int trigger;

	trigger = 1;
	start = str;

	while (*str != '\0')
	{
		/* If separator alarm is active and we hit a lowercase letter, shift it */
		if (trigger && *str >= 'a' && *str <= 'z')
		{
			*str = *str - 32;
		}

		/* Reset trigger assuming it's a normal character unless proven otherwise */
		if ((*str >= 'a' && *str <= 'z') ||
		    (*str >= 'A' && *str <= 'Z') ||
		    (*str >= '0' && *str <= '9'))
		{
			trigger = 0;
		}

		/* Check list */
		if (*str == ' ' || *str == '\t' || *str == '\n' ||
		    *str == ',' || *str == ';' || *str == '.' ||
		    *str == '!' || *str == '?' || *str == '"' ||
		    *str == '(' || *str == ')' || *str == '{' ||
		    *str == '}')
		{
			trigger = 1;
		}

		str++; /* Slide the cursor finger forward 1 byte */
	}

	/* Return the anchored original starting address */
	return (start);
}
