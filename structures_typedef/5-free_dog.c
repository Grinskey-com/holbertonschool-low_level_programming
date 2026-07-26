#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - Frees memory allocated for a dog_t struct
 * @d: Pointer to dog_t struct to free
 */
void free_dog(dog_t *d)
{
	/* Guard against NULL pointers */
	if (d == NULL)
		return;

	/* Free inner heap buffers first */
	if (d->name != NULL)
		free(d->name);

	if (d->owner != NULL)
		free(d->owner);

	/* Free outer struct container last */
	free(d);
}
