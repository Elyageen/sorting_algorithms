#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/* Struct for doubly linked list node */
typedef struct listint_s
{
    const int n;                /* Integer stored in the node */
    struct listint_s *prev;    /* Pointer to the previous element of the list */
    struct listint_s *next;    /* Pointer to the next element of the list */
} listint_t;

/* Function prototypes */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);

#endif /* SORT_H */
