#include "monty.h"

/**
 * main - implement the push and pall opcodes.
 * @ac: argument counter
 * @av: array of argument strings
 * Return: 0 on success, EXIT_FAILURE on bad inputs
 */
int main(int ac, char *av[])
{
	stack_t *stack = NULL;

	monty_init(ac, av);

	exec_script(&stack);

	freestuff(&stack);

	return (0);
}
