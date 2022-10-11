#include "sort.h"

/**
 * selection_sort - sorts an array of integers
 *	in ascending order using the Selection sort algorith
 *
 * @array: Head ponter to the array to be sorted
 * @size: Number of elements in the array
 */

void selection_sort(int *array, size_t size)
{
	int i, j, min;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (min != i)
		{
			int temp = array[min];

			array[min] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
