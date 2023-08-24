#include "monty.h"

/* contains helper freeing functions */
void free_list(stack_t *stack);
void free_to_index(char **arr, int i);
void free_all(char **arr);


/**
 * free_list - frees a doubly linked list (stack)
 * @stack: doubly linked list
 */
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
 * free_to_index - frees a 2d array upto index then frees array
 * @arr: 2d array
 * @i: index
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
 * free_all - frees a 2d array
 * @arr: 2d array
 */
void free_all(char **arr)
{
	int i = 0;

	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
