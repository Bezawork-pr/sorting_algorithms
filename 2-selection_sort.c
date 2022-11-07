#include "sort.h"
/**
 *selection_sort - C implementation of selction sort
 *
 * @array: array to be sorted
 *
 * @size: size of array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t minNumIndex, j, i;
	int minNum;

	for (i = 0; i < size - 1; i++)
	{
		minNum = array[i];
		for (j = i; j < size; j++)
		{
			if (array[j] < minNum)
			{
				minNum = array[j];
				minNumIndex = j;
			}
		}

		array[minNumIndex] = array[i];
		array[i] = minNum;
		print_array(array, size);
	}
}
