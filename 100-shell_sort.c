#include "sort.h"
#include <stdio.h>

/**
* shell_sort - Sorts an array of integers in ascending order using
*              the Shell sort algorithm with Knuth sequence
* @array: Array to be sorted
* @size: Size of the array
*/
void shell_sort(int *array, size_t size)
{

	int interval = 1;

	if (array == NULL || size < 2)
		return;

	while (interval <= (int)(size / 3))
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		int i, j, temp;

		for (i = interval; i < (int)size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= interval && array[j - interval] > temp)
			{
				array[j] = array[j - interval];
				j -= interval;
			}
			array[j] = temp;
		}
		print_array(array, size);
		interval = (interval - 1) / 3;
	}
}
