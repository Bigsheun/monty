#include "monty.h"
/**
* f_add - adds the top two elements of the stack.
* @head: stack head
* @counter: line_number
* Return: no return
*/
void f_add(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	(void) counter;
	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		bus.err_code = MNT_ERR_STK_E_ADD;
		return;
	}
	h = *head;
	aux = h->n + h->next->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
	bus.err_code = MNT_OK;
}

/**
*f_sub- sustration
*@head: stack head
*@counter: line_number
*Return: no return
*/
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *aux;
	int sus, nodes;

	(void) counter;
	aux = *head;
	for (nodes = 0; aux != NULL; nodes++)
		aux = aux->next;
	if (nodes < 2)
	{
		bus.err_code = MNT_ERR_STK_E_SUB;
		return;
	}
	aux = *head;
	sus = aux->next->n - aux->n;
	aux->next->n = sus;
	*head = aux->next;
	free(aux);
}

/**
* f_mul - multiplies the top two elements of the stack.
* @head: stack head
* @counter: line_number
* Return: no return
*/
void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	(void) counter;
	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		bus.err_code = MNT_ERR_STK_E_MUL;
		return;
	}
	h = *head;
	aux = h->next->n * h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
	bus.err_code = MNT_OK;
}

/**
* f_div - divides the top two elements of the stack.
* @head: stack head
* @counter: line_number
* Return: no return
*/
void f_div(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	(void) counter;
	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		bus.err_code = MNT_ERR_STK_E_DIV;
		return;
	}

	h = *head;
	if (h->n == 0)
	{
		bus.err_code = MNT_ERR_DIV_ZERO;
		return;
	}
	aux = h->next->n / h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
	bus.err_code = MNT_OK;
}

/**
* f_mod - computes the rest of the division of the second
* top element of the stack by the top element of the stack
* @head: stack head
* @counter: line_number
* Return: no return
*/
void f_mod(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	(void) counter;
	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		bus.err_code = MNT_ERR_STK_E_MOD;
		return;
	}
	h = *head;
	if (h->n == 0)
	{
		bus.err_code = MNT_ERR_DIV_ZERO;
		return;
	}
	aux = h->next->n % h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
	bus.err_code = MNT_OK;
}
