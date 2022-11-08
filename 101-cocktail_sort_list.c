#include "sort.h"
/**
 * cocktail_sort_list - C implementaion of cocktail sort algorithm
 *
 * @list: Head of Doubly linked list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *prevofPrevious, *previous, *nxt, *current = *list, *copy;
	int flag = 1;

	current = current->next;
	while (flag == 1)
	{
		flag = 0;
		while (current)
		{
			previous = current->prev;
			nxt = current->next;
			if (previous->n > current->n)
			{
				flag = 1;
				if (previous->prev != NULL)
				{
					prevofPrevious = previous->prev;
					current->prev = prevofPrevious;
					prevofPrevious->next = current;
					current->next = previous;
					previous->prev = current;
				}
				else
				{
					copy = *list;
					current->prev = NULL;
					current->next = copy;
					copy->prev = current;
					*list = current;
				}
				previous->next = nxt;
				if (nxt != NULL)
					nxt->prev = previous;
				copy = *list;
				print_list(copy);
			}
			current = current->next;
		}
		current = *list;
		current = current->next;
	}
}
