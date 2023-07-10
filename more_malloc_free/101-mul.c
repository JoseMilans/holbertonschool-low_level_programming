#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
/**
 * multiply - Multiplies two positive numbers
 * @num1: The first number
 * @num2: The second number
 * Return: The result of multiplication as a string
 */
char *multiply(char *num1, char *num2)
{
	int len1, len2, lenRes, i, j, prod, carry;
	char *result, *newResult;

	if (*num1 == '0' || *num2 == '0')
	{
		result = malloc(sizeof(char) * 2);
		if (result == NULL)
			return (NULL);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	len1 = strlen(num1);
	len2 = strlen(num2);
	lenRes = len1 + len2;
	result = malloc(sizeof(char) * (lenRes + 1));
	newResult = result;
	if (result == NULL)
		return (NULL);
	for (i = 0; i < lenRes; i++)
		result[i] = '0';
	result[lenRes] = '\0';
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			prod = (num1[i] - '0') * (num2[j] - '0') +
				(result[i + j + 1] - '0') + carry;
			carry = prod / 10;
			result[i + j + 1] = (prod % 10) + '0';
		}
		result[i] += carry;
	}
	if (result[0] == '0')
	{
		newResult = malloc(sizeof(char) * lenRes);
		if (newResult == NULL)
		{
			free(result);
			return (result);
		}
		strcpy(newResult, result + 1);
		free(result);
		return newResult;
	}
	return (result);
}
/**
 * isPositiveNumber - Checks if a string represents a positive number
 * @str: The string to check
 * Return: 1 if the string represents a positive number, 0 otherwise
 */
int isPositiveNumber(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	return (1);
}
/**
 * main - Entry point
 * @argc: The number of commandline arguments
 * @argv: An array of commandline argument strings
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
	char *num1, *num2, *result;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	num1 = argv[1];
	num2 = argv[2];
	if (!isPositiveNumber(num1) || !isPositiveNumber(num2))
	{
		printf("Error\n");
		return (1);
	}
	result = multiply(num1, num2);
	if (result == NULL)
	{
		printf("Error\n");
		return (1);
	}
	printf("%s\n", result);
	free(result);
	return (0);
}
