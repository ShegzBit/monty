#include "monty.h"

void pop_error(stack_t *stack, char **arr, int line_number, FILE *fs);

/**
 * pop_error - handles pop error
 * @stack: stack (double linked list)
 * @arr: array containing opcode command and instruction
 * @line_number: line number where error occurred
 * @fs: file stream of bytecode from which instructions are read
 */
void pop_error(stack_t *stack, char **arr, int line_number, FILE *fs)
{
	fprintf(stderr, "L%d: can't pop, an empty stack\n", line_number);
	_free(arr);
	free_list(stack);
	fclose(fs);
	exit(EXIT_FAILURE);
}
