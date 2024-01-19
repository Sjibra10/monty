#include "monty.h"
/**
 * f_swap - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *temp_node;
	int stack_length = 0, temp_value;

	temp_node = *head;
	while (temp_node)
	{
		temp_node = temp_node->next;
		stack_length++;
	}
	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp_node = *head;
	temp_value = temp_node->n;
	temp_node->n = temp_node->next->n;
	temp_node->next->n = temp_value;
}
