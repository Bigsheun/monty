#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int counter)
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
		return (MNT_OK);

	bus.arg = strtok(NULL, " \n\t");
	for (i =  0; opst[i].opcode && op; i++)
	{
		if (strcmp(opst[i].opcode, op) == 0)
		{
			opst[i].f(stack, counter);
			return (bus.err_code);
		}
	}

	if (op && opst[i].opcode == NULL)
	{

		bus.err_code = MNT_ERR_UNKNOWN;
		return (MNT_ERR_UNKNOWN);
	}
	return (1);
}

/**
* print_error - prints the designated error message
* error code is found in bus.err_code (global variable)
* counter: line number actually
* op: opcode
*/
void print_error(int counter, char *op)
{
	if (bus.err_code ==  MNT_ERR_STK_E_PINT)
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
	else if (bus.err_code ==  MNT_ERR_UNKNOWN)
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
	else if (bus.err_code ==  MNT_ERR_STK_E_PCHAR)
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
	else if (bus.err_code ==  MNT_ERR_PCHAR_OOR)
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
	else if (bus.err_code == MNT_ERR_STK_E_ADD)
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
	else if (bus.err_code == MNT_ERR_STK_E_SUB)
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
	else if (bus.err_code == MNT_ERR_STK_E_MUL)
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
	else if (bus.err_code == MNT_ERR_STK_E_DIV)
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
	else if (bus.err_code == MNT_ERR_DIV_ZERO)
		fprintf(stderr, "L%d: division by zero\n", counter);
	else if (bus.err_code == MNT_ERR_STK_E_MOD)
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
	else if (bus.err_code == MNT_ERR_SYNTX_PUSH)
		fprintf(stderr, "L%d: usage: push integer\n", counter);
	else if (bus.err_code == MNT_ERR_STK_E_POP)
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
	else if (bus.err_code == MNT_ERR_STK_E_SWP)
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
	/*end-if*/
}
