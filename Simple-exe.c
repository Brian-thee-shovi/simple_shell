#include "MY_shell.h"

/**
 * execute_exe - It executes a given command
 * @command: It is a given command
 * @args: it is a command arguments
 * Return: It exits = 0 or the error Number
*/
int execute_exe(char *command, char **args)
{
	int status;
	pid_t pid;
	int errcode = 0;

	pid = fork();
	if (!pid)
	{
		if (execve(command, args, environ) == -1)
		{
			free_freely(1, command);
			command = NULL;
			errcode = errno;
			error_message(args);
			exit(errcode);
		}
		else
		{
			free_freely(1, command);
			command = NULL;
			exit(errcode);
		}
	}
	else
		wait(&status);

	free_freely(1, command);
	command = NULL;
	errcode = 0;
	return (errcode);
}
