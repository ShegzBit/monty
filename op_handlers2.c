#include "monty.h"

/**
 * pop - removes an element from top of stack
 * @stack: stack
 * @line_number: line number of pop instruction
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	if (!*stack)
		return;
	if ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		tmp->next->prev = NULL;
		free(tmp);
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}
