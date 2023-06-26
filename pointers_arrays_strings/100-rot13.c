#include "main.h"
/**
 * rot13 - Encodes a string using ROT13 cipher.
 * @s: The string to encode.
 *
 * Return: A pointer to the encoded string.
 */
char *rot13(char *s)
{
	char *ptr = s;
	int i;
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	while (*ptr)
	{
		for (i = 0; i < 52; i++)
		{
			if (*ptr == alphabet[i])
			{
				*ptr = rot13[i];
				break;
			}
		}
		ptr++;
	}
	return (s);
}
