#include "monty.h"
/**
* f_pchar - prints the char at the top of the stack,
* followed by a new line
* @head: stack head
* @counter: line_number
* Return: no return
*/
void f_pchar(stack_t **head, unsigned int counter)
{
	stack_t *h;

	(void) counter;
	h = *head;
	if (!h)
	{
		bus.err_code = MNT_ERR_STK_E_PCHAR;
		return;
	}
	if (h->n > 127 || h->n < 0)
	{
		bus.err_code = MNT_ERR_PCHAR_OOR;
		return;
	}
	printf("%c\n", h->n);
	bus.err_code = MNT_OK;
}

/**
* f_pstr - prints the string at the top of the stack,
* followed by a new
* @head: stack head
* @counter: line_number
* Return: no return
*/
void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
	bus.err_code = MNT_OK;
}

