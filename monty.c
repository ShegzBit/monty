#include "monty.h"

int main(int ac, char **av)
{
	char *filename = av[1];
	int read_byte;
	/*Main stack of operation*/
	stack_t _stack;

	/*Check for invalid arguments*/
	if (ac != 2)
	{
		print("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	FILE *fs = fopen(filename, "r");
	/*Check cannot open file filename*/
	if (fs == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}
