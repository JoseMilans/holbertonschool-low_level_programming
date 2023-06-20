#include <stdio.h>

/**
 * largest_prime_factor - Finds the largest prime factor of a number
 * @num: The number
 *
 * Return: The largest prime factor
 */
long largest_prime_factor(long num)
{
	long factor = 2;

	while (factor <= num)
	{
		if (num % factor == 0)
		{
			num /= factor;
		}
		else
		{
			factor++;
		}
	}
	return (factor);
}
/**
 * main - Entry point of the program
 *
 * Return: 0 on success
 */
int main(void)
{
	long number = 612852475143;
	long largest_factor = largest_prime_factor(number);

	printf("%ld\n", largest_factor);
	return (0);
}

