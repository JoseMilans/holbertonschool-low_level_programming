#include "main.h"
/**
 * _sqrt_recursive - Helper function to compute the square root recursively.
 * @n: The number to compute the square root of.
 * @guess: The current guess for the square root.
 *
 * Return: The square root of n if found, -1 otherwise.
 */
int _sqrt_recursive(int n, int guess)
{
	if (guess * guess == n)
	{
		return (guess);
	}
	if (guess * guess > n)
	{
		return (-1);
	}
	return (_sqrt_recursive(n, guess + 1));
}
/**
 * _sqrt_recursion - Computes the natural square root of a number.
 * @n: The number to compute the square root of.
 *
 * Return: The natural square root of n.
 *         If n does not have a natural square root, returns -1.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	return (_sqrt_recursive(n, 0));
}
