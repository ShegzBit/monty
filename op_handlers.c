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
	/*int i;*/
	(void)line_number;
	if (stack == NULL || *stack == NULL)
		return;
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	free(temp);
}
