#include <stdio.h>
#include "sort.h"

/**
* swap - Swaps two integers
* @a: Pointer to the first integer
* @b: Pointer to the second integer
*/
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
* partition - Partitions the array using Lomuto scheme
* @array: The array to be sorted
* @low: Starting index of the array
* @high: Ending index of the array
* @size: Size of the array
* Return: Index of the pivot
*/
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];

	int i = low - 1;

	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

/**
* quick_sort_recursive - Recursive function to implement quick sort
* @array: The array to be sorted
* @low: Starting index of the array
* @high: Ending index of the array
* @size: Size of the array
*/
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
* quick_sort - Sorts an array of integers in ascending order using Quick sort
* @array: The array to be sorted
* @size: Size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
