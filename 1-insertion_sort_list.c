#include "sort.h"
#include <stdio.h>
/**
 * firstelementswap - Handles swap when element needs to
 * be swaped with the first element
 *
 * @current: current
 *
 * @list: head of list
 *
 * Return: 1 used as flag to return as it is the end of swapping
 */
int firstelementswap(listint_t *current, listint_t **list)
{
	listint_t *copy = *list;

	current->prev = NULL;
	current->next = copy;
	copy->prev = current;
	*list = current;
	return (1);
}
/**
 * singleswaphandler - Handles swap between previous
 * and current when previous->prev is not NULL
 *
 * @previous: previous of current
 *
 * @current: current element
 *
 * Return: void
 */
void singleswaphandler(listint_t *previous, listint_t *current)
{
	listint_t *prevofPrevious;


	prevofPrevious = previous->prev;
	current->prev = prevofPrevious;
	prevofPrevious->next = current;
	current->next = previous;
	previous->prev = current;

}
/**
 * swap - Calls singleswaphandler when
 * previous->n > current->n
 *
 * @swap: Doubly linked list
 *
 * @list: Head of doublylinked list
 *
 * Return: void
 */
void swap(listint_t *swap, listint_t **list)
{
	listint_t *previous = swap, *nxt, *current = swap, *copy;
	int flag = 1, initial_value_flag = 0;

	while (flag == 1)
	{
		flag = 0;
		while (previous)
		{
			flag = 0;
			if (current->prev != NULL)
				previous = current->prev;
			nxt = current->next;
			if (previous->n > current->n)
			{
				flag = 1;
				if (previous->prev != NULL)
					singleswaphandler(previous, current);
				else
					initial_value_flag = firstelementswap(current, list);
				previous->next = nxt;
				if (nxt != NULL)
					nxt->prev = previous;
				copy = *list;
				print_list(copy);
				if (initial_value_flag == 1)
					return;
			}
			if ((current->prev->prev != NULL) && (flag == 0))
				current = current->prev;
			else if ((current->prev->prev != NULL) && (flag == 1))
				continue;
			else
				break;
		}
	}
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
	current = current->next;
	while (current)
	{
		previous = current->prev;
		nxt = current->next;
		if (previous->n > current->n)
			swap(current, list);
		current = nxt;
	}
}
