#include "monty.h"

int main(int ac, char **av)
{
	char *filename = av[1];
	int read_byte;

	/*Check for invalid arguments*/
	if (ac != 2)
	{
		print("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	FILE *fs = fopen(filename, "r");
	/*Check cannot open file filename*/
	if (fd == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}
