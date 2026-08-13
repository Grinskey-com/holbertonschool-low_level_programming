#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - Deletes the node at index of a dlistint_t list.
 * @head: Double pointer to the head of the dlistint_t list.
 * @index: Index of the node that should be deleted.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	temp = *head;

	/* deleting the head node */
	if (index == 0)
	{
		*head = temp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}

	/* walk to node at target index */
	for (i = 0; temp != NULL && i < index; i++)
		temp = temp->next;

	/* index is out of bounds */
	if (temp == NULL)
		return (-1);

	/* unlink from prev */
	temp->prev->next = temp->next;

	/* unlink from next */
	if (temp->next != NULL)
		temp->next->prev = temp->prev;

	free(temp);
	return (1);
}
