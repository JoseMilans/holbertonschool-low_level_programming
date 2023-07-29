#include "main.h"
/**
 * flip_bits - returns the number of bits needed to be flipped to get from
 *             one number to another.
 * @n: the first number
 * @m: the second number
 * Return: the number of bits needed to be flipped to get from one number to
 * another
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_res = n ^ m;
	unsigned int flip_count = 0;

	while (xor_res)
	{
		flip_count += (xor_res & 1);
		xor_res >>= 1;
	}
	return (flip_count);
}
