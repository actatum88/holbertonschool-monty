#include "monty.h"


/**
 * m_mod - modulos top two stack elements
 * @stack: stack data input
 * @line_number: number of script that called this function
 */
void m_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int newN;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
fail:		freestuff(stack);
		exit(EXIT_FAILURE);
	}

	if (!(*stack)->n)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		goto fail;
	}
	newN = (*stack)->next->n % (*stack)->n;

	temp = *stack;

	*stack = (*stack)->next;

	(*stack)->prev = NULL;

	free(temp);

	(*stack)->n = newN;
}

