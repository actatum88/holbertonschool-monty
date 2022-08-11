#include "monty.h"
/**
 * main - implement the push and pall opcodes.
 * @ac: argument counter
 * @av: array of argument strings
 * Return: 0 on success, EXIT_FAILURE on bad inputs
 */
int main(int ac, char *av[])
{
	size_t line = 1, nchars = 0;
	char *buf = NULL;
	const char delim = ' ';
	FILE *monty;
	stack_t *stack = NULL;
	void (*f)(stack_t **stack, unsigned int line_number, char *next);

	/* buf = NULL; */
	/*Check for correct usage.*/
	if (ac != 2)
		fprintf(stderr, "Usage: %s file\n", av[0]), exit(EXIT_FAILURE);
	/*Check whether the file exists and is readable.*/
	if (access(av[1], F_OK | R_OK))
		fprintf(stderr, "Error: Can't open file: %s\n", av[1]), exit(EXIT_FAILURE);

	monty = fopen(av[1], "r");

	while (getline(&buf, &nchars, monty) != EOF && line++)
	{
		squeeze_spaces(buf); /*Sanitize the input*/
		if (*buf)
		{ /*pall*/
			f = get_spec(strtok(buf, &delim)); /* pall */
			if (f)
				f(&stack, line, strtok(NULL, &delim));
			printf("Line: %lu: %s, Value: X\n", line, buf);
		}
	}
	free(buf);
	fclose(monty);
	return (0);
}


/**
 * squeeze_spaces - squeeze spaces
 * @str_d: string to clean
 * @slen: string length after clenaing
 */
void squeeze_spaces(char *str_d)
{
	int i = 0, c = 0;

	for (; str_d[i]; i++)
	{
		if (str_d[i] == '\n' || str_d[i] == '\t')
			str_d[i] = ' ';
	}

	for (i--; i >= 0; i--)
	{
		if (str_d[i] == 32 && (i == 0 || str_d[i - 1] == 32 || !str_d[i + 1]))
		{
			for (c = i; str_d[c]; c++)
				str_d[c] = str_d[c + 1];
		}
	}
}


/**
 * get_spec - printf helper that uses an input char to determine return
 * @s: char input to match valid printf specifier
 * Return: pointer to desired function
 */


void (*get_spec(char *s))(stack_t **stack, unsigned int line_num, char *next)
{
	instruction_t specs[] = {
		{"push", push},
		{"pall", pall},
		/* {"pint", pint}, */
		/* {"pop", pop}, */
		/* {"swap", swap}, */
		/* {"add", add}, */
		/* {"nop", nop}, */
		{NULL, NULL}
	};
	unsigned int i = 0;

	while (specs[i].opcode != NULL && strcmp(s, specs[i].opcode) != 0)
		i++;

	return (specs[i].f);
}

void push(stack_t **stack, unsigned int line_number, char *next)
{
	stack_t *temp;
	stack_t *newNode = malloc(sizeof(*newNode));

	(void) line_number;
	printf("You asked me to Push something!\n");
	if (!newNode)
		return;

	newNode->n = (*next - 48);
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
#define NOT __attribute__
#define USED ((unused))
void pall(stack_t **stack, unsigned int line_number, NOT USED char *next)
{
	stack_t *temp = *stack;

	(void) next;
	printf("L: %u, You asked me to print them all!\n", line_number);
	if (temp)
	{
	while (temp->next)
		temp = temp->next;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
	}
}
