#include "monty.h"

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

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
		temp->prev = temp;
		temp = temp->next;
	}
}

/**
 * pint - prints the element on the top of the stack
 * @stack: stack to work with
 * @line_number: line number of file being executed
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (stack == NULL)
		return;
	printf("%d\n", (*stack)->n);
}

/**
 * swap - swaps the value of the top and second
 * element on the stack
 * @stack: stack to work with
 * @line_number: line number of file being executed
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int store;

	(*stack) = (*stack)->next;
	store = temp->n;
	temp->n = (*stack)->n;
	(*stack)->n = store;
	*stack = temp;
}
