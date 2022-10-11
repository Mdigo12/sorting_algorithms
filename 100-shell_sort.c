#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending
 *	order using the Shell sort algorithm, using the Knuth sequence
 *
 * Desc: The Knuth sequence
 *	n+1 = n * 3 + 1
 *	1, 4, 13, 40, 121, ...
 *
 * @array: An array to be sorted
 * @size: No of elements in an array
 *
 * Return - Void
 */

void shell_sort(int *array, size_t size)
{
	int gap, i, j, tmp;

	gap = 1;
	for (gap = (gap * 3 + 1); gap >= 1; gap = gap / 3)
	{
		for (j = gap; j < (int)size; j++)
		{
			for (i = j - gap; i >= 0; i = i - gap)
			{
				if (array[i + gap] > array[i])
					break;
				tmp = array[i + gap];
				array[i + gap] = array[i];
				array[i] = tmp;
			}
		}
		print_array(array, size);
	}
}
