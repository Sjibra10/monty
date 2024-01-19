#include "monty.h"
/**
 * f_pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *stack_node;
	(void)counter;

	stack_node = *head;
	while (stack_node)
	{
		if (stack_node->n > 127 || stack_node->n <= 0)
		{
			break;
		}
		printf("%c", stack_node->n);
		stack_node = stack_node->next;
	}
	printf("\n");
}
