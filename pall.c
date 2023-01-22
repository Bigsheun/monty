#include "monty.h"
/**
* f_pall - prints the stack
* @head: stack head
* @counter: no used
* Return: no return
*/
void f_pall(stack_t **head, unsigned int counter)
{
	stack_t *h;

	(void)counter;
	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	bus.err_code = MNT_OK;
}

/**
* f_pint - prints the top
* @head: stack head
* @counter: line_number
* Return: no return
*/
void f_pint(stack_t **head, unsigned int counter)
{
	(void)counter;
	if (*head == NULL)
	{
		bus.err_code = MNT_ERR_STK_E_PINT;
		return;
	}
	printf("%d\n", (*head)->n);
	bus.err_code = MNT_OK;
}

/**
* f_nop- do nothing
* @head: stack head
* @counter: line_number
* Return: no return
*/
void f_nop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
	bus.err_code = MNT_OK;
}
