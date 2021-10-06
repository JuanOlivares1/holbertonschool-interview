#include "lists.h"

/**
 * start_of_loop - finds the start of a loop
 * @first: pointer to node in list
 * @second: pointer to node in list
 * Return: start of loop
 */
listint_t *start_of_loop(listint_t *first, listint_t *second)
{
	while (first != second)
	{
		first = first->next;
		second = second->next;
	}
	return (first);
}


/**
 * check_cycle - check if linked list has a cycle.
 * @head: head of list
 *
 * Return: 0 if there is no cycle, node start of loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortoise = head->next;
	listint_t *hare = head->next->next;

	if (!head || !head->next)
		return (0);

	while (tortoise && hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;
		if (tortoise == hare)
			return (start_of_loop(head, hare));
	}
	return (0);
}
