#include "sort.h"
#include <stdio.h>
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
	unsigned int minNumIndex, j, i;
	int minNum;

	if ((size < 2) || array == NULL)
		return;
	for (i = 0; i < size - 1; i++)
	{
		minNum = array[i];
		for (j = i /*+ 1*/; j < size; j++)
		{
			if (array[j] < minNum)
			{
				minNum = array[j];
				minNumIndex = j;
			}
		}
		/*if (i != minNumIndex)
		{*/
			array[minNumIndex] = array[i];
			array[i] = minNum;
			print_array(array, size);
		/*}*/
	}
}
