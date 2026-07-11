#include <stdio.h>
/**
 * main - prints single digit numbers 0-9 without using a char variable
 *
 * Return: always 0 (success)
 */
int main(void)
{
	int i;

	for (i = 0; i <= 9; i++)
		putchar(i + '0');
	putchar('\n');
	return (0);
}
