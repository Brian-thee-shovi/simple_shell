#include "MY_shell.h"

/**
 * entered_nty - It executes the command lines entered by pipe
 * @av: program The programs name
 * Return: 0
*/
int entered_nty(char **av __attribute__((unused)))
{
	size_t bufsizes;
	int length = 0;
	char *buffer = NULL;
	char **env_args = NULL;
	char **user_command = NULL;
	char *full_command = NULL;
	int (*c_func)() = NULL;

	while ((length = getline(&buffer, &bufsizes, stdin)) > 0)
	{
		sim_getline(buffer, length, user_command, env_args);
		if (buffer[0] == 10 || buffer[0] == 9)
			continue;
		user_command = args_arguments(buffer);
		if (user_command == NULL)
			continue;
		c_func = handle_builtin(*user_command);
		if (c_func)
		{
			if (c_func == exiting_function)
				free_all(user_command, env_args, buffer, NULL);
			c_func();
			free_all(user_command, NULL, NULL, NULL);
			continue;
		}
		env_args = getenvpath();
		if (env_args == NULL)
			return (-1);
		full_command = _insert_path(user_command, env_args);
		if (full_command == NULL)
			write(STDOUT_FILENO, "command NOT found\n", 18);
		else
			execute_exe(full_command, user_command);
		free_freely(1, buffer), buffer = NULL;
		free_freely(2, user_command), user_command = NULL;
		free_freely(2, env_args), env_args  = NULL;
	}
	free_freely(1, buffer), buffer = NULL;
	return (0);
}
