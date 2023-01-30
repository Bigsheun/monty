#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

#define Instruction_Function (*f)(stack_t **stack, unsigned int line_number)
/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @Instruction_Function: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void Instruction_Function;
} instruction_t;

#define INSTRUCTIONSET {\
	{"pall", f_pall}, {"pint", f_pint}, {"nop", f_nop},\
	{"push", f_push}, {"pop", f_pop}, {"swap", f_swap},\
	{"add", f_add}, {"sub", f_sub},\
	{"mul", f_mul}, {"div", f_div}, {"mod", f_mod},\
	{"pchar", f_pchar}, {"pstr", f_pstr},\
	{"rotl", f_rotl}, {"rotr", f_rotr},\
	{"queue", f_queue}, {"stack", f_stack}, {NULL, NULL}	}
/**
* struct bus_s - variables -args, file, line content
* @arg: value
* @opcode: String (opcode)
* @content: line content
* @lifi: flag change stack <-> queue
* @err_code: helps to record error code (later used for error print)
* Description: carries values through the program
*/
typedef struct bus_s
{
	char *arg;
	char *opcode;
	char *content;
	int lifi;
	int err_code;
}  bus_t;

#define EMPTY_BUS {NULL, NULL, NULL, 0, 0}

#define MNT_OK 0
#define MNT_ERR_STK_E_PINT 1
#define MNT_ERR_UNKNOWN 2
#define MNT_ERR_STK_E_PCHAR 3
#define MNT_ERR_PCHAR_OOR 4
#define MNT_ERR_STK_E_ADD 5
#define MNT_ERR_STK_E_SUB 6
#define MNT_ERR_STK_E_MUL 7
#define MNT_ERR_STK_E_DIV 8
#define MNT_ERR_DIV_ZERO  9
#define MNT_ERR_STK_E_MOD 10
#define MNT_ERR_SYNTX_PUSH 11
#define MNT_ERR_STK_E_POP 12
#define MNT_ERR_STK_E_SWP 13
#define MNT_ERR_MALLOC 14

extern bus_t bus;

/**
* struct str_list - linked list to hold strings
* @str: string
* @next: points to the next element of the stack (or queue)
*
*/
typedef struct str_list
{
	char *str;
	struct str_list *next;
} list_s;


/*#include "functions-list.c"*/


/*arg-split.c*/
short found_in(char c, char *s);
int wordstart(char *str, char *delims, int index);
int delimstart(char *str, char *delims, int index);
int wordcount(char *str, char *delims);
char **split_arg(char *arg, char *delims);
/*arith.c*/
void f_add(stack_t **head, unsigned int counter);
void f_sub(stack_t **head, unsigned int counter);
void f_mul(stack_t **head, unsigned int counter);
void f_div(stack_t **head, unsigned int counter);
void f_mod(stack_t **head, unsigned int counter);
/*execute.c*/
int execute(char *content, stack_t **stack, unsigned int counter);
void print_error(int counter, char *op);
/*main.c*/
int main(int argc, char *argv[]);
long int file_Size(char *file_name);
char *file_load_all(char *Filename);
void free_all(stack_t *stack, char *content);
char *s_getline(char *pLine);
/*pall.c*/
void f_pall(stack_t **head, unsigned int counter);
void f_pint(stack_t **head, unsigned int counter);
void f_nop(stack_t **head, unsigned int counter);
/*pchar.c*/
void f_pchar(stack_t **head, unsigned int counter);
void f_pstr(stack_t **head, unsigned int counter);
/*push.c*/
void f_push(stack_t **head, unsigned int counter);
void f_pop(stack_t **head, unsigned int counter);
void f_swap(stack_t **head, unsigned int counter);
/*rotl.c*/
void f_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter);
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
/*stack_queue.c*/
void f_stack(stack_t **head, unsigned int counter);
void f_queue(stack_t **head, unsigned int counter);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void free_stack(stack_t *head);

#endif
