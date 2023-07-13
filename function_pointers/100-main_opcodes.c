#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints the opcodes of its own main function.
 * @argc: number of command line arguments
 * @argv: array of command line argument strings
 * Return: 0 on success, 1 if incorrect number of arguments, 2 if negative
 * bytes
 */
int main(int argc, char *argv[])
{
	unsigned char *ptr = (unsigned char *)main;
	int i, bytes;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	bytes = atoi(argv[1]);
	if (bytes < 0)
	{
		printf("Error\n");
		return (2);
	}
	for (i = 0; i < bytes; i++)
	{
		printf("%.2x", *(ptr + i));
		if (i != bytes - 1)
			printf(" ");
	}
	printf("\n");
	return (0);
}
