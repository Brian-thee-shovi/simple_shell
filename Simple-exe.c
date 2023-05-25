#include "MY_shell.h"

/**
 * execute_exe - It executes a given command
 * @command: It is a given command
 * @args: it is a command arguments
 * Return: It exits = 0 or the error Number
*/
int execute_exe(char *command, char **args)
{
	int stat;
	pid_t pidin;
	int errorcode = 0;

	pidin = fork();
	if (!pidin)
	{
		if (execve(command, args, environ) == -1)
		{
			free_freely(1, command);
			command = NULL;
			errorcode = errno;
			error_message(args);
			exit(errorcode);
		}
		else
		{
			free_freely(1, command);
			command = NULL;
			exit(errorcode);
		}
	}
	else
		wait(&stat);

	free_freely(1, command);
	command = NULL;
	errorcode = 0;
	return (errorcode);
}
