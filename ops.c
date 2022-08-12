#include "monty.h"

/**
 * push - pushes an element to the top of a stack
 * @stack: data stack to write tod
 * @line_number: line number of this instruction from called script
 */
void push(stack_t **stack, unsigned int line_number)
{
	int i;
	stack_t *temp, *newNode;
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
			fclose(data.script);
			free(data.buf);
			if (stack)
			{
				for (temp = *stack; temp; free(*stack), *stack = temp)
					temp = temp->next;
				free(*stack);
			}
			exit(EXIT_FAILURE);
		}
	}
	newNode = malloc(sizeof(*newNode));
	if (!newNode)
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);
	newNode->n = atoi(arg);
	newNode->next = newNode->prev = NULL;
	if (*stack)
	{
	/* for (temp = *stack; temp->next;) */
	/* 	temp = temp->next; */
		newNode->next = *stack; /* newNode; */
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

	/* printf("L: %u, Print them all!\n", line_number); Diagnostic print*/
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
 * nop - NO operator, does nothing.
 * @stack: ignored
 * @line_number: ignored
 */
void nop(NOT USED stack_t **stack, NOT USED unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
