#include "search_algos.h"

/**
 * linear_search - searches for a value in an array using the Linear search
 * algorithm
 * @array: pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 *
 * Return: the first index where value is located or -1 if value is not found
 */
int linear_search(int *array, size_t size, int value)
{
	size_t i;

    /* Check if array is NULL */
	if (!array)
		return (-1);

	for (i = 0; i < size; i++)
	{
		/* Print the current value */
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);

		/* Check if the current value matches the searched value */
		if (array[i] == value)
			return (i);
	}

    /* Return -1 if value was not found */
	return (-1);
}
