#include "monty.h"
/* FILE *monty = NULL; */
/**
 * main - implement the push and pall opcodes.
 * @ac: argument counter
 * @av: array of argument strings
 * Return: 0 on success, EXIT_FAILURE on bad inputs
 */
int main(int ac, char *av[])
{
	stack_t *stack = NULL, *temp = NULL;
	char *buf = NULL;

	monty_init(ac, av);

	exec_script(buf, stack);

	fclose(monty); /*Close the file when you don't need it, start freeing*/

	if (buf)
		free(buf);
	if (stack)
	{
		for (temp = stack; temp; free(stack), stack = temp)
			temp = temp->next;
		free(stack);
	}
	return (0);
}
