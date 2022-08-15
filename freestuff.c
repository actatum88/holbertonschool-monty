#include "monty.h"

/**
 * freestuff - frees all used data
 * @stack: implicit double pointer to data stack
 */

void freestuff(stack_t **stack)
{
	stack_t *temp;
/*
 * By the time we actually reach this point in execution some of this
 * should be always true or never true, so ifs may not be needed
 */
	if (data.script)
		fclose(data.script);
	if (data.buf)
		free(data.buf);
	if (stack)
	{
		for (temp = *stack; temp; free(*stack), *stack = temp)
			temp = temp->next;
		free(*stack);
	}
}
