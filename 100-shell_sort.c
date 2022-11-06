#include "sort.h"
#include <stdio.h>
/**
 * gap_index - Returns index
 *
 * @size: Takes size of array
 *
 * Return: index
 */
int gap_index(size_t size)
{
	if (size <= 7)
		return (0);
	else if ((size > 7) && (size <= 25))
		return (1);
	else if ((size > 25) && (size <= 79))
		return (2);
	else if ((size > 79) && (size <= 240))
		return (3);
	return (4);
}
/**
 * swap - swaps postion
 *
 * @array: array
 *
 * @i: position i
 *
 * @j: position j
 *
 * Return: void
 */
void swap(int *array, int i, int j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
/**
 * shell_sort - sorts an array of integers in ascending order
 *
 * @array: array to be sorted
 *
 * @size: size of array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	int i, gap_list[] = {1, 4, 13, 40, 121};
	int index = gap_index(size), gap, m, temp;
	size_t j;

	for (; index >= 0; index--)
	{
		gap = gap_list[index];
		j = gap;
		for (i = 0; j < size; i++)
		{
			if (array[i] > array[j])
				swap(array, i, j);
			if (gap > 1)
			{
				if ((i - gap >= 0) && (array[i] < array[i - gap]))
					swap(array, i - gap, i);
			}
			else
			{
				for (m = i; m >= 1; m--)
				{
					if (array[m] < array[m - 1])
					{
						temp = array[m];
						array[m] = array[m - 1];
						array[m - 1] = temp;
					}

				}

			}
			j++;
		}
		print_array(array, size);
	}
}
