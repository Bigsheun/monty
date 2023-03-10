#include "monty.h"

/**
* f_stack - Select stack
* @head: stack head
* @counter: line_number
* Return: no return
*/
void f_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}
/**
* f_queue - select queue
* @head: stack head
* @counter: line_number
* Return: no return
*/
void f_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;

	bus.lifi = 1;
}

/**
* addnode - add node to the head stack
* @head: head of the stack
* @n: new_value
* Return: no return
*/
void addnode(stack_t **head, int n)
{

	stack_t *new_node, *aux;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		bus.err_code = MNT_ERR_MALLOC;
		return;
	}
	new_node->n = n;

	new_node->prev = NULL;

	aux = *head;
	if (aux != NULL)
	{
		aux->prev = new_node;
		new_node->next = aux;
		*head = new_node;
	}
	else
	{
		*head = new_node;
		new_node->next = NULL;
	}
}

/**
* addqueue - add node to the tail stack
* @n: new_value
* @head: head of the stack
* Return: no return
*/
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		bus.err_code = MNT_ERR_MALLOC;
		return;
	}
	new_node->n = n;
	new_node->next = NULL;

	aux = *head;
	if (aux == NULL)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		while (aux->next)
			aux = aux->next;
		aux->next = new_node;
		new_node->prev = aux;
	}
}

/**
* free_stack - frees a doubly linked list
* @head: head of the stack
*/
void free_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
