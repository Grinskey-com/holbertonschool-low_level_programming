#include <stdio.h>
/**
 * main - prints all base 16 digits in lowercase
 *
 * Return: always 0 (success)
 */
int main(void)
{
	int i;

	for (i = 0; i <= 15; i++)
	{
		if (i < 10)
			putchar(i + '0');
		else
			putchar(i - 10 + 'a');
	}
	putchar('\n');
	return (0);
}
