#include "monty.h"

/* contains helper string functions */
char *_strdup(char *str);
int word_count(char *buffer, const char *delim);
char **string_split(char *str, char *delim);


/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: string parameter
 *
 * Return: pointer to new string or Null
 *
 */

char *_strdup(char *str)
{
	char *arr;
	int i, len;

	if (str == NULL)
		return (NULL);
	len = 0;
	while (str[len])
		len++;

	arr = malloc(len + 1);
	if (!arr)
		return (NULL);
	i = 0;
	while (str[i])
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

/**
 * word_count - count no. of words(strings) in
 * an array
 * @buffer: array
 * @delim: delimiter
 *
 * Return: no of args(strings)
 */
int word_count(char *buffer, const char *delim)
{
	char *buf, *token;
	int argc;

	argc = 0;
	buf = _strdup(buffer);
	if (!buf)
		return (argc);
	token = strtok(buf, delim);
	if (token)
		argc++;
	while (token)
	{
		token = strtok(NULL, delim);
		if (token)
			argc++;
	}
	free(buf);
	return (argc);
}

/**
 * string_split - splits a string into an array of words
 * @str: str to split
 * @delim: delimiter at which to split str
 * Return: Array of string | NULL for str = NULL
 */
char **string_split(char *str, char *delim)
{
	int count = word_count(str, delim), i = 0;
	char **arr = NULL, *new_str = NULL, *token;

	if (str == NULL || delim == NULL)
		return (NULL);

	arr = malloc(sizeof(char *) * (count + 1));
	if (arr == NULL)
		return (NULL);

	new_str = _strdup(str);
	if (!new_str)
	{
		free(arr);
		return (NULL);
	}

	printf("__%d words\n", count);
	token = strtok(new_str, delim);
	while (token != NULL && i < count)
	{
		arr[i] = _strdup(token);
		printf(">>%s\n", arr[i]);
		if (arr[i] == NULL)
		{
			free_to_index(arr, i);
			free(new_str);
			return (NULL);
		}
		i++;
		token = strtok(NULL, delim);
	}

	arr[i] = NULL;
	free(new_str); /* Free the temporary string copy */
	return (arr);
}
