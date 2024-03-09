#include <stdio.h>
#include "sort.h"

/**
* print_list - Prints a list of integers
*
* @list: The list to be printed
*/
void print_list(const listint_t *list)
{
	const listint_t *current = list;

	while (current != NULL)
	{
		printf("%d", current->n);
		if (current->next != NULL)
			printf(", ");

		current = current->next;
	}
	printf("\n");
}
