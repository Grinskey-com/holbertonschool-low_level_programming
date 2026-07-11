#include <stdio.h>
/**
 * main - prints the lowercase alphabet, excluding q and e
 *
 * Return: always 0 (success)
 */
int main(void)
{
	char ch;

	for (ch = 'a'; ch <= 'z'; ch++)
		if (ch != 'q' && ch != 'e')
			putchar(ch);
	putchar('\n');
	return (0);
}
