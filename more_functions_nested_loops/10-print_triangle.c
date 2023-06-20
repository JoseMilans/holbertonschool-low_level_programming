#include "main.h"
/**
 * print_triangle - Prints a triangle in the terminal
 * @size: The size of the triangle
 */
void print_triangle(int size)
{
	int row = 0, col, spaces;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}
	while (row < size)
	{
		spaces = size - row - 1;
		col = 0;
		while (col < size)
		{
			if (col < spaces)
				_putchar(' ');
			else
				_putchar('#');
			col++;
		}
		_putchar('\n');
		row++;
	}
}
