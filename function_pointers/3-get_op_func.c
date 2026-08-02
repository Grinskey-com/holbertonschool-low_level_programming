#include "3-calc.h"

/**
 * get_op_func - Selects the correct math function based on operator.
 * @s: The operator string passed from the command line.
 *
 * Return: Pointer to matching function, or NULL if operator is invalid.
 */
int (*get_op_func(char *s))(int, int)
{
	/* Array mapping each operator string to its function pointer */
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	i = 0;
	 /* Scan array until first match or NULL */
	while (ops[i].op != NULL && *(ops[i].op) != *s)
		i++;

	/*
	 * Check if operator matched AND string is exactly 1 char long.
	 * Rejects multi-char operators like "++" or "\*".
	 */
	if (ops[i].op != NULL && s[1] == '\0')
		return (ops[i].f);

	return (NULL);
}
