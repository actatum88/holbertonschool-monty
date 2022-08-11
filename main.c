#include "monty.h"

/**
 * main - implement the push and pall opcodes.
 * @ac: argument counter
 * @av: array of argument strings
 * Return: 0 on success, EXIT_FAILURE on bad inputs
 */
int main(int ac, char *av[])
{
	stack_t *stack = NULL, *temp = NULL;

	monty_init(ac, av);

	exec_script(&stack);

	fclose(data.script); /*Close the file when you don't need it, start freeing*/


	if (stack)
	{
		for (temp = stack; temp; free(stack), stack = temp)
			temp = temp->next;
		free(stack);
	}
	return (0);
}
