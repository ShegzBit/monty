#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 1024 * 10

/*External variable for data*/
extern int data;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/*Type definitions*/
typedef void (*func_op)(stack_t **stack, unsigned int line_number);

/*Op Handlers*/
void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        func_op opfunc;
} instruction_t;

/*Utility functions*/
int count_word(char *str);
char **split_string(char *str, char *delim);
int _execute(stack_t **_stack, FILE *fs);
func_op get_op(char *opcode);
void free_list(stack_t *stack);
void _free(char **arr);
int list_len(stack_t *stack);
char *_strdup(char *str);
int word_count(char *buffer, const char *delim);
char **string_split(char *str, char *delim);
char **_string_split(char *str, char *delim);
void free_all(char **arr);
void free_to_index(char **arr, int i);

/*op-stack error handlers*/
void pint_error(stack_t *stack, char **arr,int line_number, FILE *fs);
int stack_error(stack_t *stack, char *opcode, char **arr,
		int line_number, FILE *fs);
void pop_error(stack_t *stack, char **arr, int line_number, FILE *fs);
void swap_error(stack_t *stack, char **arr, int line_number, FILE *fs);
void add_error(stack_t *stack, char **arr, int line_number, FILE *fs);
void sub_error(stack_t *stack, char **arr, int line_number, FILE *fs);
void _div_error(stack_t *stack, char **arr, int line_number, FILE *fs);
void zero_error(stack_t *stack, char **arr, int line_number, FILE *fs);
void mul_error(stack_t *stack, char **arr, int line_number, FILE *fs);

#endif /*_MONTY_H_*/
