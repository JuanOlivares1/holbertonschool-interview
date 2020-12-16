#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node
 * @head: pointer to lists' head
 * @number: number to inster into list
 *
 * Return: pointer to new node
 */
listint_t *insert_node(listint_t **head, int number){
	listint_t *current = *head;
	listint_t *temp, *new;

	if (number <= head[0]->n){
		new = malloc(sizeof(listint_t));
		new->n = number;
		new->next = *head;
		*head = new;
		return new;
	}

	while (number > current->n && current->next != NULL){
		temp = current;
		current = current->next;
	}

	new = malloc(sizeof(listint_t));
	new->n = number;

	if (current->next == NULL && number > current->n){
		new->next = NULL;
		current->next = new;
		return new;
        }

	new->next = current;
	temp->next = new;
	return new;
}
