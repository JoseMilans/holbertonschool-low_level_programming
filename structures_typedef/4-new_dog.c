#include <stdio.h>
#include <stdlib.h>
#include "dog.h"
/**
 * new_dog - Creates a new dog.
 * @name: Dog's name.
 * @age: Dog's age.
 * @owner: Dog's owner.
 * Return: Pointer to new dog or NULL if function fails.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog;
	char *name_copy;
	char *owner_copy;
	int name_len = 0;
	int owner_len = 0;
	int i;

	while (name[name_len])
		name_len++;
	while (owner[owner_len])
		owner_len++;
	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
		return (NULL);
	name_copy = malloc(sizeof(char) * (name_len + 1));
	owner_copy = malloc(sizeof(char) * (owner_len + 1));
	if (name_copy == NULL || owner_copy == NULL)
	{
		free(name_copy);
		free(owner_copy);
		free(new_dog);
		return (NULL);
	}
	for (i = 0; i <= name_len; i++)
		name_copy[i] = name[i];
	for (i = 0; i <= owner_len; i++)
		owner_copy[i] = owner[i];
	new_dog->name = name_copy;
	new_dog->age = age;
	new_dog->owner = owner_copy;
	return (new_dog);
}
