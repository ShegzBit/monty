#include "monty.h"
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

char **split_string(char *str)
{
	if (str == NULL)
		return (NULL);
}
