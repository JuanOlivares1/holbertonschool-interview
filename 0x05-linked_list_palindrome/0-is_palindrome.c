#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * palindrome_rec - finds by recursion if list is palindrome
 * @left: pointer to head move forwards
 * @right: pointer to head move backwards
 * Return: 0 if is not palindrome, 1 if it is
 */
int palindrome_rec(listint_t** left, listint_t* right)
{ 
	int rtn;

    	if (right == NULL) 
        	return 1; 
 
    	if (palindrome_rec(left, right->next) == 0) 
        	return 0;
 
    	
    	if (right->n == (*left)->n)
	    	rtn = 1;
	else
		rtn = 0;
 
    	*left = (*left)->next; 
 
    	return rtn; 
} 
 
/**
 * is_palindrome - find if a linked list is palindrome
 * @head: pointer to head of list
 * Return: 0 if is not palindrome, 1 if it is
 */
int is_palindrome(listint_t **head)
{
    return (palindrome_rec(head, *head));
}