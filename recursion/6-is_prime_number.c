#include "main.h"

int check_prime(int n, int i);

/**
 * check_prime - tests divisors recursively
 * @n: number to test
 * @i: current divisor guess
 *
 * Return: 1 if prime, 0 if not
 */
int check_prime(int n, int i)
{
	/* base case 1: checked up to sqrt(n), so it is prime */
	if (i * i > n)
	{
		return (1);
	}

	/* base case 2: divides cleanly, so not prime */
	if (n % i == 0)
	{
		return (0);
	}

	/* try next divisor */
	return (check_prime(n, i + 1));
}

/**
 * is_prime_number - checks if integer is prime
 * @n: number to check
 *
 * Return: 1 if prime, 0 if not
 */
int is_prime_number(int n)
{
	/* guard clause: numbers 1 or less are not prime */
	if (n <= 1)
	{
		return (0);
	}

	/* start testing divisors from 2 */
	return (check_prime(n, 2));
}
