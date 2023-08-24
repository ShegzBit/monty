#include "monty.h"

void pop(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);

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

/**
 * nop - does nothing
 * @stack: stack
 * @line_number: line number of pop instruction
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub - subtracts the top element of the stack from the 
 * second top element of the stack.
 * the stack pop the first and assign the sum to the second
 * @stack: stack to work with
 * @line_number: line number of file being executed
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int store;

	(void)line_number;
	store = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = store;
}
