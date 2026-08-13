#include <stdlib.h>
#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list.
 * @head: Pointer to the head of the dlistint_t list.
 * @index: Index of the node to return, starting from 0.
 *
 * Return: Address of the nth node, or NULL if it does not exist.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	/* Loop through the list while head is not NULL */
	for (i = 0; head != NULL && i < index; i++)
	{
		head = head->next;
	}
	return (head);
}
