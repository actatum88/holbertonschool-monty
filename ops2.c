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
	temp = *stack;

	*stack = (*stack)->next;

	free(temp);
}
