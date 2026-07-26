#ifndef DOG_H
#define DOG_H

/**
 * struct dog - A structure representing basic info about a dog
 * @name: Name of the dog (string)
 * @age: Age of the dog (float)
 * @owner: Owner's name (string)
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/**
 * dog_t - Typedef for struct dog
 */
typedef struct dog dog_t;

/* Function prototypes */
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif /* DOG_H */
