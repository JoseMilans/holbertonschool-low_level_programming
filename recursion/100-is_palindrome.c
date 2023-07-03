#include "main.h"

int _is_palindrome(char *s, int start, int end);

/**
 * is_palindrome - Checks if a string is a palindrome
 * @s: The string to check
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int length = 0;
    /* Calculate the length of the string */
	while (s[length] != '\0')
		length++;
	return (_is_palindrome(s, 0, length - 1));
}

/**
 * _is_palindrome - Recursive helper function to check if a string is a
 * palindrome
 * @s: The string to check
 * @start: The starting index of the string
 * @end: The ending index of the string
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int _is_palindrome(char *s, int start, int end)
{
    /*
	 * Base case: if the start index crosses or equals the end index, it's a
	 * palindrome
	 */
	if (start >= end)
		return (1);
    /*
	 * If the characters at start and end indices are different, it's not
	 * a palindrome
	 */
	if (s[start] != s[end])
		return (0);
    /* Recursively check the substring by moving the start and end indices */
	return (_is_palindrome(s, start + 1, end - 1));
}
