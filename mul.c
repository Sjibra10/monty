#include "monty.h"
/**
 * f_mul - multiplies the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_mul(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	stack_head = *head;
	temp = stack_head->next->n * stack_head->n;
	stack_head->next->n = temp;
	*head = stack_head->next;
	free(stack_head);
}
