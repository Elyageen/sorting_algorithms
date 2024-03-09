#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 the Counting sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
    size_t max = 0;
    size_t i;
    int *count = malloc((max + 1) * sizeof(int));
    int *temp = malloc(size * sizeof(int));

    if (array == NULL || size < 2)
        return;

    /* Find the maximum element in the array*/
    for (i = 0; i < size; i++)
    {
        if ((size_t)array[i] > max)
            max = (size_t)array[i];
    }

    /* Create a counting array of size max+1 and initialize all elements to 0*/
    if (count == NULL)
        return;

    for (i = 0; i <= max; i++)
        count[i] = 0;

    /* Count the occurrences of each element in the array*/
    for (i = 0; i < size; i++)
        count[array[i]]++;

    /* Print the counting array*/
    printf("Counting array: ");
    for (i = 0; i <= max; i++)
        printf("%d%s", count[i], i == max ? "\n" : ", ");

    /* Modify the counting array to store the cumulative frequencies*/
    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];

    /* Create a temporary array to store the sorted elements*/
    if (temp == NULL)
    {
        free(count);
        return;
    }

    /* Sort the array based on the counting array*/
    for (i = size - 1; i < size; i--)
    {
        temp[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    /* Copy the sorted elements from the temporary array to the original array*/
    for (i = 0; i < size; i++)
        array[i] = temp[i];

    /* Free the allocated memory*/
    free(temp);
    free(count);
}
