#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - Prints anything based on format.
 * @format: A list of types of arguments passed to the function.
 */
void print_all(const char * const format, ...)
{
	int i = 0;
	char *str;
	char *sep = "";/* no comma for 1st item */
	va_list args;

	/* Args is a moveable pointer */
	va_start(args, format);
	/* 1. Is it a string? 2. any chars left? */
	while (format && format[i])
	{
		switch (format[i])
		{
		case 'c':
			printf("%s%c", sep, va_arg(args, int));
			sep = ", ";
			break;
		case 'i':
			printf("%s%d", sep, va_arg(args, int));
			sep = ", ";
			break;
		case 'f':
			printf("%s%f", sep, va_arg(args, double));
			sep = ", ";
			break;
		case 's':
			str = va_arg(args, char *);
			if (!str)
				str = "(nil)";
			printf("%s%s", sep, str);
			sep = ", ";
			break;
		default:
			break;
		}
		i++;
	}

	printf("\n");
	va_end(args);
}
