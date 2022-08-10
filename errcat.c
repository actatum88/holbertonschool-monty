#include "monty.h"

/**
 * errcat - writes sh-style error messages
 * @pname: argv[0] as invoked
 * @cname: user-provided input command
 * Return: sh-style error string
 */

char *errcat(char *pname, char *cname)
{
	int i, j;
	char *erract = malloc(256 * sizeof(char));
	char *errsuff = ": not found\n";
	char *errmid = ": 1: ";

	for (i = 0; pname[i]; i++)
		erract[i] = pname[i];
	for (j = 0; errmid[j]; j++)
		erract[i++] = errmid[j];
	for (j = 0; cname[j]; j++)
		erract[i++] = cname[j];
	for (j = 0; errsuff[j]; j++)
		erract[i++] = errsuff[j];
	erract[i] = '\0';

	return (erract);
}
