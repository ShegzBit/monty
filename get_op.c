#include "monty.h"

func_op get_op(char *opcode);

/**
 * get_op - gets the right op handler for instruction
 * @opcode: instruction to carry out
 * Return: right op handler
 */
func_op get_op(char *opcode)
{
	instruction_t handlers[] = {
		{"rotl", rotl},
		{"pchar", pchar},
		{"mul", mul},
		{"div", _div},
		{"add", add},
		{"swap", swap},
		{"pint", pint},
		{"pall", pall},
		{"push", push},
		{"pop", pop},
		{"nop", nop},
		{"sub", sub},
		{"mod", mod},
		{"pstr", pstr},
		{"rotr", rotr},
		{"stack", stack},
		{NULL, NULL}
	};
	int i;

	for (i = 0; handlers[i].opcode != NULL; i++)
		if ((strcmp(handlers[i].opcode, opcode) == 0))
			return (handlers[i].opfunc);
	return (NULL);
}
