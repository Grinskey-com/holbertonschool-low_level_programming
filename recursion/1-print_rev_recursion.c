#include "main.h"

/**
 * _print_rev_recursion - prints a string in reverse
 * @s: string to print
 *
 * Return: void
 */
void _print_rev_recursion(char *s)
{
	/* stop at the null terminator */
	if (*s == '\0')
	{
		return;
	}

	/* recurse first to traverse to the end of the string */
	_print_rev_recursion(s + 1);

	/* print the character after calls finish */
	_putchar(*s);
}
