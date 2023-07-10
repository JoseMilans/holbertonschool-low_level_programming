#include <stdio.h>
#include "function_pointers.h"
/**
 * print_name - prints a name
 * @name: someone's name
 * @f: pointer to a function that takes a char pointer as parameter
 *
 * Return: nothing
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
		f(name);
}

