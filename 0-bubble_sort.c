#include "sort.h"
/**
 * bubble_sort - C implementation of the buble sort
 * algorithm
 *
 * @array: array to be sorted
 *
 * @size: size of the array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t n = size, newn, i;
	int temp;

	while (n > 1)
	{
		newn = 0;
		for (i = 1; i < n; i++)
		{
			if (array[i - 1] > array[i])
			{
				temp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = temp;
				newn = i;

				print_array(array, size);
			}
		}
		n = newn;
	}
}
