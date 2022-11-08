#include "sort.h"
/**
 * getpivot - checks and swaps
 *
 * @array : pointer to the array to be modified
 *
 * @lo: starting index
 *
 * @hi: finishing index
 *
 * @size: size of array
 *
 * Return: index of Pivot
 */
int getpivot(int *array, int lo, int hi, size_t size)
{
	int i = lo - 1, j, pivot, temp;

	pivot = array[hi];
	for (j = lo; j < hi; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
		}
	}
	i++;
	temp = array[i];
	array[i] = array[hi];
	array[hi] = temp;
	if (i != j)
		print_array(array, size);
	return (i);
}
/**
 * quicksort - recursive function
 *
 * @array: pointer to array
 *
 * @lo: low index
 *
 * @hi: finishing index
 *
 * @size: size of array
 *
 * Return: void
 */
void quicksort(int *array, int lo, int hi, size_t size)
{
	int pivotIndex;

	if (lo < hi)
	{
		pivotIndex = getpivot(array, lo, hi, size);
		quicksort(array, lo, (pivotIndex - 1), size);
		quicksort(array, (pivotIndex + 1), hi, size);
	}
}
/**
 * quick_sort - C implementation of quick sort algorithm
 *
 * @array: array to be sorted
 *
 * @size: size of array
 *
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
