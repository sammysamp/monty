#include "monty.h"

/**
 * add_dnodeint - adds a new node at the beginning of a list
 * @head: the head of a list
 * @n: the piece of data of the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint(stack_t **head, int n)
{
	stack_t *new = malloc(sizeof(stack_t)), *ptr = *head;

	if (new == NULL)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	if (ptr != NULL)
	{
		new->next = ptr;
		ptr->prev = new;
	}
	else
		new->next = NULL;
	*head = new;
	return (new);
}

/**
 * add_dnodeint_end - adds a new node at the end of a list
 * @head: the head of a list
 * @n: the piece of data of the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint_end(stack_t **head, int n)
{
	stack_t *new = malloc(sizeof(stack_t)), *ptr;

	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}
	ptr = *head;
	while (ptr->next != NULL)
		ptr = ptr->next;
	new->prev = ptr;
	ptr->next = new;
	return (new);
}

/**
 * dlistint_len - counts the elements of a doubly linked list
 * @h: the head of a list
 *
 * Return: the number of elements of the list
 */
size_t dlistint_len(stack_t *h)
{
	size_t i = 0;
	stack_t *p = h;

	for (; p != NULL; i++)
		p = p->next;
	return (i);
}

/**
 * delete_dnodeint_at_index - deletes the node at a given index of a
 * doubly linked list
 * @head:the head of a list
 * @index: is the index of the node that should be deleted
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *ptr = *head;
	unsigned int len = dlistint_len(ptr);

	if (index >= len)
		return (-1);
	if (len == 1)
	{
		free(*head);
		*head = NULL;
		return (1);
	}
	while (index > 0)
	{
		ptr = ptr->next;
		index--;
	}
	if (ptr->prev == NULL)
	{
		*head = ptr->next;
		if (ptr->next != NULL)
			ptr->next->prev = NULL;
	}
	else
	{
		ptr->prev->next = ptr->next;
		if (ptr->next != NULL)
			ptr->next->prev = ptr->prev;
	}
	free(ptr);
	return (1);
}

void swap_stack(stack_t **head)
{
	stack_t *s1 = *head;
	stack_t *s2 = (*head)->next;

	s1->prev = s2;
	s1->next = s2->next;
	s2->next = s1;
	s2->prev = NULL;
	*head = s2;
}
