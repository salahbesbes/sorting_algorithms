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
	int tmp;

	if (firstNode == NULL || secondNode == NULL)
		return;
	listint_t *firstNodeNext = firstNode->next;
	listint_t *firstNodePrev = firstNode->prev;
	listint_t *secondNodeNext = secondNode->next;
	listint_t *secondNodePrev = secondNode->prev;
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
		return;
	}
	if (firstNodePrev != NULL)
		firstNodePrev->next = secondNode;
	if (firstNodeNext != NULL)
		firstNodeNext->prev = secondNode;
	if (secondNodePrev != NULL)
		secondNodePrev->next = firstNode;
	if (secondNodeNext != NULL)
		secondNodeNext->prev = firstNode;
	firstNode->next = secondNodeNext;
	firstNode->prev = secondNodePrev;
	secondNode->next = firstNodeNext;
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
	listint_t *head = NULL, *current = NULL, *swapPointer = NULL;
	int oldval;

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
