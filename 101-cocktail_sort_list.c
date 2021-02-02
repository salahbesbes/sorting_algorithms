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

	if (firstNode == NULL || secondNode == NULL)
		return;
	listint_t *firstNodeNext = firstNode->next;
	listint_t *firstNodePrev = firstNode->prev;
	listint_t *secondNodeNext = secondNode->next;
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
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *current = NULL;
	listint_t *start = NULL;
	listint_t *end = NULL;

	start = *list;
	while (swapped)
	{
		/* we suppose the list is swapped */
		swapped = 0;
		current = start;
		while (current)
		{
			if (current->next)
				/* if we swap we do some updates */
				if (current->n > current->next->n)
				{
					swap(current, current->next, list);
					/* move back the current pointer */
					current = current->prev;
					/* update swapped flag */
					swapped = 1;
					print_list(*list);
				}
			/* we save the adjacent position of the greatest item*/
			if (current->next == NULL)
				end = current->prev;
			current = current->next;
		}
		/* break if there is no swap swapped will be 0 (sorted list) */
		if (swapped == 0)
			break;
		else /* we suppose there is no more swapping */
			swapped = 0;
		/* starting point is the adjacent pos of the greatest item */
		current = end;
		while (current)
		{
			if (current->next)
				/* if we swap we do some updates */
				if (current->n > current->next->n)
				{
					/* move back the current pointer by 1 */
					swap(current, current->next, list);
					current = current->next;
					/* update swapped flag */
					swapped = 1;
					print_list(*list);
				}
			/* we save the node adjacent to the greatest node */
			/* greatest node is always the one to the right */
			if (current->prev == NULL)
				start = current;
			current = current->prev;
		}
		/* swapped == 0 we won't loop again*/
	}
}