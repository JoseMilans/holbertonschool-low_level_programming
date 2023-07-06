#include "main.h"
#include <stdlib.h>
/**
 * string_nconcat - Concatenates two strings
 * @s1: The first string
 * @s2: The second string
 * @n: The number of bytes of s2 to concatenate
 * Return: A pointer to the newly allocated concatenated string.
 *         NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1 = 0, len2 = 0, i, j;
	char *concat;
	/* Calculate the lengths of s1 and s2 */
	if (s1 != NULL)
	{
		while (s1[len1] != '\0')
			len1++;
	}
	if (s2 != NULL)
	{
		while (s2[len2] != '\0')
			len2++;
	}
	/* Adjust n if it is >= to the length of s2 */
	if (n >= len2)
		n = len2;
	/* Allocate memory for the concatenated string */
	concat = malloc(sizeof(char) * (len1 + n + 1));
	if (concat == NULL)
		return (NULL);
	/* Copy s1 to the beginning of concat */
	for (i = 0; i < len1; i++)
		concat[i] = s1[i];
	/* Copy n bytes of s2 after s1 in concat */
	for (j = 0; j < n; j++)
		concat[i++] = s2[j];
	/* Null-terminate the concatenated string */
	concat[i] = '\0';
	return (concat);
}
