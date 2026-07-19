#include "main.h"

/**
 * puts_half - prints the second half of a string using pointers
 * @str: pointer to the string
 */
void puts_half(char *str)
{
	char *searcher;
	int length;
	int start_offset;

	searcher = str;
	length = 0;

	/* 1. Find length by moving the searcher pointer forward */
	while (*searcher != '\0')
	{
		length++;
		searcher++;
	}

	/* 2. Calculate how many steps forward we need to jump from the start */
	if (length % 2 == 0)
		start_offset = length / 2;
	else
		start_offset = length - ((length + 1) / 2);

	/* 3. Reset a pointer to the start address,add the half */
	searcher = str + start_offset;

	/* 4. Print characters by dereferencing and advancing the pointer directly */
	while (*searcher != '\0')
	{
		_putchar(*searcher);
		searcher++; /* Move to the next memory address */
	}

	_putchar('\n');
}
