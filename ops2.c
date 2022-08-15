#include "monty.h"

/**
 * pop - removes top stack element
 * @stack: stack data element
 * @line_number: number of script that called this function
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		freestuff(stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;

	*stack = (*stack)->next;

	free(temp);
}

/**
 *swap - swaps the top two elements of the stack
 *@stack: the stack to push the element to
 *@line_number: the line number of the particulare opcode instruction
 *              in the monty byte code file
 *
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int newN;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		freestuff(stack);
		exit(EXIT_FAILURE);
	}
	newN = (*stack)->n;

	(*stack)->n = (*stack)->next->n;
/*setting the first number to the next number*/
	(*stack)->next->n = newN;
}
