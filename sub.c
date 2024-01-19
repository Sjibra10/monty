#include "monty.h"
/**
  *f_sub- sustration
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *temp_node;
	int subtraction_result, node_count;

	temp_node = *head;
	for (node_count = 0; temp_node != NULL; node_count++)
		temp_node = temp_node->next;
	if (node_count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp_node = *head;
	subtraction_result = temp_node->next->n - temp_node->n;
	temp_node->next->n = subtraction_result;
	*head = temp_node->next;
	free(temp_node);
}
