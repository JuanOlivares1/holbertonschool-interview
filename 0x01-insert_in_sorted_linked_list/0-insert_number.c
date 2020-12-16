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

	// if list is empty add new node
	if (*head == NULL){
		new = malloc(sizeof(listint_t));
		new->n = number;
		new->next = NULL;
		*head = new;
		return new;
	}

	// if n is less than new, add new node at head
	if (number <= (*head)->n){
		new = malloc(sizeof(listint_t));
		new->n = number;
		new->next = *head;
		*head = new;
		return new;
	}

	// trverse the list until find a node grater than new node or tail
	while (number > current->n && current->next != NULL){
		temp = current;
		current = current->next;
	}

	new = malloc(sizeof(listint_t));
	new->n = number;

	// if new node is grater than hole list, add new node at tail
	if (current->next == NULL && number > current->n){
		new->next = NULL;
		current->next = new;
		return new;
        }

	// add node in between the list
	new->next = current;
	temp->next = new;
	return new;
}
