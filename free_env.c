#include "MY_shell.h"

/**
* free_env -It frees the tokenized PATH directories and user's arguments
* @env_args: tokenized environmental directories
* @args: tokenized user's commands
* Return: nothing
*/

void free_env(char **env_args, char **args)
{
	if (env_args != NULL)
	{
		free_freely(2, env_args);
	}
	free_freely(2, args);
}
