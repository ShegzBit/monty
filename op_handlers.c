#include "monty.h"

/**
 * push - pushes an element unto a stack
 * @stack: pointer to stack to push element unto
 * @line_number: element to push unto stack
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = malloc(sizeof(stack_t));

	(void)line_number;
	temp->n = data;
	temp->next = *stack;
	temp->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = temp;
	*stack = temp;
}

/**
 * pall - prints all elements on a stack
 * @stack: stack to print from
 * @line_number: a not so neccessary argument
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int i;
	(void)line_number;
	if (stack == NULL || *stack == NULL)
		return;
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp->prev = temp;
		temp = temp->next;
	}
	free(temp);
}

/**
 * pint - prints the element on the top of the stack
 * @stack: stack to work with
 * @line_number: line number of file being executed
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL)
		return;
	if (*stack == NULL)
	{
		fprintf(stderr, "L<%d>: can't pint, stack empty\n", line_number);
		free_list(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
