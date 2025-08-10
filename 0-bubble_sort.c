#include "sort.h"
/**
 * bubble_sort - bubble sort
 * @array: integers
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	while (1)
	{
		size_t c = 0, i;

		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				int t = array[i];

				array[i] = array[i + 1];
				array[i + 1] = t;
				print_array(array, size);
				c++;
			}
		}
		if (c == 0)
			break;
	}
}
