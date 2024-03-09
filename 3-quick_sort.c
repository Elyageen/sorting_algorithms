#include <stdio.h>
#include "sort.h"

/**
* quick_sort - Sorts an array of integers in ascending order using the
*              Quick sort algorithm
* @array: Array to be sorted
* @size: Size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1);
}

/**
* quicksort - Implements the Quick sort algorithm recursively
* @array: Array to be sorted
* @low: Starting index of the partition to be sorted
* @high: Ending index of the partition to be sorted
*/
void quicksort(int *array, int low, int high)
{
	if (low < high)
	{
		int pivot_index = partition(array, low, high);

		quicksort(array, low, pivot_index - 1);
		quicksort(array, pivot_index + 1, high);
	}
}

/**
* partition - Partitions the array based on a pivot element
* @array: Array to be partitioned
* @low: Starting index of the partition
* @high: Ending index of the partition
*
* Return: Index of the pivot element after partitioning
*/
int partition(int *array, int low, int high)
{
	int pivot = array[high];

	int i = low - 1;

	int j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, high - low + 1);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, high - low + 1);
	}

	return (i + 1);
}
