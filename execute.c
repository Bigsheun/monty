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
	unsigned int i;
	char *op;
	instruction_t opst[] = {
		{"pall", f_pall}, {"pint", f_pint}, {"nop", f_nop},
		{"push", f_push}, {"pop", f_pop}, {"swap", f_swap},

		{"add", f_add}, {"sub", f_sub},
		{"mul", f_mul}, {"div", f_div}, {"mod", f_mod},

		{"pchar", f_pchar}, {"pstr", f_pstr},
		{"rotl", f_rotl}, {"rotr", f_rotr},

		{"queue", f_queue}, {"stack", f_stack},
		{NULL, NULL}
	};

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");

	for (i =  0; opst[i].opcode && op; i++)
	{
		if (strcmp(opst[i].opcode, op) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
