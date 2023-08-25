#include "monty.h"

int handle_comment(char *str);
int is_int(char *str);

/**
 * handle_comment - handles comment by not executing line
 * @str: string to compare for #
 *
 * Return: 1 if comment or 0 if not
 */
int handle_comment(char *str)
{
	if (strcmp(str, "#") == 0 || *str == '#')
		return (1);
	return (0);
}

/**
 * is_int - checks if string contains only integers
 * @str: string
 *
 * Return: 1 if true or 0 if false
 */
int is_int(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
