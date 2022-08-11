#include "monty.h"
#include "global.h"

void exec_script(char *buf, stack_t *stack)
{
	size_t line = 1, nchars = 0;
	const char delim = ' ';
	void (*f)(stack_t **stack, unsigned int line_number, char *next);
	FILE *monty;

        /*Read each line of your Monty script*/
	while (getline(&buf, &nchars, monty) != EOF && line++)
	{
		squeeze_spaces(buf); /*Sanitize the input*/
		if (*buf)
		{
			f = get_op(strtok(buf, &delim)); /*Get the first word as a function*/
			if (f)
				f(&stack, line, strtok(NULL, &delim));
			else
			{
				fprintf(stderr, "L%lu: unknown instruction %s\n", line, buf);
			}
		}
	}
}
