#include <stdlib.h>
#include "main.h"
/**
 * str_concat - Concatenates two strings.
 * @s1: Pointer to the first string.
 * @s2: Pointer to the second string.
 *
 * Return: Pointer to the newly allocated memory containing the concatenated
 * string,
 *         or NULL if the allocation fails.
 */
char *str_concat(char *s1, char *s2)
{
	char *concatenated;
	unsigned int length1 = 0, length2 = 0, i, j;

	if (s1 != NULL)
	{
		while (s1[length1] != '\0')
			length1++;
	}
	if (s2 != NULL)
	{
		while (s2[length2] != '\0')
			length2++;
	}
	concatenated = malloc(sizeof(char) * (length1 + length2 + 1));
	if (concatenated == NULL)
	{
		free(concatenated);
		return (NULL);
	}
	for (i = 0; i < length1; i++)
		concatenated[i] = s1[i];
	for (j = 0; j < length2; j++)
		concatenated[i + j] = s2[j];
	concatenated[i + j] = '\0';
	return (concatenated);
}
