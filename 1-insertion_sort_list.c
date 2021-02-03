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
	listint_t *firstNodePrev = NULL;
	listint_t *secondNodeNext = NULL;

	if (firstNode == NULL || secondNode == NULL)
		return;
	firstNodePrev = firstNode->prev;
	secondNodeNext = secondNode->next;
	/* if nodes are adjacent*/
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

/**
 * insertion_sort_list - insertion sort
 * @list: head list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *swapPointer = NULL;
	int oldval;

	if (!list || !(*list) || !((*list)->next))
		return;
	current = *list;
	/* start from the second node */
	while (current)
	{
		swapPointer = current->prev;
		oldval = current->n;

		while (swapPointer && swapPointer->n > oldval)
		{
			swap(swapPointer, current, list);
			print_list(*list);
			swapPointer = current->prev;
		}
		current = current->next;
	}
}
