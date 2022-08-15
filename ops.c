#include "monty.h"
#include "limits.h"
/**
 * push - pushes an element to the top of a stack
 * @stack: data stack to write tod
 * @line_number: line number of this instruction from called script
 */
void push(stack_t **stack, unsigned int line_number)
{
	int i;
	stack_t *temp, *newNode = NULL;
	char *arg = data.buf + 5;

	if (!*arg)
		goto fail;
	for (i = 0; arg[i] && arg[i] != 32; i++)
	{
		if (arg[i] == '-')
			continue;
		if (arg[i] == 32 || arg[i] < 48 || arg[i] > 57)
		{
fail:			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			freestuff(stack);
			exit(EXIT_FAILURE);
		}
	}
	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freestuff(stack);
		exit(EXIT_FAILURE);
	}
	newNode->n = atoi(arg);
	newNode->next = newNode->prev = NULL;
	if (*stack)
	{
		newNode->next = *stack;
		(*stack)->prev = newNode;
	}
	*stack = newNode;
}
/**
 * pall - prints all elements of @stack
 * @stack: data stack to print out
 * @line_num: line number of calling script that matched this spec
 */
void pall(stack_t **stack, NOT USED unsigned int line_num)
{
	stack_t *temp;

	if (*stack)
	{
		temp = *stack;
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
}

/**
 *pint - prints the value at the top of the stack
 *@stack: the stack to push the element to
 *@line_number: the line number of the particulare opcode instruction
 *              in the monty byte code file
 *
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		freestuff(stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * nop - NO operator, does nothing.
 * @stack: ignored
 * @line_number: ignored
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * add - adds top two stack elements
 * @stack: stack data input
 * @line_number: number of script that called this function
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int newN;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		freestuff(stack);
		exit(EXIT_FAILURE);
	}
	newN = (*stack)->n + (*stack)->next->n;

	temp = *stack;

	*stack = (*stack)->next;

	(*stack)->prev = NULL;

	free(temp);

	(*stack)->n = newN;
}
