#include "MY_shell.h"

/**
 * entered_nty - It executes the command lines entered by pipe
 * @av: program The programs name
 * Return: 0
 * author:Brian and joy
*/
int entered_nty(char **av __attribute__((unused)))
{
	size_t bufsizes;
	int length = 0;
	char *b = NULL;
	char **args = NULL;
	char **user_ = NULL;
	char *full_c = NULL;
	int (*b_func)() = NULL;

	while ((length = getline(&b, &bufsizes, stdin)) > 0)
	{
		sim_getline(b, length, user_, args);
		if (b[0] == 10 || b[0] == 9)
			continue;
		user_ = args_arguments(b);
		if (user_ == NULL)
			continue;
		b_func = handle_builtin(*user_);
		if (b_func)
		{
			if (b_func == exiting_function)
				free_all(user_, args, b, NULL);
			b_func();
			free_all(user_, NULL, NULL, NULL);
			continue;
		}
		args = getenvpath();
		if (args == NULL)
			return (-1);
		full_c = _insert_path(user_, args);
		if (full_c == NULL)
			write(STDOUT_FILENO, "command NOT found\n", 18);
		else
			execute_exe(full_c, user_);
		free_freely(1, b), b = NULL;
		free_freely(2, user_), user_ = NULL;
		free_freely(2, args), args  = NULL;
	}
	free_freely(1, b), b = NULL;
	return (0);
}
