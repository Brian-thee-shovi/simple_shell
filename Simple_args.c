#include "MY_shell.h"
/**
 * args_arguments - executes command lines entered by pipe
 * @buffer: command name
 * Return: 0
*/
char **args_arguments(char *buffer)
{
	int size = 0;
	char **user_command = NULL;

	size = pearl_used(buffer);
	user_command = pars_given(buffer, size);
	if (user_command == NULL)
	{
		free_freely(2, user_command);
		user_command = NULL;
	}

	return (user_command);
}
