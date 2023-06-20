#include "main.h"

/**
 * print_number - Prints an integer
 * @n: The integer to print
 */
void print_number(int n)
{
    if (n == 0)
    {
        _putchar('0');
        return;
    }
    else if (n < 0)
    {
        _putchar('-');
        if (n == INT_MIN)
        {
            print_number(-(n / 10));
            _putchar('8');
            return;
        }
        n = -n;
    }

    if (n / 10)
    {
        print_number(n / 10);
    }

    _putchar('0' + (n % 10));
}

