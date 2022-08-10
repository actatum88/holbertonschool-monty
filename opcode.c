#include "monty.h"

/**
 * pushOp - Pushes an element to the stack
 * @stack: double linked list containing the stack
 * @line_number: value of new node
 */
/*Saving for later!*/



/**
 *run_opcode - executes a particular function that
 *             implements a monty byte code opcode
 *@opcode: the name of the opcode to execute
 *@stack: the stack where the opcode will be implemented on
 *@line_number: the line number in the byte code file
 *              that contains this particular opcode
 *
 *Return: void
 */

void run_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t opcode_list[] = {
                {"push", push},
                {"pall", pall},
                {"pint", pint},
                {"pop", pop},
                {"swap", swap},
                {"add", add},
                {"nop", nop},
                {NULL, NULL}
};
/*OPCODES = List of known stack operations */

	i = 0;
	while (opcode_list[i].opcode)
	{
		if (strcmp(opcode_list[i].opcode, opcode) == 0)
		{
			opcode_list[i].f(stack, line_number);
		return;
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

/**
 *push - pushes an element onto a stack
 *@stack: the stack to push the element to
 *@line_number: the line number of the particulare opcode instruction
 *              in the monty byte code file
 *
 */

void push(stack_t **stack, unsigned int line_number)
{
	int n;
	{
		dprintf(STDERR, "L%u: usage: push integer\n", line_number);
	       
	}
}
