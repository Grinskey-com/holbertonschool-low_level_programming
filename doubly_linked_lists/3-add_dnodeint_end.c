#include <stdio.h>
#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a dlistint_t list.
 * @head: Double pointer to the head of the dlistint_t list.
 * @n: Integer value to store in the new node.
 *
 * Return: Address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	dlistint_t *temp;

	if (head == NULL)
		return (NULL);

	/* malloc new node */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	/* Empty list? */
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	/* walk the old nodes to the end */
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;

	/* connect old tail(temp) with new node */
	temp->next = new_node;
	new_node->prev = temp;

	return (new_node);
}
