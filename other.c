#include "monty.h"

char *extension(char *file)
{
	char *ext;
	int i = 0;

	if (file == NULL)
		return (NULL);
	while (file[i] != '\0')
		i++;
	i--;
	ext = file + i;
	while (*ext != '.' && i >= 0)
	{
		ext--;
		i--;
	}
	return (ext);
}

void free_args(char **args)
{
	int i = 0;

	while (args[i] != NULL)
		i++;
	i--;
	for (; i >= 0; i--)
		free(args[i]);
	free(args);
	args = NULL;
}

void free_stack(stack_t *stack)
{
	if (stack == NULL)
		return;
	if (stack->next != NULL)
		free_stack(stack->next);
	free(stack);
}

int isnumber(char *s)
{
	char *n = s;

	if (n == NULL)
		return (0);
	while (*n != '\0')
	{
		if (*n < 48 || *n > 57)
			return (0);
		n++;
	}
	return (1);
}
