#include "sort.h"

/**
 * search_max - search for max in an array
 * @ar: array
 * @n: size of array
 * Return: largest nb
 */
int search_max(int *ar, size_t n)
{
	int i, largest = 0;

	for (i = 0; i < (int) n; i++)
	{
		if (ar[i] > largest)
			largest = ar[i];
	}
	return (largest);
}
/**
 * counting_sort - counting sort on positive integer
 * @array: array
 * @size: size
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int largest, idx, val;
	int *count_Ar = NULL, *new_ar = NULL;
	size_t i;

	if (size < 2)
		return;
	largest = search_max(array, size);
	count_Ar = malloc(sizeof(int) * (largest + 1));
	for (i = 0; i < (size_t) largest; i++)
		count_Ar[i] = 0;

	for (i = 0; i < size; i++)
	{
		idx = array[i];
		count_Ar[idx] = count_Ar[idx] + 1;
	}
	for (i = 1; i <= (size_t) largest; i++)
		count_Ar[i] += count_Ar[i - 1];

	new_ar = malloc(sizeof(int) * size);

	for (i = 0; i < size; i++)
	{
		val = array[i];
		idx = count_Ar[val];
		if (idx > 1)
			count_Ar[val] = count_Ar[val] - 1;
		new_ar[idx -1] = val;

	}
	for (i = 0; i < size; i++)
		array[i] = new_ar[i];
	print_array(count_Ar, largest + 1);
	free(new_ar);
	free(count_Ar);
}
