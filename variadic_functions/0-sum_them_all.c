#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - Returns the sum of all its parameters.
 * @n: The number of parameters passed to the function.
 * @...: A variable number of parameters to sum.
 *
 * Return: If n == 0 - 0.
 *         Otherwise - the sum of all parameters.
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	int sum = 0;

	/* NULL GUARD */
	if (n == 0)
		return (0);
	/* Start the arg list (parameters) */
	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		/* reads current args as ints */
		sum += va_arg(args, int);
	}
	/* Cleans up memory resets args pointer */
	va_end(args);

	return (sum);
}
