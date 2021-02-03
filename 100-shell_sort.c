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
 * shell_sort - shell sort algorithm
 * @array: array
 * @size: array size
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	int gap, i, j;

	gap = 1;
	while (gap < (int) size / 3)
	{
		gap = 3 * gap + 1;
	}
	while (gap > 0)
	{

		for (i = gap; i < (int) size; i += 1)
		{
			int temp = array[i];

			for (j = i; j - gap >= 0; j -= gap)
			{
				if (array[j - gap] > temp)
					array[j] = array[j - gap];
				else
					break;

			}
			array[j] = temp;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
