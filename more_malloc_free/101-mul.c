#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * error_and_exit - print error message and exit
 */
void error_and_exit(void)
{
    printf("Error\n");
    exit(98);
}

/**
 * is_num - check if a string is a number
 * @num: string to check
 * Return: 1 if string is a number, 0 otherwise
 */
int is_num(char *num)
{
    int i;

    for (i = 0; num[i]; i++)
    {
        if (!isdigit(num[i]))
            return (0);
    }

    return (1);
}

/**
 * multiply - multiply two numbers
 * @num1: first number
 * @num2: second number
 * Return: result of multiplication as a string
 */
char *multiply(char *num1, char *num2)
{
    int len1 = strlen(num1), len2 = strlen(num2);
    int *res = malloc((len1 + len2) * sizeof(int));
    char *res_str = malloc((len1 + len2 + 1) * sizeof(char));
    int i, j;

    if (!res || !res_str)
        error_and_exit();

    for (i = 0; i < len1 + len2; i++)
        res[i] = 0;

    for (i = len1 - 1; i >= 0; i--)
    {
        for (j = len2 - 1; j >= 0; j--)
        {
            res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            res[i + j] += res[i + j + 1] / 10;
            res[i + j + 1] %= 10;
        }
    }

    for (i = 0; i < len1 + len2; i++)
        res_str[i] = '0' + res[i];

    res_str[i] = '\0';

    if (res_str[0] == '0')
        memmove(res_str, res_str + 1, strlen(res_str));

    free(res);
    return (res_str);
}

/**
 * main - multiply two numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 if successful, 98 otherwise
 */
int main(int argc, char *argv[])
{
    char *result;

    if (argc != 3)
    {
        error_and_exit();
    }

    if (!is_num(argv[1]) || !is_num(argv[2]))
    {
        error_and_exit();
    }

    result = multiply(argv[1], argv[2]);

    printf("%s\n", result);

    free(result);

    return (0);
}

