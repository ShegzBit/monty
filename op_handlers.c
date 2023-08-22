#include "monty.h"

/**
 * push - pushes an element unto a stack
 * @stack: pointer to stack to push element unto
 * @line_number: element to push unto stack
 */
void push(stack_t **stack, unsigned int line_number)
{
	st_node temp = malloc(sizeof (stack_t));

	temp->n = n;
	temp->next = *stack;
	*stack = temp;
}

/**
 * pall - prints all elements on a stack
 * @stack: stack to print from
 * @line_number: a not so neccessary argument
 */
void pall(stack_t **stack, unsigned int line_number)
{
	st_node temp;

	(void)line_number;
	if (stack == NULL || *stack == NULL)
		return;
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
	}
}
