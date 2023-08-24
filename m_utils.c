#include "monty.h"

char *_strdup(char *str);

/*Contains utility functions for efficient and sufficient use of opfuncs*/

int _execute(stack_t **_stack, FILE *fs);
int count_word(char *str);
char **split_string(char *str, char *delim);
void _free(char **arr);
int stack_error(stack_t *stack, char *opcode, char **arr,
		int line_number, FILE *fs);

/**
 * count_word - counts number of words in a string
 * @str: string to count through
 * Return: number of words in a string | 0 for NULL
 */
int count_word(char *str)
{
	int is_space = 1,/*False*/ i, word_count = 0;
	/*   this is a    boy*/

	if (str == NULL)
		return (0);
	for (i = 0; str[i]; i++)
	{
		if (str[i] == ' ')
			is_space = 1;

		else if (str[i] != ' ')
		{
			if (is_space == 1)
				word_count++;
			is_space = 0;
		}
	} return (word_count);
}

/**
 * split_string - splits a string into an array of words
 * @str: str to split
 * @delim: delimiter at which to split str
 * Return: Array of string | NULL for str = NULL
 */
char **split_string(char *str, char *delim)
{
	int word_count = count_word(str), i = 0;
	char **arr;

	if (str == NULL || delim == NULL)
		return (NULL);

	arr = malloc(sizeof(char *) * (word_count + 1));
	if (arr == NULL)
		return (NULL);

	arr[i++] = _strdup(strtok(str, delim));
	while (i < word_count && arr[i - 1] != NULL)
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
	if ((strcmp(opcode, "pop") == 0) && stack == NULL)
		pop_error(stack, arr, line_number, fs);
	if ((strcmp(opcode, "swap") == 0) && list_len(stack) < 2)
		swap_error(stack, arr, line_number, fs);
	if ((strcmp(opcode, "add") == 0) && list_len(stack) < 2)
		add_error(stack, arr, line_number, fs);

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
	size_t i = 1, word_count;
	char lineptr[BUFFER_SIZE], **arr;
	func_op op_handler;

	while (fgets(lineptr, sizeof(lineptr), fs) != NULL)
	{
		word_count = count_word(lineptr);
		arr = split_string(lineptr, " \n");
		/*Extern int data in .h file*/
		stack_error(*_stack, arr[0], arr, i, fs);
		op_handler = get_op(arr[0]);
		if (op_handler == NULL)
		{
			fprintf(stderr, "L<%ld>: unknown instruction <%s>\n", i, arr[0]);
			_free(arr);
			return (-1);
		}
		/*Extern int data in .h file*/
		if (word_count >= 2)
			data = atoi(arr[1]);
		op_handler(_stack, i++);
		_free(arr);
	}
	return (0);
}
