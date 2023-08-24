#include "monty.h"

void push_error(stack_t *stack, char **arr, int line_number, FILE *fs);
void pop_error(stack_t *stack, char **arr, int line_number, FILE *fs);
void sub_error(stack_t *stack, char **arr, int line_number, FILE *fs);
void mod_error(stack_t *stack, char **arr, int line_number, FILE *fs);
void pchar_error(stack_t *stack, char **arr, int line_number, FILE *fs);
/**
 * push_error - handles push error
 * @stack: stack (double linked list)
 * @arr: array containing opcode command and instruction
 * @line_number: line number where error occurred
 * @fs: file stream of bytecode from which instructions are read
 */
void push_error(stack_t *stack, char **arr, int line_number, FILE *fs)
{
	int count = 0;

	while (arr[count])
		count++;

	if (is_int(arr[1]) == 0 || count == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		_free(arr);
		free_list(stack);
		fclose(fs);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop_error - handles pop error
 * @stack: stack (double linked list)
 * @arr: array containing opcode command and instruction
 * @line_number: line number where error occurred
 * @fs: file stream of bytecode from which instructions are read
 */
void pop_error(stack_t *stack, char **arr, int line_number, FILE *fs)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	_free(arr);
	free_list(stack);
	fclose(fs);
	exit(EXIT_FAILURE);
}

/**
 * sub_error - handles stack error on sub if
 * stack too short
 * @stack: stack to operate on
 * @arr: arr used in other function to be freed before exit
 * @line_number: line on which the error was found
 * @fs: monty byte code file where opcodes were read from
 */
void sub_error(stack_t *stack, char **arr, int line_number, FILE *fs)
{
	fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
	_free(arr);
	free_list(stack);
	fclose(fs);
	exit(EXIT_FAILURE);
}
/**
 * mul_error - handles stack error on mul if
 * stack too short
 * @stack: stack to operate on
 * @arr: arr used in other function to be freed before exit
 * @line_number: line on which the error was found
 * @fs: monty byte code file where opcodes were read from
 */
void mul_error(stack_t *stack, char **arr, int line_number, FILE *fs)
{
	fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
	_free(arr);
	free_list(stack);
	fclose(fs);
	exit(EXIT_FAILURE);
}

/**
 * mod_error - handles stack error on mod
 * @stack: stack to operate on
 * @arr: arr used in other function to be freed before exit
 * @line_number: line on which the error was found
 * @fs: monty byte code file where opcodes were read from
 */
void mod_error(stack_t *stack, char **arr, int line_number, FILE *fs)
{
	if (list_len(stack) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		_free(arr);
		free_list(stack);
		fclose(fs);
		exit(EXIT_FAILURE);
	}
	else if (stack->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		_free(arr);
		free_list(stack);
		fclose(fs);
		exit(EXIT_FAILURE);
	}
}

void pchar_error(stack_t *stack, char **arr, int line_number, FILE *fs)
{
	if (stack == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		_free(arr);
		free_list(stack);
		fclose(fs);
		exit(EXIT_FAILURE);
	}
	else if (stack->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		_free(arr);
		free_list(stack);
		fclose(fs);
		exit(EXIT_FAILURE);
	}
}
