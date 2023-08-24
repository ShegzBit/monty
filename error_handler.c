#include "monty.h"

void pint_error(stack_t *stack, char **arr, int line_number, FILE *fs);
void swap_error(stack_t *stack, char **arr, int line_number, FILE *fs);
void add_error(stack_t *stack, char **arr, int line_number, FILE *fs);

/**
 * pint_error - handles error on stack for pint
 * @stack: stack to operate on
 * @arr: arr used in other function to be freed before exit
 * @line_number: line on which the error was found
 * @fs: monty byte code file where opcodes were read from
 */
void pint_error(stack_t *stack, char **arr, int line_number, FILE *fs)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	_free(arr);
	free_list(stack);
	fclose(fs);
	exit(EXIT_FAILURE);
}

/**
 * swap_error - handles stack error on swap
 * stack too short
 * @stack: stack to operate on
 * @arr: arr used in other function to be freed before exit
 * @line_number: line on which the error was found
 * @fs: monty byte code file where opcodes were read from
 */
void swap_error(stack_t *stack, char **arr, int line_number, FILE *fs)
{
	fprintf(stderr, "L<%d>: can't swap, stack too short\n", line_number);
	_free(arr);
	free_list(stack);
	fclose(fs);
	exit(EXIT_FAILURE);
}

/**
 * add_error - handles stack error on add
 * stack too short
 * @stack: stack to operate on
 * @arr: arr used in other function to be freed before exit
 * @line_number: line on which the error was found
 * @fs: monty byte code file where opcodes were read from
 */
void add_error(stack_t *stack, char **arr, int line_number, FILE *fs)
{
	fprintf(stderr, "L<%d>: can't add, stack too short\n", line_number);
	_free(arr);
	free_list(stack);
	fclose(fs);
	exit(EXIT_FAILURE);
}
