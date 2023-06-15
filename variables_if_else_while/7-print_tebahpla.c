#include <stdio.h>
/**
 * main - prints the lowercase alphabet in reverse.
 *
 * Return: always 0.
 */
int main(void)
{
	int i;

	for (i = 'z'; i >= 'a'; i--)
	{
		putchar(i);
	}
	putchar('\n');
	return (0);
}
