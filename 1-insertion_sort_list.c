#include "sort.h"
/**
 * swap - Swaps by finding the smallest element
 *
 * @swap: Doubly linked list
 *
 * @list: Head of doublylinked list
 *
 * Return: void
 */
void swap(listint_t *swap, listint_t **list)
{
	listint_t *previous, *nxt, *printlist, *copy;

	previous = swap->prev;
	nxt = swap->next;

	while ((previous->prev != NULL) && (previous->prev->n > swap->n))
		previous = previous->prev;
	swap->prev->next = nxt;
	if (nxt != NULL)
		nxt->prev = swap->prev;
	if (previous->prev == NULL)
	{
		copy = *list;
		swap->prev = NULL;
		swap->next = copy;
		copy->prev = swap;
		*list = swap;
		return;
	}
	else
	{
		swap->prev = previous->prev;
		swap->prev->next = swap;
	}
	swap->next = previous;
	previous->prev = swap;
	printlist = *list;
	print_list(printlist);
}

/**
 * insertion_sort_list - C implementation of the insertion
 * sort algoritm
 *
 * @list: Doubly linked list to be sorted
 *
 * Return: void
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list, *nxt, *previous, *count = *list;
	int counter = 0;

	while (count != NULL)
	{
		counter++;
		count = count->next;
	}
	if (counter <= 2)
		return;
	while (current != NULL)
	{
		previous = current->prev;
		nxt = current->next;
		if (previous == NULL)
		{
			current = nxt;
			continue;
		}

		if (previous->n > current->n)
			swap(current, list);
		current = nxt;
		continue;
	}
}
