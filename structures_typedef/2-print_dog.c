#include "dog.h"
#include <stdio.h>

/**
 * print_dog - Prints a struct dog
 * @d: Pointer to struct dog to print
 */
void print_dog(struct dog *d)
{
	/* If d is NULL, do nothing */
	if (d == NULL)
		return;

	/* Print Name */
	if (d->name == NULL)
		printf("Name: (nil)\n");
	else
		printf("Name: %s\n", d->name);

	/* Print Age (floats can't be NULL) */
	printf("Age: %f\n", d->age);

	/* Print Owner  */
	if (d->owner == NULL)
		printf("Owner: (nil)\n");
	else
		printf("Owner: %s\n", d->owner);
}
