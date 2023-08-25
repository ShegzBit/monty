#include "monty.h"

void pstr(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);

/**
 * pstr - prints the string starting at the top of the
 * stack, followed by a new line.
 * @stack: stack to work with
 * @line_number: line number of file being executed
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;

	(void)line_number;
	if (*stack == NULL)
	{
		printf("\n");
		return;
	}
	for (; ptr != NULL; ptr = ptr->next)
	{
		if (ptr->n == 0 || ptr->n > 127)
			break;
		printf("%c", ptr->n);
	}
	printf("\n");
}

/**
 * rotr - rotates the stack to the bottom.
 * stack, followed by a new line.
 * @stack: stack to work with
 * @line_number: line number of file being executed
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	(void)line_number;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return;

	while (ptr->next)
		ptr = ptr->next;

	ptr->next = *stack;
	(*stack)->prev = ptr;
	ptr->prev->next = NULL;
	ptr->prev = NULL;
	*stack = ptr;
}

/**
 * stack - sets the format of the data to a stack (LIFO) by doing nothing
 * default format is already stack
 * @stack: stack
 * @line_number: line number of pop instruction
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
