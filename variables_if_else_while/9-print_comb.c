#include <stdio.h>
/**
 * main - prints all single digit numbers sepersted by a comma and space
 *
 * Return: always 0 (success)
 */
int main(void)
{
	int i;
	
	for (i = 0; i<= 9; i++)
	{
	putchar(i + '0');
	if(i != 9)
		{
		putchar(',');
		putchar(' ');
		}
	}
	putchar('\n');
	return(0);
}
