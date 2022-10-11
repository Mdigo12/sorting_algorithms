#include "sort.h"

/**
 * swap - swap two elements.
 * @a: integer
 * @b: integer
 **/
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;

}

/**
 * partition - Split the array and takes the last element as pivot
 * @arr: Array
 * @low: first element
 * @high: The last element
 * @size: size of array
 * Return: pivot integer
 **/
int partition(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
			if (i != j)
				print_array(arr, size);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	if (i != j)
		print_array(arr, size);
	return (i + 1);
}

/**
 * quick_sort_array - quick_sort_array
 * @arr: arr
 * @low: first element
 * @high: last element
 * @size: size of array
 * Return: Nothing
 */
void quick_sort_array(int *arr, int low, int high, size_t size)
{

	int pivot;

	if (low < high)
	{
		pivot = partition(arr, low, high, size);
		quick_sort_array(arr, low, pivot - 1, size);
		quick_sort_array(arr, pivot + 1, high, size);
	}
}

/**
 * quick_sort -Sort an array using quick_sort algorithm
 * @array: array
 * @size: size
 **/
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quick_sort_array(array, 0, size - 1, size);
}
