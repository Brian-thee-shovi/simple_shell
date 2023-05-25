#include "MY_shell.h"

/**
**handle_builtin -  It finds whether the user's command is a builtin
** @user_input: it is the user's command
**Return: ptr to funct builtin or NULL if doesn't exists
**/
int (*handle_builtin(char *user_input))()
{
	int count = 0, struct_size = 0;

	builtin_struct my_builtins[] = {
		{"exit", exiting_function},
		{"env", envy_function},
	};

	struct_size = (sizeof(my_builtins) / sizeof(builtin_struct));
	if (user_input != NULL)
	{
		while (count < struct_size)
		{
			if (comp_str(my_builtins[count].b_name, user_input) == 0)
				return (my_builtins[count].b_func);
			count++;
		}
	}
	return (NULL);
}
