#include "MY_shell.h"
/**
 * error_message - writes error depending on the error number
 * @args: given command to execute
 * Return: Nothing
*/
void error_message(char **args)
{
	int loop = 1;
	char *hsh_home = "";
	char *error_message = malloc(sizeof(char) * 255);
	char *looper = NULL;

	looper = int_charac_ter(loop);
	error_message = dup_string(hsh_home);
	error_message = str_str(error_message, ": ");
	error_message = str_str(error_message, looper);
	error_message = str_str(error_message, ": ");
	error_message = str_str(error_message, args[0]);
	perror(error_message);
	free(error_message);
}

/**
 * error_notgood - writes error depending on the error number
 * @args: given command to execute
 * @buffer: given command to execute
 * Return: Nothing
*/
void error_notgood(char **args, char *buffer)
{
	write(STDOUT_FILENO, "command not found\n", 18);
	free_freely(1, buffer);
	buffer = NULL;
	free_freely(2, args);
	args = NULL;
}
