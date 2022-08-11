#include "monty.h"
#include "global.h"

/**
 * push - pushes an element to the top of a stack
 * @stack: data stack to write tod
 * @line_number: line number of this instruction from called script
 * @next: second word of script line to store as int in @stack
 */
void push(stack_t **stack, unsigned int line_number, char *next)
{
	stack_t *temp;
	stack_t *newNode;

	if (!atoi(next))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	newNode = malloc(sizeof(*newNode));
	if (!newNode)
		return;
	newNode->n = atoi(next);
	newNode->next = NULL;
	newNode->prev = NULL;

	if (!*stack)
	{
		*stack = newNode;
		return;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;

	temp->next = newNode;
	newNode->prev = temp;
}
/**
 * pall - prints all elements of @stack
 * @stack: data stack to print out
 * @line_num: line number of calling script that matched this spec
 * @next: ignored for pall
 */
void pall(stack_t **stack, NOT USED unsigned int line_num, NOT USED char *next)
{
	stack_t *temp;

	(void) next;
	/* printf("L: %u, Print them all!\n", line_number); Diagnostic print*/
	if (*stack)
	{
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->prev;
		}
	}
}
