#include "MY_shell.h"
/**
 * execute_exe - Executes a given command
 * @command: Given command
 * @args: command arguments
 * Return: Exit = 0 or Error Number
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
