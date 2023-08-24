#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void free_all(char **arr);
void free_to_index(char **arr, int i);
void _free(char **arr);

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
 * return_num_of_arg - returns no. of args(strings) in
 * an array
 * @buffer: array
 * @delim: delimiter
 *
 * Return: no of args(strings)
 */
int return_num_of_arg(char *buffer, const char *delim)
{
	char *buf, *token;
	int argc;

	argc = 0;
	buf = strdup(buffer);
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

char **split_string(char *str, char *delim)
{
    int word_count = return_num_of_arg(str, delim), i = 0;
    char **arr = NULL, *new_str = NULL;

    if (str == NULL || delim == NULL)
        return NULL;

    arr = malloc(sizeof(char *) * (word_count + 1));
    if (arr == NULL)
        return NULL;

    new_str = strdup(str);
    if (!new_str)
    {
        free(arr);
        return NULL;
    }

    char *token = strtok(new_str, delim);
    while (token != NULL && i < word_count)
    {
        arr[i] = strdup(token);
        if (arr[i] == NULL)
	{
            free_to_index(arr, i);
            free(new_str);
            return NULL;
        }
        i++;
        token = strtok(NULL, delim);
    }

    arr[i] = NULL;
    free(new_str); /* Free the temporary string copy */
    return arr;
}

void free_to_index(char **arr, int i)
{
        while (i)
        {
                free(arr[i]);
                i--;
        }
        free(arr);
}

/**
 */
void free_all(char **arr)
{
        int i = 0;

        while (arr[i])
        {
                free(arr[i]);
                i++;
        }
        free(arr);
}

int main(void)
{
	char *str = "      hey     its    m   ";
	char **arr;
	int i = 0;

	arr = split_string(str, " \n");
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
	free_all(arr);

	return 0;
}
