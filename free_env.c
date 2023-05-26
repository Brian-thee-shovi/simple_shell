#include "MY_shell.h"

/**
* free_env -It frees the tokenized path dir and user's arguments
* @env_args: tokenized env dir
* @args: tokenized user's cmds
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
