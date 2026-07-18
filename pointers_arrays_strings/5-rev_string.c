#include "main.h"

/**
 * rev_string - reverses a string in place
 * @s: pointer to the string to modify
 */
void rev_string(char *s)
{
	int len = 0, i, j;
	char temp;

	/* 1. Find the length */
	while (s[len] != '\0')
		len++;

	/* 2. The compact swap engine */
	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}
