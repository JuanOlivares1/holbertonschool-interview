#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - Function that inserts a new node in a sorted singly linked list
 * @head: Pointer to list's head
 * @number: Value for new node
 *
 * Return: Pointer to new node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current = *head;
	listint_t *temp, *new;
	/* If list is empty add new node */
	if (*head == NULL)
	{
		new = malloc(sizeof(listint_t));
		new->n = number;
		new->next = NULL;
		*head = new;
		return (new);
	}
	/* If head node is less than number, add new node at head */
	if (number <= (*head)->n)
	{
		new = malloc(sizeof(listint_t));
		new->n = number;
		new->next = *head;
		*head = new;
		return (new);
	}
	/* Trverse the list until find a node grater than number or tail */
	while (number > current->n && current->next != NULL)
	{
		temp = current;
		current = current->next;
	}

	new = malloc(sizeof(listint_t));
	new->n = number;
	/* If number is grater than hole list, add new node at tail */
	if (current->next == NULL && number > current->n)
	{
		new->next = NULL;
		current->next = new;
		return (new);
	}
	new->next = current;
	temp->next = new;
	return (new);
}
