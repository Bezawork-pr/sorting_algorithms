#include "sort.h"
#include <stdio.h>
/**
 * gapcalc - Returns index
 *
 * @size: Takes size of array
 *
 * Return: index
 */
unsigned int gapcalc(size_t size)
{
	unsigned int gap = 1;

	while (gap < size)
		gap = 3 * gap + 1;
	if (gap >= size)
		gap = (gap - 1) / 3;
	return (gap);
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
	int i, gap = gapcalc(size), m, temp, flag;
	size_t j;

	if (array == NULL)
		return;
	for (; gap > 0; gap = (gap - 1) / 3)
	{
		j = gap;
		flag = 0;
		for (i = 0; j < size; i++)
		{
			if (array[i] > array[j])
			{
				swap(array, i, j);
				flag = 1;
			}
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
						flag = 1;
					}
				}
			}
			j++;
		}
		if (flag == 1)
			print_array(array, size);
	}
}
