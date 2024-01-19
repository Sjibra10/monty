#include "monty.h"

/**
 * f_add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_add(stack_t **head, unsigned int counter)
{
	stack_t *currentNode;
	int stackLength = 0, sum;

	currentNode = *head;
	while (currentNode)
	{
		currentNode = currentNode->next;
		stackLength++;
	}
	if (stackLength < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	currentNode = *head;
	sum = currentNode->n + currentNode->next->n;
	currentNode->next->n = sum;
	*head = currentNode->next;
	free(currentNode);
}

