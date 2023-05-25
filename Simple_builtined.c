#include "MY_shell.h"
/**
**handle_builtin -  finds wheter user's command is a builtin
** @user_input: user's command
**Return: pointer to function builtin or NULL if doesn't exists
**/
int (*handle_builtin(char *user_input))()
{
	int counter = 0, stru_size = 0;

	builtin_struct my_builtins[] = {
		{"exit", exiting_function},
		{"env", envy_function},
	};

	stru_size = (sizeof(my_builtins) / sizeof(builtin_struct));
	if (user_input != NULL)
	{
		while (counter < stru_size)
		{
			if (comp_str(my_builtins[counter].b_name, user_input) == 0)
				return (my_builtins[counter].b_func);
			counter++;
		}
	}
	return (NULL);
}
