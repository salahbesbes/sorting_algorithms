#include "sort.h"


/**
 * swap - swap 2 element in an array
 * @ar: array
 * @pos1: pos first element
 * @pos2: pos second element
 * Return: void
 */
void swap(int *ar, int pos1, int pos2)
{
	int tmp;

	tmp = ar[pos2];
	ar[pos2] = ar[pos1];
	ar[pos1] = tmp;
}

/**
 * bubble_sort - sort array using bubble sort method
 * @array: array
 * @size: size fo array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	int i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array, j, j + 1);
				print_array(array, size);
			}
		}
	}
}
