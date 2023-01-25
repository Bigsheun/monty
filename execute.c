#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int counter)
{
	unsigned int i;
	char *op, **content_array;
	instruction_t opst[] = INSTRUCTIONSET;

	content_array = split_arg(content, " \t");
	op = content_array[0];
	bus.opcode  = op;
	if ((op == NULL) || (op[0] == '#'))
	{
		free(content_array);
		return (MNT_OK);
	}

	bus.arg = content_array[1];
	for (i =  0; opst[i].opcode && op; i++)
	{
		if (strcmp(opst[i].opcode, op) == 0)
		{
			opst[i].f(stack, counter);
			free(content_array);
			return (bus.err_code);
		}
	}
	bus.err_code = MNT_ERR_UNKNOWN;
	free(content_array);
	return (MNT_ERR_UNKNOWN);
}

/**
* print_error - prints the designated error message
* error code is found in bus.err_code (global variable)
* @counter: line number actually
* @op: opcode
*/
void print_error(int counter, char *op)
{
	fflush(stdout);
	counter += 1;
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
	fflush(stderr);
}
