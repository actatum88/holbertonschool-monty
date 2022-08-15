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


/**
 * sub - subtracts top two stack elements
 * @stack: stack data input
 * @line_number: number of script that called this function
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int newN;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		freestuff(stack);
		exit(EXIT_FAILURE);
	}
	newN = (*stack)->next->n - (*stack)->n;

	temp = *stack;

	*stack = (*stack)->next;

	(*stack)->prev = NULL;

	free(temp);

	(*stack)->n = newN;
}


/**
 * m_div - divides top two stack elements
 * @stack: stack data input
 * @line_number: number of script that called this function
 */
void m_div(stack_t **stack, unsigned int line_number)
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
	newN = (*stack)->next->n / (*stack)->n;

	temp = *stack;

	*stack = (*stack)->next;

	(*stack)->prev = NULL;

	free(temp);

	(*stack)->n = newN;
}


/**
 * m_mul - multiplies top two stack elements
 * @stack: stack data input
 * @line_number: number of script that called this function
 */
void m_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int newN;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		freestuff(stack);
		exit(EXIT_FAILURE);
	}

	newN = (*stack)->n * (*stack)->next->n;

	temp = *stack;

	*stack = (*stack)->next;

	(*stack)->prev = NULL;

	free(temp);

	(*stack)->n = newN;
}
