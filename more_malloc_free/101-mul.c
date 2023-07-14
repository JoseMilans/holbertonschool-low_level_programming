#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * error - prints an error message and exits.
 */
void error(void)
{
    fprintf(stderr, "Error\n");
    exit(98);
}

/**
 * _isdigit - check if a character is a digit.
 * @c: character to check.
 * Return: 1 if c is a digit, 0 otherwise.
 */
int _isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

/**
 * mul - multiplies two large numbers.
 * @num1: first number.
 * @num2: second number.
 * Return: result of multiplication.
 */
char *mul(char *num1, char *num2)
{
    int i, j, mul, sum;
    int len1 = strlen(num1), len2 = strlen(num2);
    int len = len1 + len2;
    char *res = calloc(len + 1, sizeof(char));

    if (!res)
        error();

    for (i = len1 - 1; i >= 0; i--)
    {
        if (!_isdigit(num1[i]))
            error();

        for (j = len2 - 1; j >= 0; j--)
        {
            if (!_isdigit(num2[j]))
                error();

            mul = (num1[i] - '0') * (num2[j] - '0');
            sum = res[i + j + 1] + mul;

            res[i + j + 1] = sum % 10;
            res[i + j] += sum / 10;
        }
    }

    for (i = 0; i < len; i++)
        res[i] += '0';

    /* remove leading zeros */
    while (*res && *res == '0') 
        memmove(res, res + 1, len--);

    return (res);
}

/**
 * main - Entry point.
 * @argc: arguments count.
 * @argv: arguments vector.
 * Return: 0 in success, 1 in error.
 */
int main(int argc, char **argv)
{
    char *res;

    if (argc != 3)
        error();

    res = mul(argv[1], argv[2]);
    printf("%s\n", *res ? res : "0");
    free(res);

    return (0);
}

