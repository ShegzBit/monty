#include "monty.h"

void pstr(stack_t **stack, unsigned int line_number);

/**
 * pstr - prints the string starting at the top of the
 * stack, followed by a new line.
 * @stack: stack to work with
 * @line_number: line number of file being executed
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	int flag = 0;
	stack_t *ptr = *stack;
	(void)line_number;

	if ((*stack) == NULL)
	{
		printf("\n");
		return;
	}
	while ((ptr->n > 0 && ptr->n < 128) && ptr)
	{
		flag = 1;
		printf("%c", ptr->n);
		ptr = ptr->next;
	}
	if (flag)
		printf("\n");
}
