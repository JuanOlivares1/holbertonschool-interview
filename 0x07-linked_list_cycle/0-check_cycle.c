#include "lists.h"

/**
 * check_cycle - check if linked list has a cycle.
 * @list: head of list
 *
 * Return: Always 0.
 */
int check_cycle(listint_t *list)
{
    listint_t *tortoise, *hare;
    
    if (list == NULL || list->next == NULL)
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
