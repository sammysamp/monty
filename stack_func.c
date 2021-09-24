#include "monty.h"

void _push(stack_t **stack, unsigned int line)
{
	int data;

	if (arguments[1] == NULL || isnumber(arguments[1]) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		statusfunc = 0;
		return;
	}
	data = atoi(arguments[1]);
	if (montyflag == 0)
		add_dnodeint(stack, data);
	if (montyflag == 1)
		add_dnodeint_end(stack, data);
	statusfunc = 1;
}

void _pall(stack_t **stack, unsigned int line)
{
	stack_t *ptr;
	(void)line;

	for (ptr = *stack; ptr != NULL; ptr = ptr->next)
		printf("%d\n", ptr->n);
	statusfunc = 1;
}

void _swap(stack_t **stack, unsigned int line)
{
	if (dlistint_len((*stack)) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short", line);
		statusfunc = 0;
		return;
	}
	swap_stack(stack);
	statusfunc = 1;
}

void _nop(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;
	statusfunc = 1;
}

void _pchar(stack_t **stack, unsigned int line)
{
	int top;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		statusfunc = 0;
		return;
	}
	top = (*stack)->n;
	if (top < 32 || top > 126)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n",
				line);
		statusfunc = 0;
		return;
	}
	printf("%c\n", top);
	statusfunc = 1;
}

void _pint(stack_t **stack, unsigned int line)
{
	int top;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		statusfunc = 0;
		return;
	}
	top = (*stack)->n;
	printf("%d\n", top);
	statusfunc = 1;
}

void _pop(stack_t **stack, unsigned int line)
{
	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		statusfunc = 0;
		return;
	}
	delete_dnodeint_at_index(stack, 0);
	statusfunc = 1;
}

void _add(stack_t **stack, unsigned int line)
{
	if (dlistint_len((*stack)) < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		statusfunc = 0;
		return;
	}
	(*stack)->next->n += (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
	statusfunc = 1;
}

void _sub(stack_t **stack, unsigned int line)
{
	if (dlistint_len((*stack)) < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		statusfunc = 0;
		return;
	}
	(*stack)->next->n -= (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
	statusfunc = 1;
}

void _mul(stack_t **stack, unsigned int line)
{
	if (dlistint_len((*stack)) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		statusfunc = 0;
		return;
	}
	(*stack)->next->n *= (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
	statusfunc = 1;
}

void _div(stack_t **stack, unsigned int line)
{
	if (dlistint_len((*stack)) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		statusfunc = 0;
		return;
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		statusfunc = 0;
		return;
	}
	(*stack)->next->n /= (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
	statusfunc = 1;
}

void _pstr(stack_t **stack, unsigned int line)
{
	int c;
	stack_t *ptr = *stack;

	(void)line;
	while(ptr != NULL)
	{
		c = ptr->n;
		if (c < 32 || c > 126)
			break;
		putchar(c);
		ptr = ptr->next;
	}
	putchar('\n');
	statusfunc = 1;
}

void _mod(stack_t **stack, unsigned int line)
{
	if (dlistint_len((*stack)) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		statusfunc = 0;
		return;
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		statusfunc = 0;
		return;
	}
	(*stack)->next->n %= (*stack)->n;
	delete_dnodeint_at_index(stack, 0);
	statusfunc = 1;
}
/**
 * _rotr - rotates the stack to the bottom
 * The last element of the stack becomes the top element of the stack
 * @stack:
 * @line:
 *
 * Return:
 */
void _rotr(stack_t **stack, unsigned int line)
{
	stack_t *head, *last;

	(void)line;
	if (dlistint_len((*stack)) < 2)
	{
		statusfunc = 1;
		return;
	}
	head = *stack;
	last = head;
	while (last->next != NULL)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = head;
	head->prev = last;
	*stack = last;
	statusfunc = 1;
}

/**
 * _rotl - rotates the stack to the top
 * The top element of the stack becomes the last one, and the second top
 * element of the stack becomes the first one
 * @stack:
 * line:
 *
 * Return:
 */
void _rotl(stack_t **stack, unsigned int line)
{
	stack_t *head, *last;

	(void)line;
	if (dlistint_len((*stack)) < 2)
	{
		statusfunc = 1;
		return;
	}
	head = *stack;
	last = head;
	while (last->next != NULL)
		last = last->next;
	*stack = head->next;
	head->next->prev = NULL;
	head->next = NULL;
	head->prev = last;
	last->next = head;
	statusfunc = 1;
}

void _queue(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;

	montyflag = 1;
	statusfunc = 1;
}

void _stack(stack_t **stack, unsigned int line)
{
	(void)stack;
	(void)line;

	montyflag = 0;
	statusfunc = 1;
}
