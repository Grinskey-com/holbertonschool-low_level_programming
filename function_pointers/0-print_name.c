#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name - prints a name using a given a fucntion pointer
 * @name: the string to print
 * @f: the pointer to the printing fucntion
 */
void print_name(char *name, void (*f)(char *))
{
	/* Guard against NULL pointers */
	if (name == NULL || f == NULL)
		return;

	/* Call the fucntion pointer and pass the name */
	(*f)(name);

}
