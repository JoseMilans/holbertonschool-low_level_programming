#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PASSWORD_LENGTH 15
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char password[PASSWORD_LENGTH + 1];

	srand(time(0));
	for (int i = 0; i < PASSWORD_LENGTH; i++)
	{
		password[i] = rand() % 94 + 33;
	}
	password[PASSWORD_LENGTH] = '\0';
	printf("%s\n", password);
	return (0);
}
