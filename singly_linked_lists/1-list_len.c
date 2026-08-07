#include <stdio.h>
#include "lists.h"

/**
 * list_len- count of the nomber of nodes in list.
 * @h: Pointer to the head of the list_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t list_len(const list_t *h)
{
	/* set count to 0 */
	size_t count = 0;

	/* loop thru str plus NUll guard */
	while (h != NULL)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else

		count++; /* increment count */
		h = h->next; /* point to next node */
	}

	return (count);
}
