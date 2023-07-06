#include "main.h"
#include <stdlib.h>
/**
 * _calloc - Allocates memory for an array using malloc
 * @nmemb: The number of elements in the array
 * @size: The size of each element in bytes
 *
 * Return: A pointer to the allocated memory
 *         NULL if nmemb or size is 0, or if malloc fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;
	unsigned int i;
	char *chPtr;
    /* Check for zero values */
	if (nmemb == 0 || size == 0)
		return (NULL);
    /* Allocate memory using malloc */
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
    /* Set all bytes in the allocated memory to 0 */
	chPtr = ptr;
	for (i = 0; i < nmemb * size; i++)
		chPtr[i] = 0;
	return (ptr);
}
