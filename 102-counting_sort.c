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
	int Maxnum = array[0], i;

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
	int outputArray[100], index_array[1000], sum = 0, new_index, index;


	/*outputArray = malloc(sizeof(int) * size);
	index_array = malloc(sizeof(int) * (Maxnum + 1));*/
	if (/*outputArray == NULL || index_array == NULL ||*/ size < 2 ||  !array)
	{
		/*free(outputArray);
		free(index_array);*/
		return;
	}
	/*Initiate with 0 */
	for (i = 0; i <= Maxnum; i++)
		index_array[i] = 0;

	/* add to 0 everytime there is occurance */
	for (i = 0; i < size; i++)
	{

		index = array[i];
		index_array[index]++;
	}
	/* set index based on occurance and ascending order*/
	for (i = 0; i <= Maxnum; i++)
	{
		sum += index_array[i];
		index_array[i] = sum;
	}
	print_array(index_array, Maxnum + 1);
	/* Get occurance and order from index array and save to newarray */
	for (i = 0; i < size; i++)
	{
		index = array[i];
		new_index = index_array[index]- 1;
		index_array[index]--;
		outputArray[new_index] = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] = outputArray[i];
	/*free(outputArray);
	free(index_array);*/
}
