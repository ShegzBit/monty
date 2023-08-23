#include "monty.h"

int data = 0;

/**
 * main - calls all functions and execute interpreter
 * @ac: Argument count
 * @av: Argument vector
 * Return: 0 on success | EXIT_FAILURE otherwise
 */
int main(int ac, char **av)
{
	char *filename = av[1];
	FILE *fs;
	/*Main stack of operation*/
	stack_t *_stack = NULL;

	/*Check for invalid arguments*/
	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fs = fopen(filename, "r");
	/*Check cannot open file filename*/
	if (fs == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	_execute(&_stack, fs);
	free_list(_stack);
	return (0);
}
