#include "main.h"
#include <limits.h>
/**
 * _atoi - Converts a string to an integer
 * @s: The string to convert
 *
 * Return: The converted integer
 */
int _atoi(char *s)
{
	int sign = 1;
	int result = 0;
	int i = 0;

	while (s[i] && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
	{
		if (result == INT_MIN / 10 && (s[i] - '0') == 8)
		{
			return (INT_MIN);
		}
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result * sign);
}
