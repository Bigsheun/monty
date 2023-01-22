#include "monty.h"
/**
* f_push - add node to the stack
* @head: stack head
* @counter: line_number
* Return: no return
*/
void f_push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	(void) counter;
	bus.err_code = MNT_OK;
	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1;
		if (flag == 1)
		{
			bus.err_code = MNT_ERR_SYNTX_PUSH;
			return;
		}
	}
	else
	{
		bus.err_code = MNT_ERR_SYNTX_PUSH;
		return;
	}

	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}

/**
* f_pop - prints the top
* @head: stack head
* @counter: line_number
* Return: no return
*/
void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *h;

	(void) counter;
	bus.err_code = MNT_OK;
	if (*head == NULL)
	{
		bus.err_code = MNT_ERR_STK_E_POP;
		return;
	}
	h = *head;
	*head = h->next;
	free(h);
}

/**
* f_swap - adds the top two elements of the stack.
* @head: stack head
* @counter: line_number
* Return: no return
*/
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	(void) counter;
	bus.err_code = MNT_OK;
	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		bus.err_code = MNT_ERR_STK_E_SWP;
		return;
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
