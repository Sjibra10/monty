#include "monty.h"
/**
 * f_pall - prints the stack
 * @head: stack head
 * @counter: no used
 * Return: no return
*/
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *stack_head;
	(void)counter;

	stack_head = *head;
	if (stack_head == NULL)
		return;
	while (stack_head)
	{
		printf("%d\n", stack_head->n);
		stack_head = stack_head->next;
	}
}
