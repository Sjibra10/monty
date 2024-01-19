#include "monty.h"
/**
 * addnode - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
*/
void addnode(stack_t **head, int n)
{

	stack_t *newElement, *temp;

	temp = *head;
	newElement = malloc(sizeof(stack_t));
	if (newElement == NULL)
	{ printf("Error\n");
		exit(0); }
	if (temp)
		temp->prev = newElement;
	newElement->n = n;
	newElement->next = *head;
	newElement->prev = NULL;
	*head = newElement;
}

