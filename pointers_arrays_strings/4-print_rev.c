#include "main.h"
/**
 * print_rev - Prints a string in reverse, followed by a new line
 * @s: The string to be printed in reverse
 */
void print_rev(char *s)
{
	int lenght = 0;

	while (s[lenght] != '\0')
		lenght++;
	while (lenght >= 0)
	{
		_putchar(s[lenght]);
		lenght--;
	}
	_putchar('\n');
}
