#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
				{"pop", f_pop},
				{"swap", f_swap},
				{"add", f_add},
				{"nop", f_nop},
				{"sub", f_sub},
				{"div", f_div},
				{"mul", f_mul},
				{"mod", f_mod},
				{"pchar", f_pchar},
				{"pstr", f_pstr},
				{"rotl", f_rotl},
				{"rotr", f_rotr},
				{"queue", f_queue},
				{"stack", f_stack},
				{NULL, NULL}
				};
	unsigned int index = 0;
	char *opcode;

	opcode = strtok(content, " \n\t");
	if (opcode && opcode[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[index].opcode && opcode)
	{
		if (strcmp(opcode, opst[index].opcode) == 0)
		{	opst[index].f(stack, counter);
			return (0);
		}
		index++;
	}
	if (opcode && opst[index].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
