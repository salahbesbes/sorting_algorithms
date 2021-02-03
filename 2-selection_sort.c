#include "sort.h"
#include <stdlib.h>

/**
 * swap - swap 2 element in an array
 * @ar: array
 * @pos1: pos first element
 * @pos2: pos second element
 * Return: void
 */
void swap(int *ar, int pos1, int pos2)
{
	int tmp = 0;

	tmp = ar[pos2];
	ar[pos2] = ar[pos1];
	ar[pos1] = tmp;
}

/**
 * selection_sort - using selection sort
 * @array: array
 * @size: size of the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int i, j, min;

	for (i = 0; i < (int) size - 1; i++)
	{
		min = i;
		/* search for the min */
		for (j = i + 1; j < (int) size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		/* if we found min we swap */
		if (min != i)
		{
			swap(array, i, min);
			print_array(array, size);
		}
	}
}
