#include "main.h"
/**
 * print_to_98 - Prints all natural numbers from n to 98.
 * @n: The starting number.
 */
int _putchar(char c);

void print_to_98(int n)
{
    while (1)
    {
        if (n < 0)
        {
            _putchar('-');
            n = -n;
        }

        if (n / 100)
            _putchar((n / 100) + '0');

        if (n / 10)
            _putchar((n / 10) % 10 + '0');

        _putchar((n % 10) + '0');

        if (n == 98)
            break;

        _putchar(','), _putchar(' ');

        if (n < 98)
            n++;
        else
            n--;
    }

    _putchar('\n');
}
