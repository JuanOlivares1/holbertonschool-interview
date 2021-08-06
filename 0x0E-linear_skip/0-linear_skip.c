#include "search.h"

/**
 * linear_skip - linear search on skip-list
 * @list: pointer to list
 * @value: value to search for
 *
 * Return: pointer to node
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *temp;

	if (!list)
		return (NULL);

	if (list->n == value)
		return (list);

	if (!list->express)
	{
		temp = list;
		while (temp->next)
			temp = temp->next;
		printf("Value found between indexes [%li] and [%li]\n",
				list->index, temp->index);
		while (list)
		{
			printf("Value checked at index [%li] = [%d]\n", list->index, list->n);
			if (list->n == value)
				return (list);
			list = list->next;
		}
		return (NULL);
	}

	printf("Value checked at index [%li] = [%d]\n",
			list->express->index, list->express->n);
	if (list->express->n < value)
		return (linear_skip(list->express, value));
	printf("Value found between indexes [%li] and [%li]\n",
			list->index, list->express->index);
	while (list->next)
	{
		printf("Value checked at index [%li] = [%d]\n", list->index, list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}
	return (NULL);
}
