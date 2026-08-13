#include <stdlib.h>
#include "lists.h"

/**
 * free_dlistint - Frees a dlistint_t list.
 * @head: Pointer to the head of the dlistint_t list.
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head != NULL)
	{
		/* 1. Save the next node */
		temp = head->next;
		/* 2. Free current node */
		free(head);
		/* 3. Advance head to temp */
		head = temp;
	}
}
