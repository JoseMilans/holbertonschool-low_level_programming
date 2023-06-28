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
	int i;
	int sum;
	char password[100];

	srand(time(0));

	sum = 2772;
	i = 0;

	while (sum > 126)
	{
		password[i] = rand() % 94 + 33;
		sum -= password[i];
		i++;
	}

	password[i] = sum;
	password[i + 1] = '\0';

	printf("%s", password);

	return (0);
}
