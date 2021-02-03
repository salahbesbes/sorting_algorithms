#include "sort.h"

/**
 * swap - function to swap two nodes in a doubly linked list
 * @left: left node to swap
 * @right: right node to swap
 */
void swap(listint_t *left, listint_t *right)
{
	if (left->prev != NULL)
		left->prev->next = right;
	if (right->next != NULL)
		right->next->prev = left;
	left->next = right->next;
	right->prev = left->prev;
	left->prev = right;
	right->next = left;
}

/**
 * insertion_sort_list - insertion sort algorithm on a list
 * @list: list to be sorted
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

	if (!list || !(*list) || !((*list)->next))
		return;
	i = (*list)->next;
	while (i)
	{
		j = i;
		while (j->prev && (j->prev)->n > j->n)
		{
			if (i == j)
				i = j->prev;
			if (j->prev == *list)
				*list = j;
			swap(j->prev, j);
			print_list(*list);
		}
		i = i->next;
	}
}
