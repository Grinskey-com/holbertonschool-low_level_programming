#ifndef FUNCTION_POINTER_H
#define FUNCTION_POINTER_H

/**
 * file: function_pointers.h
 * desc: Header file containing function prototypes
 */

/**
 * print_name - prints a name using a given function pointer
 * @name: string to print
 * @f: pointer to the printing function
 */
void print_name(char *name, void (*f)(char *));

#endif /* FUNCTION_POINTER_H */
