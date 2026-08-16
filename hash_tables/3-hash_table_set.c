#include <stdlib.h>
#include <string.h>
#include "hash_tables.h"

/**
 * hash_table_set - Adds or updates an element in the hash table.
 * @ht: The hash table to add/update.
 * @key: The key string (cannot be empty).
 * @value: The value string to store (must be duplicated).
 *
 * Return: 1 if successful, 0 otherwise.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *current, *new_node;
	char *val_copy, *key_copy;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	val_copy = strdup(value);
	if (val_copy == NULL)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);

	/* Check if key already exists to update value */
	current = ht->array[idx];
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = val_copy;
			return (1);
		}
		current = current->next;
	}

	/* Key does not exist: create new node and prepend to chain */
	key_copy = strdup(key);
	if (key_copy == NULL)
	{
		free(val_copy);
		return (0);
	}

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
	{
		free(key_copy);
		free(val_copy);
		return (0);
	}

	new_node->key = key_copy;
	new_node->value = val_copy;
	new_node->next = ht->array[idx];
	ht->array[idx] = new_node;

	return (1);
}
