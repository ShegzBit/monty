#include "monty.h"

void pop(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);

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
		(*stack)->prev = NULL;
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

/**
 * _div - divides the second element of the stack
 * by the top element of the stack.
 * the stack pop the first and assign the value to the second
 * @stack: stack to work with
 * @line_number: line number of file being executed
 */
void _div(stack_t **stack, unsigned int line_number)
{
	int div;
	stack_t *temp = *stack;

	(*stack) = (*stack)->next;
	div = (*stack)->n / temp->n;
	*stack = temp;
	pop(stack, line_number);
	(*stack)->n = div;
}

/**
 * mul - multiplies the second element of the stack
 * by the top element of the stack.
 * the stack pop the first and assign the value to the second
 * @stack: stack to work with
 * @line_number: line number of file being executed
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int mul;
	stack_t *temp = *stack;

	(*stack) = (*stack)->next;
	mul = (*stack)->n * temp->n;
	*stack = temp;
	pop(stack, line_number);
	(*stack)->n = mul;
}
