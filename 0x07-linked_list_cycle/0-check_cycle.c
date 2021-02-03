#include "lists.h"

/**
 * check_cycle - check if linked list has a cycle.
 * @list: head of list
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle.
 */
int check_cycle(listint_t *list)
{
    listint_t *tortoise, *hare;
    
    if (list == NULL)
        return (0);

    tortoise = list;
    hare = list;

    while (tortoise->next != NULL && hare->next->next != NULL)
    {
        tortoise = tortoise->next;
        hare= hare->next->next;

        if (tortoise == hare)
            return (1);
    }
    return (0);
}
