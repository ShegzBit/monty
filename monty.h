#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>


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

/*op-stack error handlers*/
void pint_error(stack_t *stack, char *lineptr, char **arr,
		int line_number, FILE *fs);
int stack_error(stack_t *stack, char *opcode, char *lineptr, char **arr,
		int line_number, FILE *fs);

#endif /*_MONTY_H_*/
