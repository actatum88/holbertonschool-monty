#include "monty.h"
#include <fcntl.h>
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
	FILE *monty;

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
		printf("Line: %lu: %s\n", line, buf);
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
		if (str_d[i] == 32 && (i == 0 || str_d[i - 1] == 32 || str_d[i + 1] == 0))
		{
			for (c = i; str_d[c]; c++)
				str_d[c] = str_d[c + 1];
		}
	}
}
