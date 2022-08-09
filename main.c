#include "monty.h"

/**
 * main - implement the push and pall opcodes.
 * @ac: argument counter
 * @av: array of argument strings
 *
 * Return: success exit with failure
 */

int main(int ac, char *av[])
{

char *wrongargs = "Usage: monty file";
char *cannotopenfile = "Error: Can't open file";
char *unknowninstruction = "L : Unknown instruction";
(void) cannotopenfile;
(void) av;
(void) unknowninstruction;

if (ac != 2)
/*Check for correct usage.*/
{
	if(write (2,wrongargs,17) != -1)
		exit(EXIT_FAILURE);
}
if(access(av[1], F_OK | X_OK))
/*Check whether the calling process can access the file.*/
{
	if(write (2,cannotopenfile, 22) != -1)
		exit(EXIT_FAILURE);
}
return (0);
}
