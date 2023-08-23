#include "monty.h"

void free_list(stack_t *stack)
{
	stack_t *temp = stack;
	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
