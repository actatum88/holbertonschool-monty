#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>

/**
 * argument - global variable to hold the value of the argument.
 *
 */
typedef struct arg
{
    char *argument;
}arg;
arg Arg;

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
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/*errcat.c*/
char *errcat(char *pname, char *cname);
/*main.c*/
int main(int ac, char *av[]);
/*opcode.c*/
void pushOp(stack_t stack, unsigned int line_number);
void run_opcode(char *opcode, stack_t **stack, unsigned int line_number
);
void pintOp(stack_t stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);

extern char *global;

#endif
