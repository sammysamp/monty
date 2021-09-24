#ifndef MONTY
#define MONTY

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

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char **arguments;
int statusfunc;
int montyflag;

char *extension(char *file);
void read_file(char *file, stack_t **stack);
void free_stack(stack_t *stack);
char *cure_buffer(char *buffer);
char **_strtok_all(char *buffer, char *delimiter);
void free_args(char **args);
size_t dlistint_len(stack_t *h);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
void swap_stack(stack_t **head);
stack_t *add_dnodeint(stack_t **head, int n);
stack_t *add_dnodeint_end(stack_t **head, int n);
void free_args(char **args);
int isnumber(char *s);
void _pall(stack_t **stack, unsigned int line);
void _swap(stack_t **stack, unsigned int line);
void _nop(stack_t **stack, unsigned int line);
void _pchar(stack_t **stack, unsigned int line);
void _pint(stack_t **stack, unsigned int line);
void _push(stack_t **stack, unsigned int line);
void _pop(stack_t **stack, unsigned int line);
void _add(stack_t **stack, unsigned int line);
void _sub(stack_t **stack, unsigned int line);
void _mul(stack_t **stack, unsigned int line);
void _div(stack_t **stack, unsigned int line);
void _pstr(stack_t **stack, unsigned int line);
void _mod(stack_t **stack, unsigned int line);
void _rotl(stack_t **stack, unsigned int line);
void _rotr(stack_t **stack, unsigned int line);
void _queue(stack_t **stack, unsigned int line);
void _stack(stack_t **stack, unsigned int line);

#endif
