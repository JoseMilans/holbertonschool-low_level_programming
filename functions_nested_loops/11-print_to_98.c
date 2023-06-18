#include "main.h"
/**
 * print_to_98 - Prints all natural numbers from n to 98.
 * @n: The starting number.
 */
void print_to_98(int n)
{
	int i = n;

	while (1)
	{
		if (i <= 98)
		{
			if (i < 0)
			{
				_putchar('-');
				if (i > -10)
					_putchar('0' + (-i));
				else
				{
					_putchar('0' + (-i) / 10);
					_putchar('0' + (-i) % 10);
				}
			}
			else
			{
				if (i < 10)
					_putchar('0' + i);
				else
				{
					_putchar('0' + i / 10);
					_putchar('0' + i % 10);
				}
			}
		}
		else
		{
			_putchar(' ');
			if (i > 100)
				_putchar('0' + i / 100);
			_putchar('0' + (i % 100) / 10);
			_putchar('0' + (i % 100) % 10);
		}
		if (i == 98)
		break;
		_putchar(',');
		_putchar(' ');
		if (i < 98)
			i++;
		else
			i--;
	}
	_putchar('\n');
}
