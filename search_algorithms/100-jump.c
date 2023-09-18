#include "search_algos.h"
#include <math.h>

/**
 * jump_search - searches for a value in an array of integers using the
 * Jump search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 * Return: the first index where value is located or -1 if value is not found
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step, prev, i;

	if (!array)
		return (-1);

	step = sqrt(size);
	prev = 0;

	while (prev < size && array[prev] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", prev, array[prev]);
		prev += step;
	}
	if (prev >= size)
		printf("Value found between indexes [%lu] and [%lu]\n", prev - step, prev);
	else
		printf("Value found between indexes [%lu] and [%lu]\n", prev - step, prev);

	for (i = prev - step; i < prev && i < size; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}
