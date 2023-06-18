#include "main.h"
int _putchar(char c);
/**
 * print_number - Prints a number
 * @n: The number to be printed
 */
void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	if (n / 10 != 0)
		print_number(n / 10);

	_putchar((n % 10) + '0');
}
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
			if (i != 98)
			{
				print_number(i);
				_putchar(',');
				_putchar(' ');
			}
			else
			{
				print_number(i);
			}
		}
	}
	else
	{
		for (i = n; i >= 98; i--)
		{
			if (i != 98)
			{
				print_number(i);
				_putchar(',');
				_putchar(' ');
			}
			else
			{
				print_number(i);
			}
		}
	}
	_putchar('\n');
}
