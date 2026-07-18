#include "main.h"
/**
 * print_rev - prints a string in reverse, followed by a new line
 * @s: pointer to the string to print
 */
void print_rev(char *s)
{
	int length = 0;
	int i;

	/* Phase 1: You must define the length first by walking forward */
	while (s[length] != '\0')
	{
		length++;
	}

	/* Phase 2: Start at length - 1, print, and use i-- to go backward */
	for (i = length - 1; i >= 0; i--)
	{
		_putchar(s[i]);
	}

	_putchar('\n');
}

