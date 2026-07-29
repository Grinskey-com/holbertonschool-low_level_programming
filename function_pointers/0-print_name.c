#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name - prints a name using a given function pointer
 * @name: string to print
 * @f: pointer to the printing function
 *
 * Return: nothing
 */
void print_name(char *name, void (*f)(char *))
{
	/* NULL guard */
	if (name == NULL || f == NULL)
		return;
	/* handing the name to the *f */
	(*f)(name);
}
