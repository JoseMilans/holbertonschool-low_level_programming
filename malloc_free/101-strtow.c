#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * strtow - splits a string into words
 * @str: the string to split
 * Return: pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, len, count;

	if (str == NULL || *str == '\0')
		return (NULL);
	count = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
	}
	words = malloc(sizeof(char *) * (count + 1));
	if (words == NULL)
		return (NULL);
	k = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			len = 0;
			for (j = i; str[j] != '\0' && str[j] != ' '; j++)
				len++;
			words[k] = malloc(sizeof(char) * (len + 1));
			if (words[k] == NULL)
			{
				for (j = 0; j < k; j++)
					free(words[j]);
				free(words);
				return (NULL);
			}
			for (j = 0; j < len; j++)
				words[k][j] = str[i++];
			words[k][j] = '\0';
			k++;
		}
	}
	words[k] = NULL;
	return (words);
}
