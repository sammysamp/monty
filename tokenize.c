#include "monty.h"

void only_one_space(char *dest, char *src)
{
	size_t i, size = strlen(src);
	int switcher = 0;
	char *aux = src;

	while (*aux != ' ' && *aux != '\n')
	{
		if (*aux == '\0')
		{
			strcpy(dest, src);
			strcat(dest, "\n");
			return;
		}
		aux++;
	}
	for (i = 0; i <= size; i++)
	{

		while (switcher == 0)
		{
			if (*src != ' ')
			{
				dest[i] = *src;
				if (*src == '\n')
					i++;
				src++;
				break;
			}
			if ((*src == ' ')
					&& (*(src + 1) != ' ' && *(src + 1) != '\n'))
			{
				dest[i] = ' ';
				dest[i + 1] = *(src + 1);
				i++;
				src += 2;
				break;
			}
			src++;
		}
		if (*src == '\0')
			switcher = 1;
		if (switcher == 1)
			dest[i] = '\0';
	}
}

char *rm_first_space(char *buffer)
{
	size_t i;
	char *nofs;

	nofs = malloc(strlen(buffer) * sizeof(char));
	if (nofs == NULL)
	{
		free(nofs);
		return (NULL);
	}
	for (i = 1; i <= strlen(buffer); i++)
	{
		nofs[i - 1] = buffer[i];
	}
	free(buffer);
	return (nofs);
}

char *cure_buffer(char *buffer)
{
	size_t i, size = strlen(buffer);
	char *j = buffer;
	char *cure = NULL, *aux = NULL;
	char *new = malloc((size + 1) * sizeof(char));

	if (new == NULL)
	{
		free(new);
		return (NULL);
	}
	only_one_space(new, j);
	j = NULL;
	if (new[0] == ' ' || new[0] == '\n')
		aux = rm_first_space(new);
	else
		aux = new;
	if (strlen(aux) == 0)
	{
		free(aux);
		aux = NULL;
		return (NULL);
	}
	cure = malloc((1 + strlen(aux)) * sizeof(char));
	if (cure == NULL)
	{
		free(aux);
		free(cure);
		return (NULL);
	}
	for (i = 0; i < strlen(aux); i++)
		cure[i] = aux[i];
	cure[i] = '\0';
	free(aux);
	new = NULL;
	aux = NULL;
	return (cure);
}

char **tokalloc(char *buffer, char *delim, int ctok)
{
	int i, k = 0;
	char **tokens;

	tokens = malloc((ctok + 1) * sizeof(char *));
	if (tokens == NULL)
	{
		free(tokens);
		return (NULL);
	}
	for (i = 0; i <= ctok; i++)
	{
		if (*buffer == '\0')
		{
			tokens[i] = NULL;
			break;
		}
		while (*buffer != delim[0] && *buffer != delim[1])
		{
			if (*buffer == '\0')
				break;
			k++;
			buffer++;
		}
		tokens[i] = malloc((k + 1) * sizeof(char));
		if (tokens[i] == NULL)
		{
			for (; i >= 0; i--)
				free(tokens[i]);
			free(tokens);
			return (NULL);
		}
		buffer++;
		k = 0;
	}
	return (tokens);
}

char **_strtok_all(char *buffer, char *delimiter)
{
	size_t i, j, ctok = 0, k = 0;
	char *ptr = buffer, *ptr2 = buffer;
	size_t size = strlen(buffer);
	char **tokens = NULL;

	if (buffer == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < 2; j++)
		{
			if (buffer[i] == delimiter[j])
				ctok++;
		}
	}
	tokens = tokalloc(ptr, delimiter, ctok);
	if (tokens == NULL)
		return (NULL);
	ptr = NULL;
	for (i = 0; i <= ctok; i++)
	{
		if (*ptr2 == '\0')
			break;
		while (*ptr2 != delimiter[0] && *ptr2 != delimiter[1] && *ptr2 != '\0')
		{
			tokens[i][k] = *ptr2;
			ptr2++;
			k++;
		}
		tokens[i][k] = '\0';
		ptr2++;
		k = 0;
	}
	ptr2 = NULL;
	return (tokens);
}
