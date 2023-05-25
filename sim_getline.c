#include "MY_shell.h"
/**
 *sim_getline - it EXEcutes command lines entered by PIPE
 * @buffer: program NAME
 * @len: length buffer IN this code
 * @args: Argument 1
 * @env_args: Env arg in this code
 * Return: 0
*/
void sim_getline(char *buffer, int len, char **args, char **env_args)
{
	if (len == EOF)
	{
		printf("salida EOF\n");
		write(STDOUT_FILENO, "\n", 1);
		if (buffer != NULL)
		{
			free_freely(1, buffer);
			buffer = NULL;
		}
		if (args != NULL)
		{
			free_freely(2, args);
			args = NULL;
		}
		if (env_args != NULL)
		{
			free_freely(2, env_args);
			env_args = NULL;
		}
		exit(0);
	}
}
