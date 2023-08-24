#include "monty.h"

void mod(stack_t **stack, unsigned int line_number);

/**
 * mod - computes the rest of the division of the second top
 * element of the stack by the top element of the stack.
 * @stack: stack to work with
 * @line_number: line number of file being executed
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int store;
	(void)line_number;

	store = (*stack)->next->n % (*stack)->n;
	pop(stack, line_number);
	(*stack)->n = store;
}

/**
 * pchar - print the ascii representation of the element on
 * stack
 * @stack: stack to work with
 * @line_number: line number of file being executed
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	printf("%c\n", (char)(*stack)->n);
}
