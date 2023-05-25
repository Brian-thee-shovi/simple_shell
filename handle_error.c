#include "MY_shell.h"
/**
 * error_message - prints error depending
 * on the error num in this code
 * @args: given command to execute in this code
 * Return: returns nil
*/
void error_message(char **args)
{
	int len = 1;
	char *terminal = "";
	char *error_message = malloc(sizeof(char) * 255);
	char *ask = NULL;

	ask = int_charac_ter(len);
	error_message = dup_string(terminal);
	error_message = str_str(error_message, ": ");
	error_message = str_str(error_message, ask);
	error_message = str_str(error_message, ": ");
	error_message = str_str(error_message, args[0]);
	perror(error_message);
	free(error_message);
}

/**
 * error_notgood - prints error depending on the error
 * num in this code
 * @args: command to execute in this code
 * @buffer: given command to execute in this code
 * Return: returns nothing
*/
void error_notgood(char **args, char *buffer)
{
	write(STDOUT_FILENO, "command not found\n", 18);
	free_freely(1, buffer);
	buffer = NULL;
	free_freely(2, args);
	args = NULL;
}
