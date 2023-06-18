#include "main.h"
#include <stdio.h>
/**
 * print_to_98 - Prints all natural numbers from n to 98.
 * @n: The starting number.
 */
void print_to_98(int n)
{
	int i;

	if (n <= 98)
	{
		for (i = n; i <= 98; i++)
		{
			if (i == -10)
			{
				_putchar('-');
				_putchar('1');
				_putchar('0');
			}
			else if (i < 0)
			{
				_putchar('-');
				_putchar('0' - i);
			}
			else if (i < 10)
			{
				_putchar('0' + i);
			}
			else
			{
				_putchar((i / 10) + '0');
				_putchar((i % 10) + '0');
			}
			if (i != 98)
			{
				_putchar(',');
				_putchar(' ');
			}
		}
	}
	_putchar('\n');
}
