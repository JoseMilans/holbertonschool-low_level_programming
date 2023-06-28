#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PASSWORD_LENGTH 15
/**
 * main - Generates a random valid password for the crackme program.
 *
 * Return: Always 0.
 */
int main(void)
{
	int i;
	char password[PASSWORD_LENGTH + 1];

	srand(time(NULL));
	for (i = 0; i < PASSWORD_LENGTH; i++)
	{
		int randomValue;

		do {
			randomValue = rand() % 94 + 33;
		} while (randomValue == 127 || randomValue == 128);
		password[i] = (char)randomValue;
	}
	password[PASSWORD_LENGTH] = '\0';
	printf("%s\n", password);
	return (0);
}
