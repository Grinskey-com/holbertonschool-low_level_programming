#include <stdio.h>
#include "lists.h"

/**
 * add_dnodeint - Adds a new node at the beginning of a dlistint_t list.
 * @head: Double pointer to the head of the dlistint_t list.
 * @n: Int value to store in the new node.
 *
 * Return: Address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node;

	if (head == NULL)
		return (NULL);

	/* malloc new node */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	/* node data */
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;

	/* link old head to new node */
	if (*head != NULL)
		(*head)->prev = new_node;

	/* update head */
	*head = new_node;

	return (new_node);
}
