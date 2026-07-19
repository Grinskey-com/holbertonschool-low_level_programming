#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: pointer to the string to convert
 *
 * Return: the converted integer, or 0 if no numbers are found
 */
int _atoi(char *s)
{
	int sign = 1;
	int result = 0;
	int found_digit = 0;

	while (*s != '\0')
	{
		/* 1. Tracks elements that aren't digits (flips the sign switch) */
		if (*s == '-')
		{
			sign *= -1;
		}

		if (*s >= '0' && *s <= '9')
		{
			/* 2. Alarm for when a digit is found */
			found_digit = 1;

			/* Engine builds a number using x10 to shift digits over */
			/* and converts the ASCII value, adding or subtracting safely */
			if (sign == 1)
				result = (result * 10) + (*s - '0');
			else
				result = (result * 10) - (*s - '0');
		}
		/* 3. Else if a non-digit is found after the alarm, stop immediately */
		else if (found_digit)
		{
			break;
		}

		s++;
	}

	return (result);
}
