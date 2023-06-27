#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * infinite_add - Adds two numbers
 * @n1: First number as a string
 * @n2: Second number as a string
 * @r: Buffer to store the result
 * @size_r: Size of the buffer
 *
 * Return: Pointer to the result
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = 0, len2 = 0, i, j, sum, carry = 0;
	int max_length = size_r - 1;

	while (n1[len1])
		len1++;

	while (n2[len2])
		len2++;

	if (len1 > max_length || len2 > max_length)
		return (NULL);

	i = len1 - 1;
	j = len2 - 1;
	r[max_length] = '\0';

	while (i >= 0 || j >= 0)
	{
		sum = carry;

		if (i >= 0)
			sum += n1[i] - '0';

		if (j >= 0)
			sum += n2[j] - '0';

		carry = sum / 10;
		r[--max_length] = (sum % 10) + '0';

		i--;
		j--;
	}

	if (carry != 0)
	{
		if (max_length == 0)
			return (NULL);
		r[--max_length] = carry + '0';
	}

	return (&r[max_length]);
}

