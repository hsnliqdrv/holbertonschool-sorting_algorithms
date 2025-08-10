#include "sort.h"
/**
 * min - find minimum of array
 * @array: array
 * @size: size of array
 *
 * Return: index of min
 */
size_t min(int *array, size_t size)
{
	size_t m = 0, i;

	for (i = 1; i < size; i++)
	{
		if (array[i] < array[m])
			m = i;
	}
	return (m);
}
/**
 * selection_sort - sort array using selection
 * @array: array of int
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0;

	while (i < size)
	{
		size_t m = i + min(array + i, size - i);

		if (m != i)
		{
			int t = array[m];

			array[m] = array[i];
			array[i] = t;
			print_array(array, size);
		}
		i++;
	}
}
