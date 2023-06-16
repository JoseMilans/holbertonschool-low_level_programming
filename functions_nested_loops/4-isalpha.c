#include "main.h"
/**
 * int _isalpha - Checks if a character is lowercase.
 * @c: The character to be checked.
 *
 * Return: 1 if c is lowercase or uppercase, 0 otherwise.
 */
int _islower(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
