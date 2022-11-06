#include "sort.h"
#include <stdio.h>

void sort(int *array, int start_point, size_t half)
{
	int temp;
	
	if (half < 2)
	{
		printf("Merging...\n");
		printf("[left]: %d\n", array[start_point]);
		printf("[right]: %d\n", array[half]);
		if (array[start_point] > array[half])
		{
			temp = array[half];
			array[half] = array[start_point];
			array[start_point] = temp;
			return;
		}

	}
}
void merge_sort(int *array, size_t size)
{
	size_t half = size / 2, prev = half;


	while (half >= 2)
	{
		printf("first half %lu\n", half - 1);
		sort(array, 0, half - 1);
		printf("second half %lu------size %lu\n", half, prev);
		sort(array, half, prev);
		prev = half - 1;
		half = half / 2;

	}
}
