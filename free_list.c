#include "monty.h"

void free_list(stack_t *stack)
{
	stack_t *temp = stack;
	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

/**
 */
void free_to_index(char **arr, int i)
{
	while (i)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
}

/**
 */
void free_all(char **arr)
{
	int i = 0;

	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
