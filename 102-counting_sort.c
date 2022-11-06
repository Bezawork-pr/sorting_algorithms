#include "sort.h"
#include <limits.h>
#include <stdio.h>
/**
 * get_max_int - gets the max int in the array
 *
 * @array: array
 *
 * @size: size of array
 *
 * Return: Max int
 */
int get_max_int(int *array, size_t size)
{
	int Maxnum = array[0];
	int i;

	for (i = size; i >= 0; i--)
	{
		if (array[i] > Maxnum)
			Maxnum = array[i];
	}
	return (Maxnum);

}
/**
 * counting_sort - implementation of the counting sort algorithm
 *
 * @array: array
 *
 * @size: size of array
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	size_t i, Maxnum = get_max_int(array, size);
	int *out_array, *index_array, sum = 0, new_index, index;


	out_array = malloc(sizeof(int) * size +5);
	index_array = malloc(sizeof(int) * Maxnum + 10);
	if (out_array == NULL || index_array == NULL || size == 2 ||  !array)
	{
		free(out_array);
		free(index_array);
		return;
	}
	for (i = 0; i <= Maxnum; i++)
		index_array[i] = 0;

	for (i = 0; i < size; i++)
	{

		index = array[i];
		index_array[index]++;
	}
	for (i = 0; i <= Maxnum; i++)
	{
		sum += index_array[i];
		index_array[i] = sum;
	}
	print_array(index_array, 100);
	for (i = 0; i < size; i++)
	{
		index = array[i];
		new_index = index_array[index]- 1;
		index_array[index]--;
		out_array[new_index] = array[i];

	}
	for (i = 0; i < size; i++)
		array[i] = out_array[i];
	free(out_array);
	free(index_array);
}
