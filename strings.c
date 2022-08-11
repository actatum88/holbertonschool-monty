#include "monty.h"
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
