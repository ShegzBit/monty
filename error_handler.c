#include "monty.h"

/**
 * pint_error - prints the value at the top of the stack,
 * followed by a new line.
 * @stack: stack (double linked list)
 * @arr: array containing opcode command and instruction
 * @line_number: line number where error occurred
 * @fs: file stream of bytecode from which instructions are read
 */
void pint_error(stack_t *stack, char **arr, int line_number, FILE *fs)
{
	fprintf(stderr, "L<%d>: can't pint, stack empty\n", line_number);
	_free(arr);
	free_list(stack);
	fclose(fs);
	exit(EXIT_FAILURE);
}
