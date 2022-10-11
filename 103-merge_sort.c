#include "sort.h"

/**
 * merge - initiate merge sort
 * @array: array to be sorted
 * @result: temporary array for holding sorted elements
 * @size: size of the array
 */
void merge(int *array, int *result, size_t size)
{
	size_t half = size / 2, i = 0, j = 0, k;

	if (size < 2)
		return;

	merge(array, result, half);
	merge(array + half, result + half, size - half);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, half);
	printf("[right]: ");
	print_array(array + half, size - half);
	for (k = 0; k < size; k++)
		if (j >= size - half || (i < half && array[i] < (array + half)[j]))
			result[k] = array[i++];
		else
			result[k] = (array + half)[j++];
	for (k = 0; k < size; k++)
		array[k] = result[k];
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - initiate merge sort
 * @array: array to be sorted
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *result;

	if (!array || size < 2)
		return;
	result = malloc(sizeof(*result) * size);
	merge(array, result, size);
	free(result);
}
