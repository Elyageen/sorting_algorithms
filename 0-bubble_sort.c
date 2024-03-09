#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using
 *               the Bubble sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 *
 * Description: This function sorts an array of integers in ascending order
 *              using the Bubble sort algorithm. It iterates through the array
 *              and compares adjacent elements, swapping them if they are in
 *              the wrong order. It continues this process until the array
 *              is sorted. The `print_array` function is called after each
 *              swap to print the array's current state.
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int temp;
    int swapped;

    for (i = 0; i < size - 1; i++)
    {
        swapped = 0; /* Initialize swapped to 0 */
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                print_array(array, size); /* Print the array after each swap */
                swapped = 1; /* Set swapped to 1 to indicate a swap occurred */
            }
        }

        /* If no two elements were swapped in the inner loop, then the array is sorted */
        if (swapped == 0)
            break;
    }
}
