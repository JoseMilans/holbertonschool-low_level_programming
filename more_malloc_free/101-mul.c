#include "main.h"
#include <stdlib.h>
#include <unistd.h>
/**
 * main - Entry point
 * @argc: Number of command line arguments
 * @argv: Array of command line arguments
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
	char *num1, *num2, *result;
	int len1, len2, lenRes, i;

	if (argc != 3)
	{
		printError();
		return (1);
	}
	num1 = argv[1];
	num2 = argv[2];
	len1 = findLength(num1);
	len2 = findLength(num2);
	if (len1 == 0 || len2 == 0)
	{
		printError();
		return (1);
	}
	result = multiply(num1, num2);
	lenRes = findLength(result);
	i = 0;
	while (result[i] == '0' && i < lenRes - 1)
		i++;
	write(1, result + i, lenRes - i);
	write(1, "\n", 1);
	free(result);
	return (0);
}
/**
 * multiply - Multiply two numbers
 * @num1: First number as a string
 * @num2: Second number as a string
 * Return: Pointer to the result as a string
 */
char *multiply(char *num1, char *num2)
{
	int len1, len2, lenRes, i, j, n1, n2, carry, product;
	char *result;

	len1 = findLength(num1);
	len2 = findLength(num2);
	lenRes = len1 + len2;
	result = malloc(sizeof(char) * (lenRes + 1));
	if (result == NULL)
		printError();
	for (i = 0; i < lenRes; i++)
		result[i] = '0';
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		n1 = num1[i] - '0';
		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			product = (n1 * n2) + (result[i + j + 1] - '0') + carry;
			result[i + j + 1] = (product % 10) + '0';
			carry = product / 10;
		}
		if (carry > 0)
			result[i + j + 1] += carry;
	}
	return (result);
}

/**
 * findLength - Calculate the length of a string
 * @str: The input string
 * Return: The length of the string
 */
int findLength(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}
/**
 * printError - Print error message and exit with status 1
 */
void printError(void)
{
	write(2, "Error\n", 6);
	exit(98);
}
