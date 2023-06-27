#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char password[7];
	int i;

	srand(time(0));
	for (i = 0; i < 7; i++)
	{
		password[i] = rand() % 94 + 33;
	}
	password[6] = '\0';
	printf("%s\n", password);
	return (0);
}
