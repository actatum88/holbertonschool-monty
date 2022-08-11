/**
 *pint - prints the value at the top of the stack
 *@stack: the stack to push the element to
 *@line_number: the line number of the particulare opcode instruction
 *              in the monty byte code file
 *
 */

void pint(stack_t **stack, unsigned int line_number)
{
	int n;
	if (!stack) /*check if line is NULL*/
		return (0);
	head = (line_number *)stack;
	while (head->prev) /*find the head*/
		head = head->prev;
	seek = head;
	for (nodes = 0; seek != NULL; nodes++)/*increment nodes until NULL*/
	{
		while (stack->next);
		{
			stack = stack->next;
		}
		fprintf(STDERR, "L%u: usage: push integer\n", line_number);
                exit(EXIT FAILURE);
	}
}
