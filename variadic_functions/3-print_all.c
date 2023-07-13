#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"
/**
 * print_all - prints anything depend on the format string
 * @format: the format string specifying the types of arguments
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i = 0;
	char *str;
	int num;
	char ch;
	float flt;

	va_start(args, format);
	while (format && format[i])
	{
		switch (format[i])
		{
			case 'c':
				ch = va_arg(args, int);
				printf("%c", ch);
				break;
			case 'i':
				num = va_arg(args, int);
				printf("%d", num);
				break;
			case 'f':
				flt = va_arg(args, double);
				printf("%f", flt);
				break;
			case 's':
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(nil)";
				printf("%s", str);
				break;
			default:
				i++;
				continue;
		}
		if (format[i + 1])
			printf(", ");
		i++;
	}
	va_end(args);
	printf("\n");
}
