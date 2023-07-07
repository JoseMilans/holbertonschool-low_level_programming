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
	int i, j, len, count, index;

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
	index = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
			continue;
		{
			len = 0;
			for (j = i; str[j] != ' ' && str[j] != '\0'; j++)
				len++;
			words[index] = malloc(sizeof(char) * (len + 1));
			if (words[index] == NULL)
			{
				for (j = 0; j < index; j++)
					free(words[j]);
				free(words);
				return (NULL);
			}
			for (j = 0; j < len; j++, i++)
				words[index][j] = str[i];
			words[index][j] = '\0';
			index++;
		}
	}
	words[index] = NULL;
	return (words);
}
