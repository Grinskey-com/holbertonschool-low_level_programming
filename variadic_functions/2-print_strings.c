#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_strings - Prints strings, followed by a new line.
 * @separator: The str to be printed between the strings.
 * @n: The number of strings passed to the function.
 * @...: A variable number of strings to be printed.
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	char *str; /*temp pointer for each string*/

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		/* takes each arg and stores it inside str */
		str = va_arg(args, char *);

		/* NULL GUARD */
		if (str == NULL)
		{
			printf("(nil)");
		}
		else
		{
			/* Print the actual string */
			printf("%s", str);
		}

		if (separator != NULL && i < n - 1)
		{
			printf("%s", separator);
		}
	}

	printf("\n");

	va_end(args);
}
