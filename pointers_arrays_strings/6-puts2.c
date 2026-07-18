#include "main.h"

/**
 * puts2 - prints every other character of a string
 * @str: pointer to the string to print
 */
void puts2(char *str)
{
	int i;

	/* Start at 0, check for the null terminator, hop by 2 */
	for (i = 0; str[i] != '\0'; i += 2)
	{
		_putchar(str[i]);
	}

	_putchar('\n');
}
