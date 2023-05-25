#include "MY_shell.h"
/**
 * inter_collabo - This creates a loop that execute c
 * ommand lines entered by tty in this code
 * @av: its arg from main in this code
 * Return: Exit / Error Code
*/
int inter_collabo(char **av __attribute__((unused)))
{
	size_t faster;
	char *pathing = NULL;
	char **env_ = NULL;
	char **man_d = NULL;
	char *kim = NULL;
	int (*func)() = NULL;

	while (1)
	{
		write(STDOUT_FILENO, "($) ", 4);
		getline(&pathing, &faster, stdin);
		sim_getline(pathing, 0, man_d, env_);
		if (pathing[0] == 10 || pathing[0] == 9)
			continue;
		man_d = args_arguments(pathing);
		if (man_d == NULL)
			continue;
		func = handle_builtin(*man_d);
		if (func)
		{
			if (func == exiting_function)
				free_all(man_d, env_, pathing, NULL);
			func();
			free_all(man_d, NULL, NULL, NULL);
			continue;
		}
		env_ = getenvpath();
		if (env_ == NULL)
			return (-1);
		kim = _insert_path(man_d, env_);
		if (kim == NULL)
			write(STDOUT_FILENO, "command NOT found\n", 18);
		else
			execute_exe(kim, man_d);
		free_freely(1, pathing), pathing = NULL;
		free_freely(2, man_d), man_d = NULL;
		free_freely(2, env_), env_ = NULL;
	}
	return (0);
}
