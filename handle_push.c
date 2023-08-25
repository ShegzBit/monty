#include "monty.h"

/**
 * pick_push - uses the right implementation for the right
 * list format
 * LIFO | FIFO
 * @stack: stack
 * @line_number: line number of pop instruction
 */
void pick_push(stack_t **stack, unsigned int line_number)
{
	if (is_queue == 0)
		push(stack, line_number);
	else
		queue_push(stack, line_number);
}
