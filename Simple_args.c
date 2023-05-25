#include "MY_shell.h"
/**
 * args_arguments - this executes command lines entered by PIPE
 * @buffer: command name IN THIS CODE
 * Return: 0
*/
char **args_arguments(char *buffer)
{
	int kim = 0;
	char **man_d = NULL;

	size = pearl_used(buffer);
	man_d = pars_given(buffer, kim);
	if (mman_d == NULL)
	{
		free_freely(2, man_d);
		man_d = NULL;
	}

	return (man_d);
}
