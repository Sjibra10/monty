#include "monty.h"
/**
 * f_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_mod(stack_t **head, unsigned int counter)
{
	stack_t *stack_head;
	int stack_length = 0, temp;

	stack_head = *head;
	while (stack_head)
	{
		stack_head = stack_head->next;
		stack_length++;
	}
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	stack_head = *head;
	if (stack_head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = stack_head->next->n % stack_head->n;
	stack_head->next->n = temp;
	*head = stack_head->next;
	free(stack_head);
}
