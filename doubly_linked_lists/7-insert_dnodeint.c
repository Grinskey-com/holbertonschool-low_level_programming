#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position.
 * @h: Double pointer to the head of the dlistint_t list.
 * @idx: Index of the list where the new node should be added.
 * @n: Integer value to store in the new node.
 *
 * Return: Address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node;
	dlistint_t *temp;
	unsigned int i;

	if (h == NULL)
		return (NULL);

	/* insert at head */
	if (idx == 0)
		return (add_dnodeint(h, n));

	/* walk to node at idx - 1 */
	temp = *h;
	for (i = 0; temp != NULL && i < idx - 1; i++)
		temp = temp->next;

	/* out of bounds check */
	if (temp == NULL)
		return (NULL);

	/* insert at end */
	if (temp->next == NULL)
		return (add_dnodeint_end(h, n));

	/* insert in middle */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = temp->next;
	new_node->prev = temp;
	temp->next->prev = new_node;
	temp->next = new_node;

	return (new_node);
}
