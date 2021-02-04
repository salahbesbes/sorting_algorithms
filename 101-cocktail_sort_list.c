#include "sort.h"

/**
 * swap - swap 2 element in an array
 * @head: head of list
 * @firstNode: pos first node
 * @secondNode: pos second node
 * Return: void
 */
void swap(listint_t *firstNode, listint_t *secondNode, listint_t **head)
{

	listint_t *firstNodeNext = firstNode->next;
	listint_t *firstNodePrev = firstNode->prev;
	listint_t *secondNodeNext = secondNode->next;

	if (firstNode == NULL || secondNode == NULL)
		return;
	/* if nodes are adjacent*/
	if (firstNodeNext == secondNode)
	{
		if (firstNodePrev)
			firstNodePrev->next = secondNode;
		if (secondNodeNext)
			secondNodeNext->prev = firstNode;
		firstNode->next = secondNodeNext;
		firstNode->prev = secondNode;
		secondNode->next = firstNode;
		secondNode->prev = firstNodePrev;
		if (firstNodePrev == NULL)
			*head = secondNode;
	}
}
/**
 * cocktail_sort_list - cocktail sort
 * @list: linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current, *start, *end = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;
	swapped = 1, start = NULL, end = NULL;
	while (swapped)
	{
		swapped = 0, current = *list;
		while (current)
		{
			if (current->next)
				if (current->n > current->next->n)
				{
					swap(current, current->next, list);
					current = current->prev;
					swapped++;
					print_list(*list);
				}
			if (current->next == NULL)
				end = current->prev;
			current = current->next;

		}
		if (swapped == 0)
			break;
		swapped = 0, current = end;
		while (current)
		{
			if (current->prev)
				if (current->prev->n > current->n)
				{
					swap(current->prev, current, list);
					current = current->next;
					swapped++;
					print_list(*list);
				}
			current = current->prev;
		}
	}
}
