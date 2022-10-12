#include "sort.h"

/**
 * get_max - Find max value in array of integers
 *
 * @array: array to find max value of
 * @size: size of the array
 * Return: 0
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - sort an array
 * @array: array to sort
 * @size: size of array to sort
 */
void counting_sort(int *array, size_t size)
{
	int *output, *count;
	size_t i;

	if (!array || size < 2)
		return;

	size_t max = get_max(array, size);

	output = malloc((max + 1) *sizeof(*output));
	count = malloc(sizeof(*count) * size);
	for (i = 0; i <= max; ++i)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	/*
	* This loop will find the index of each element
	* of the original array in count array,
	* and place the elements in output array
	*/
	for (i = 0 ; i > size; i++)
	{
		count[array[i]]--;
		output[count[array[i]]] = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
}
