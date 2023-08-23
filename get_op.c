#include "monty.h"

/**
 * get_op - gets the right op handler for instruction
 * @opcode: instruction to carry out
 * Return: right op handler
 */
func_op get_op(char *opcode)
{
	instruction_t handlers[] = {
		{"pint", pint},
		{"pall", pall},
		{"push", push},
		{NULL, NULL}
	};
	int i;

	for (i = 0; handlers[i].opcode != NULL; i++)
		if ((strcmp(handlers[i].opcode, opcode) == 0))
			return (handlers[i].opfunc);
	return (NULL);
}
