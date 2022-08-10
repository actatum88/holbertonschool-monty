#include "monty.h"
#include <fcntl.h>
/**
 * main - implement the push and pall opcodes.
 * @ac: argument counter
 * @av: array of argument strings
 *
 * Return: success exit with failure
 */

int main(int ac, char *av[])
{
	int line = 1;
	char *buf = NULL;
	FILE *monty;
	size_t nchars = 0;
	char *wrongargs = "Usage: monty file";
	char *cannotopenfile = "Error: Can't open file";
	char *unknowninstruction = "L : Unknown instruction";
	(void) cannotopenfile;
	(void) av;
	(void) unknowninstruction;

	if (ac != 2)
/*Check for correct usage.*/
	{
		if (write(2, wrongargs, 17) != -1)
			exit(EXIT_FAILURE);
	}
	if (access(av[1], F_OK | R_OK))
/*Check whether the file exists and is readable.*/
	{
		if (write(2, cannotopenfile, 22) != -1)
			exit(EXIT_FAILURE);
	}
	monty = fopen(av[1], "r");
	while (getline(&buf, &nchars, monty) != EOF && line++)
	{
		if (*buf != '\n')
			printf("Line: %d: %s", line, buf);
	}
	return (0);
}
