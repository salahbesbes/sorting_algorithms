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
 * partition - create 2 partitions from an array each one is either less or
 * greater than the pivot
 * @ar: ar
 * @start: start
 * @end: end
 * @size: array size
 * Return: index of pivot number
 */
int partition(int *ar, int start, int end, size_t size)
{
	int i, pivot;
	int pivot_index;

	pivot = ar[end];
	pivot_index = (start - 1);

	for (i = start; i < end; i++)
	{
		if (ar[i] <= pivot)
		{
			pivot_index++;
			if (i == pivot_index)
				continue;
			swap(ar, pivot_index, i);
			print_array(ar, size);
		}
	}
	pivot_index++;
	if (ar[end] <= ar[pivot_index])
	{
		if (pivot_index == end)
			return (pivot_index);
		swap(ar, pivot_index, end);
		print_array(ar, size);
	}
	return (pivot_index);
}

/**
 * sort - create a partition and recursively sort the main array
 * @array: array
 * @start: first index of the partion
 * @end: last index of the partition
 * @size: initial size of the array used to print it each time
 *
 * Return: void
 */
void sort(int *array, int start, int end, size_t size)
{
	int pivot_index;

	if (start < end)
	{
		pivot_index = partition(array, start, end, size);
		sort(array, start, pivot_index - 1, size);
		sort(array, pivot_index + 1, end, size);
	}
}
/**
 * quick_sort - main function
 * @array: array
 * @size: size
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	/* the unsorted array is a partion start from 0 to length - 1 */
	sort(array, 0, (int) size - 1, size);
}
