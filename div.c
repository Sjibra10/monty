#include "monty.h"
/**
 * f_div - divides the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_div(stack_t **head, unsigned int counter)
{
	stack_t *currentNode;
	int stackLength = 0, result;

	currentNode = *head;
	while (currentNode)
	{
		currentNode = currentNode->next;
		stackLength++;
	}
	if (stackLength < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	currentNode = *head;
	if (currentNode->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	result = currentNode->next->n / currentNode->n;
	currentNode->next->n = result;
	*head = currentNode->next;
	free(currentNode);
}
