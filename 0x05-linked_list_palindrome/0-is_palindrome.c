#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - find if a linked list is palindrome
 * @head: pointer to head of list
 * Return: 0 if is not palindrome, 1 if it is
 */
int is_palindrome(listint_t **head)
{
	int rtn = 0;
	listint_t *spointer = *head;
	listint_t *fpointer = *head;
	listint_t *prev_spointer = *head;
	listint_t *half, *mid;

	if (head != NULL && (*head)->next != NULL)
	{
		while (fpointer != NULL && fpointer->next != NULL)
		{
			fpointer = fpointer->next->next;
			prev_spointer = spointer;
            		spointer = spointer->next;
		}

		if (fpointer != NULL)
		{
			mid = spointer;
			spointer = spointer->next;
		}
		half = spointer;
		prev_spointer->next = NULL;
		reverse(&half);
		rtn = is_equal(*head, half);
		reverse(&half);

		if (mid != NULL) { 
            		prev_spointer->next = mid; 
            		mid->next = half; 
        	} else
            		prev_spointer->next = half; 
    	}
	return (rtn);
}

/**
 * is_equal - tells if two singly linked lists have the same data
 * @h1: pointer to head of list
 * @h2: pointer to head of list
 * Return: 0 if are the same, 1 if doesn't
 */
int is_equal (listint_t *head1, listint_t *head2)
{
	listint_t *h1 = head1;
	listint_t *h2 = head2;

	while (h1 && h2) { 
        	if (h1->n == h2->n) 
		{ 
         		h1 = h1->next; 
            		h2 = h2->next; 
        	} else 
		{
			return 0; 
		}
    	} 
 
    	if (h1 == NULL && h2 == NULL) 
        	return 1; 
	
	return (0);
}

/**
 * reverse - a singly linked list
 * @head: pointer to head of list
 */
void reverse (listint_t **head)
{
	listint_t *prev, *current, *next;

	prev = NULL;
	current = *head;
	while (current != NULL) 
	{ 
	        next = current->next;
        	current->next = prev;
        	prev = current;
        	current = next;
    	}
    *head = prev;
}
