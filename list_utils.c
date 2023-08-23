#include "monty.h"

void free_list(stack_t *stack);
int list_len(stack_t *stack);

/**
 * free_list - frees a linked list stack
 * @stack: stack to free
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
 * list_len - counts the number of element in a stack
 * @stack: stack to work on
 * Return: size of len
 */
int list_len(stack_t *stack)
{
	int i;

	for (i = 0; stack != NULL; stack = stack->next, i++)
		;
	return (i);
}
