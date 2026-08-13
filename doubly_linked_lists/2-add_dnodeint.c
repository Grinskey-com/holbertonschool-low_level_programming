#include <stdio.h>
#include "lists.h"

/**
 * print_dlistint - Prints all the elements of a dlistint_t list.
 * @h: Pointer to the head of the dlistint_t list.
 *
 * Return: The number of nodes in the list.
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
