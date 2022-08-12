#include "monty.h"

/**
 * exec_script - runs stack ops from a monty script
 * @stack: data stack for each subroutine
 */
void exec_script(stack_t **stack)
{
	const char delim = ' ';
	size_t line = 0, nchars = 0;
	stack_t *temp;
	void (*f)(stack_t **stack, unsigned int line_number);

	data.buf = NULL;

	/*Read each line of your Monty script*/
	while (getline(&data.buf, &nchars, data.script) != EOF && ++line)
	{
		if (!data.buf)
		{
			fprintf(stderr, "Error: malloc failed\n");
			fclose(data.script);
			exit(EXIT_FAILURE);
		}
		squeeze_spaces(data.buf); /*Sanitize the input*/
		if (*(data.buf) && *(data.buf) != '\n')
		{
			f = get_op(strtok(data.buf, &delim)); /*Get the first word as a function*/
			if (f)
				f(stack, line);
			else
			{
				fprintf(stderr, "L%lu: unknown instruction %s\n", line, data.buf);
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
	}
	if (data.buf)
		free(data.buf);
}
