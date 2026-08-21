#include "main.h"

int _sqrt_helper(int n, int i);

/**
 * _sqrt_helper - tests guesses recursively to find square root
 * @n: target number
 * @i: current guess iterator
 *
 * Return: natural square root, or -1 if none exists
 */
int _sqrt_helper(int n, int i)
{
	/* base case 1: exact square root found */
	if (i * i == n)
	{
		return (i);
	}

	/* base case 2: passed n without exact match */
	if (i * i > n)
	{
		return (-1);
	}

	/* try next guess */
	return (_sqrt_helper(n, i + 1));
}

/**
 * _sqrt_recursion - returns natural square root of a number
 * @n: input integer
 *
 * Return: natural square root, or -1 if none
 */
int _sqrt_recursion(int n)
{
	/* guard clause: negative numbers have no real square root */
	if (n < 0)
	{
		return (-1);
	}

	/* start testing guesses from 1 */
	return (_sqrt_helper(n, 1));
}
