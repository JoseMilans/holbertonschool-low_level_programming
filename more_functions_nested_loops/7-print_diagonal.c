#include "main.h"
/**
 * print_diagonal - Draws a diagonal line in the terminal
 * @n: The number of times the character '\' should be printed
 */
void print_diagonal(int n)
{
	int i = 0, j;

	if (n > 0)
	{
		while (i < n)
		{
			while (j < i)
			{
				_putchar(' ');
				j++;
			}
			i++;
			j = 0;
			_putchar('\\');
			_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
