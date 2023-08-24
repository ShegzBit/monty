#include "monty.h"

/*Contains utility functions for efficient and sufficient use of opfuncs*/

int _execute(stack_t **_stack, FILE *fs);
char **split_string(char *str, char *delim);
void _free(char **arr);
int stack_error(stack_t *stack, char *opcode, char **arr,
		int line_number, FILE *fs);
/**
 * string_split - splits a string into an array of words
 * @str: str to split
 * @delim: delimiter at which to split str
 * Return: Array of string | NULL for str = NULL
 */
char **string_split(char *str, char *delim)
{
	int word_c = word_count(str, delim), i = 0;
	char **arr;

	if (str == NULL || delim == NULL)
		return (NULL);

	arr = malloc(sizeof(char *) * (word_c + 1));
	if (arr == NULL)
		return (NULL);

	arr[i++] = _strdup(strtok(str, delim));
	while (i < word_c && arr[i - 1] != NULL)
		arr[i++] = _strdup(strtok(NULL, delim));
	arr[i] = NULL;
	return (arr);
}

/**
 * _free - frees a strtok arr
 *@arr: array to free
 */
void _free(char **arr)
{
	unsigned int i;

	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
}

/**
 * stack_error - check the stack for sufficient number of element
 * @stack: stack to work on
 * @opcode: opcode to search for
 * @arr: arr used in _execute to be freed before exit
 * @line_number: line number on which error was spotted
 * @fs: file opcodes were read from
 * Return: 0 on executable | -1 otherwise
 */
int stack_error(stack_t *stack, char *opcode, char **arr,
		int line_number, FILE *fs)
{
	if ((strcmp(opcode, "pint") == 0) && stack == NULL)
		pint_error(stack, arr, line_number, fs);
	else if ((strcmp(opcode, "pop") == 0) && stack == NULL)
		pop_error(stack, arr, line_number, fs);
	else if ((strcmp(opcode, "swap") == 0) && list_len(stack) < 2)
		swap_error(stack, arr, line_number, fs);
	else if ((strcmp(opcode, "add") == 0) && list_len(stack) < 2)
		add_error(stack, arr, line_number, fs);
	else if ((strcmp(opcode, "sub") == 0) && list_len(stack) < 2)
		sub_error(stack, arr, line_number, fs);
	else if (strcmp(opcode, "div") == 0)
	{
		if (list_len(stack) < 2)
			_div_error(stack, arr, line_number, fs);
		else if (list_len(stack) >= 2 && (stack->n == 0))
			zero_error(stack, arr, line_number, fs);
	}

	return (0);

}
/**
 * _execute - reads each line from file fs and executes it
 * @fs: file passed to execute to read from
 * @_stack: stack on which to operate
 * Return: 1 on success | 0 otherwise
 */
int _execute(stack_t **_stack, FILE *fs)
{
	size_t i = 1, count;
	char lineptr[BUFFER_SIZE], **arr;
	func_op op_handler;
	char *delim = " \n\t\b";

	while (fgets(lineptr, sizeof(lineptr), fs) != NULL)
	{
		count = word_count(lineptr, delim);
		if (count == 0)
			continue;
		arr = _string_split(lineptr, delim);
		if (!arr)
			continue;
		/*Extern int data in .h file*/
		stack_error(*_stack, arr[0], arr, i, fs);
		op_handler = get_op(arr[0]);
		if (op_handler == NULL)
		{
			fprintf(stderr, "L<%ld>: unknown instruction <%s>\n", i, arr[0]);
			free_all(arr);
			return (-1);
		}
		/*Extern int data in .h file*/
		if (count >= 2)
			data = atoi(arr[1]);
		op_handler(_stack, i++);
		free_all(arr);
	}
	return (0);
}
