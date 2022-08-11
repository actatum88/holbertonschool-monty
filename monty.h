#ifndef MONTY_H
#define MONTY_H
/*Standard Library*/
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>
/*Macros*/
#define NOT __attribute__
#define USED ((unused))
/*Structs*/
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
	void (*f)(stack_t **stack, unsigned int line_number, char *next);
} instruction_t;
/*main.c*/
void squeeze_spaces(char *str_d);
void push(stack_t **stack, unsigned int line_number, char *next);
void pall(stack_t **stack, unsigned int line_number, char *next);
void (*get_op(char *s))(stack_t **stack, unsigned int line_num, char *next);
void exec_script(char *buf, stack_t *stack);
FILE *monty_init(int ac, char *av[]);
/*Globals*/
extern char *buf;
extern FILE *monty;
#endif
