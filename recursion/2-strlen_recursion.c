#include "main.h"

/**
 * _strlen_recursion - returns the length of a string
 * @s: string to measure
 *
 * Return: length of string as integer
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return (0);
	}

	/* 1 for current char + rest of length */
	return (1 + _strlen_recursion(s + 1));
}
