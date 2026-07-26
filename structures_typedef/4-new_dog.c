#include "dog.h"
#include <stdlib.h>

/**
 * _strlen - Returns the length of a string
 * @str: String to evaluate
 * Return: Length of string
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}

/**
 * _strcpy - Copies string from src to dest
 * @dest: Destination buffer
 * @src: Source string
 * Return: Pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * new_dog - Creates a new dog struct with copied strings
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Owner of the dog
 * Return: Pointer to new dog struct, or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;

	if (name == NULL || owner == NULL)
		return (NULL);

	/* 1. Allocate space for the struct */
	d = malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);

	/* 2. Allocate and copy 'name' */
	d->name = malloc(sizeof(char) * (_strlen(name) + 1));
	if (d->name == NULL)
	{
		free(d);
		return (NULL);
	}
	_strcpy(d->name, name);

	/* 3. Set primitive 'age' */
	d->age = age;

	/* 4. Allocate and copy 'owner' */
	d->owner = malloc(sizeof(char) * (_strlen(owner) + 1));
	if (d->owner == NULL)
	{
		free(d->name);
		free(d);
		return (NULL);
	}
	_strcpy(d->owner, owner);

	return (d);
}
