#include "dog.h"
#include <stdio.h>
/**
 * init_dog - Initialises struct dog.
 * @d: Pointer to the struct dog.
 * @name: Dog's age.
 * @age: Dog's age.
 * @owner: Dog's owner.
 *
 * Return: void
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}

