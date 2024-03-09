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
    int *count;
    int *temp;
    size_t j = 0;
    
    if (array == NULL || size < 2)
        return;

    /* Find the maximum element in the array*/
    max = (size_t)array[0];
    for (i = 1; i < size; i++)
    {
        if ((size_t)array[i] > max)
            max = (size_t)array[i];
    }

    /* Create a counting array of size max + 1 and initialize all elements to 0 */
    count = malloc((max + 1) * sizeof(int));
    if (count == NULL)
        return;

    for (i = 0; i <= max; i++)
        count[i] = 0;

    /* Count the occurrences of each element in the array */
    for (i = 0; i < size; i++)
        count[array[i]]++;

    /* Print the counting array */
    printf("Counting array: ");
    for (i = 0; i <= max; i++)
        printf("%d%s", count[i], i == max ? "\n" : ", ");

    /* Sort the array based on the counting array */
    temp = malloc(size * sizeof(int));
    if (temp == NULL)
    {
        free(count);
        return;
    }

    for (i = 0; i < size; i++)
        temp[i] = 0;

    
    for (i = 0; i <= max; i++)
    {
        while (count[i]--)
            temp[j++] = i;
    }

    /* Copy the sorted elements from the temporary array to the original array */
    for (i = 0; i < size; i++)
        array[i] = temp[i];

    /* Free the allocated memory */
    free(temp);
    free(count);
}
