#include "monty.h"

/**
 * exec_script - runs stack ops from a monty script
 * @stack: data stack for each subroutine
 */
void exec_script(stack_t **stack)
{
	const char delim = ' ';
	size_t line = 0, nchars = 0;
	void (*f)(stack_t **stack, unsigned int line_number);

	data.buf = NULL;

	/*Read each line of your Monty script*/
	while (getline(&data.buf, &nchars, data.script) != EOF && ++line)
	{
		squeeze_spaces(data.buf); /*Sanitize the input*/

		if (!*(data.buf)) /*This is how we catch an empty line*/
			continue;

		f = get_op(strtok(data.buf, &delim)); /*Get the first word as a function*/

		if (!f)
		{
			fprintf(stderr, "L%lu: unknown instruction %s\n", line, data.buf);
			freestuff(stack);
			exit(EXIT_FAILURE);
		}

		f(stack, line);
	}
}
