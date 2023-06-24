#include "main.h"
/**
 * _strspn - Gets the length of a prefix substring.
 * @s: The string to be evaluated.
 * @accept: The bytes to be counted.
 *
 * Return: Number of bytes in the initial segment of s that consist only
 *         of bytes from accept.
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int i, j;
	int found;

	for (i = 0; s[i] != '\0'; i++)
	{
		found = 0;
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				found = 1;
				break;
			}
		}
		if (found == 0)
			break;
		count++;
	}
	return (count);
}
