#include "monty.h"

/**
 * dsh_read_line - reads line
 * @buf: buffer storing monty line
 */

void dsh_read_line(char **buf)
{
	char *newbuf = NULL;
	size_t bufsize = 256, pos = 0;
	int c = 0;
	/*unsigned int i;*/

	if (*buf)
		free(*buf);

	newbuf = malloc(bufsize * sizeof(char));

	if (!newbuf)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	*buf = newbuf;

	while ((c = getc(data.script)) != EOF)
	{
		if (c == '\n')
		{
			(*buf)[pos] = '\0';
			break;
		}
		(*buf)[pos++] = c;
	}

	if (c == -1)
	{
		free(*buf);
		*buf = NULL;
	}
}
