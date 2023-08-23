#include "monty.h"

void pint_error(stack_t *stack, char *lineptr, char **arr, int line_number, FILE *fs)
{
	fprintf(stderr, "L<%d>: can't pint, stack empty\n", line_number);
	_free(arr);
	free(lineptr);
	free_list(stack);
	fclose(fs);
	exit(EXIT_FAILURE);
}
