#include "main.h"

/**
 * puts2 - prints every other character of a string
 * @str: pointer to the string to print
 */
void puts2(char *str)
{
	int len = 0;
	int i;

	/* Step 1: Find the end */
	while (str[len] != '\0')
	{
		len++;
	}

	/* Step 2: Use the exact integer length as a strict boundary*/
	for (i = 0; i < len; i += 2)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}
