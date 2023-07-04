#include "main.h"
#include <stdlib.h>
/**
 * create_array - creates an array of chars and initialises it with a specific
 *  char.
 * @size: The size of the array.
 * @c: The char to initialise the array with.
 *
 * Return: pointer to the array, or NULL if it fails.
 */
char *create_array(unsigned int size, char c)
{
	char *array;
	unsigned int i;

	if (size == 0)
		return (NULL);
	array = malloc(sizeof(char) * size);
	if (array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		array[i] = c;
	return (array);
}

