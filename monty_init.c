#include "monty.h"
FILE *monty_init(int ac, char *av[])
{
	FILE *temp = NULL;

/*Check for correct usage.*/
	if (ac != 2)
		fprintf(stderr, "USAGE: %s file\n", av[0]), exit(EXIT_FAILURE);
	/*Check whether the file exists and is readable.*/
	if (access(av[1], F_OK | R_OK))
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
			exit(EXIT_FAILURE);
	}
	/*If you argued correctly, the file is opened*/
	data.script = temp = fopen(av[1], "r");

	return (monty);
}
