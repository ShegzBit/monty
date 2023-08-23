#include "monty.h"
#include <stdio.h>

/*Contains utility functions for efficient and sufficient use of opfuncs*/

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
	char **arr, *new_str;

	if (str == NULL || delim == NULL)
		return (NULL);

	arr = malloc(sizeof(char *) * word_count);
	if (arr == NULL)
		return (NULL);

	new_str = strdup(str);
	arr[i++] = strtok(new_str, delim);
	while (i < word_count && arr[i - 1] != NULL)
		arr[i++] = strtok(NULL, delim);
	return (arr);
}


void _free(char **arr)
{
	free(*arr);
	free(arr);
}
/**
 * _execute - reads each line from file fs and executes it
 * @fs: file passed to execute to read from
 * @_stack: stack on which to operate
 * Return: 1 on success | 0 otherwise
 */
int _execute(stack_t **_stack, FILE *fs)
{
	size_t read_byte, i = 0, size = 0, word_count;
	char *lineptr = NULL, **arr;
	func_op op_handler;

	while ((read_byte = getline(&lineptr, &size, fs)) != -1)
	{
		word_count = count_word(lineptr);
		arr = split_string(lineptr, " \n");
		/*Extern int data in .h file*/
		op_handler = get_op(arr[0]);
		if (op_handler == NULL)
		{
			_free(arr);
			free(lineptr);
			return (-1);
		}
		/*Extern int data in .h file*/
		if (word_count >= 2)
			data = atoi(arr[1]);
		op_handler(_stack, ++i);
		_free(arr);
	}
	free(lineptr);
	return (0);
}
