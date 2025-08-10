#include "sort.h"
#include <stdlib.h>
/**
 * swap - swap two elements
 * @array: array
 * @a: first index
 * @b: second index
 */
void swap(int *array, size_t a, size_t b)
{
	if (a != b)
	{
		int t = array[a];

		array[a] = array[b];
		array[b] = t;
	}
}
/**
 * partition - partition algorithm lomuto
 * @array: beginning of array
 * @start: start index
 * @end: ending index
 * @size: size of array
 *
 * Return: size of first partition
 */
int partition(int *array, size_t start, size_t end, size_t size)
{
	int count = 0;
	size_t i;

	for (i = start; i <= end; i++)
	{
		if (array[i] <= array[end])
		{
			if (i != start + (size_t) count)
			{
				swap(array, i, start + (size_t) count);
				print_array(array, size);
			}
			count++;
		}
	}
	return (count - 1);
}
/**
 * quick_sort - sort array using quick sort
 * @array: array of integers
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (size > 1)
	{
		int *ids = malloc(sizeof(int) * size * 2);
		size_t c = 1;

		if (ids)
		{
			ids[0] = 0;
			ids[1] = size - 1;
			while (c > 0)
			{
				int a = (c - 1) * 2, b = (c - 1) * 2 + 1, l;

				if (ids[b] == ids[a])
				{
					c--;
					continue;
				}
				l = partition(array, ids[a], ids[b], size);
				if (l > 0)
				{
					ids[a + 2] = ids[a];
					ids[b + 2] = ids[a] + l - 1;
					c++;
				}
				ids[a] += l;
			}
			free(ids);
		}
	}
}
