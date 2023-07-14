#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * error_exit - Prints "Error" and exits the program with a status of 98.
 */
void error_exit()
{
    printf("Error\n");
    exit(98);
}

/**
 * mul - Multiplies two numbers passed as strings.
 * @num1: The first number.
 * @num2: The second number.
 */
void mul(char *num1, char *num2)
{
    int i, j, len1 = strlen(num1), len2 = strlen(num2);
    int *buf = calloc(len1 + len2 + 1, sizeof(int));

    if (!buf)
        error_exit();

    for (i = len1 - 1; i >= 0; i--)
    {
        if (!isdigit(num1[i]))
            error_exit();
        for (j = len2 - 1; j >= 0; j--)
        {
            if (!isdigit(num2[j]))
                error_exit();
            buf[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
        }
    }

    for (i = len1 + len2 - 1; i > 0; i--)
    {
        buf[i - 1] += buf[i] / 10;
        buf[i] %= 10;
    }

    i = 0;
    while (!buf[i] && i < len1 + len2)
        i++;

    while (i < len1 + len2)
        putchar(buf[i++] + '0');
    putchar('\n');

    free(buf);
}

/**
 * main - Entry point.
 * @argc: The number of command line arguments.
 * @argv: The command line arguments.
 *
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char **argv)
{
    if (argc != 3)
        error_exit();

    mul(argv[1], argv[2]);
    return (0);
}

