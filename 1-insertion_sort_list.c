#include "sort.h"
#include <stdlib.h>

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: double pointer to the list head to be sorte
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *head, *temp, *curr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	head = *list;
	curr = head->next;
	while (curr)
	{
		while (curr->prev && curr->n < (curr->prev)->n)
		{
			temp = curr;
			if (curr->next != NULL)
				(curr->next)->prev = curr->prev;
			(curr->prev)->next = curr->next;

			curr = curr->prev;
			temp->prev = curr->prev;
			temp->next = curr;

			if (curr->prev)
				(curr->prev)->next = temp;
			curr->prev = temp;

			if (temp->prev == NULL)
				*list = temp;
			print_list(*list);
			curr = curr->prev;
		}
		curr = curr->next;
	}
}
