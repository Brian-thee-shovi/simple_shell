#include "MY_shell.h"

/**
 * find_paths - Finds the PATH variable from enviroment
 * Return: pointer position of the PATH variable
*/

char *find_paths()
{
	char *path = NULL;
	int i = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (comp_str(environ[i], "PATH") == 0)
		{
			path = malloc(sizeof(char *) * (length_string(environ[i])));
			if (path == NULL)
			{
				free_freely(1, path);
				exit(-1);
			}
			string_copy(path, environ[i]);
			break;
		}
	}
	return (path);
}

/**
 * changes_to_char - Change from a given strings = to : character
 * @str: given string
 * Return: Nohing
*/

void changes_to_char(char *str)
{
	char **ptr_str = NULL;
	int i = 0;

	ptr_str = &str;

	while ((*(*ptr_str + i)) != '=')
	{
		(*(*ptr_str + i)) = ':';
		i++;
	}
	(*(*ptr_str + i)) = ':';
}

/**
 * _insert_path - Inserts the directory into given command
 * @args: given command
 * @path: tokenized path enviroment
 * Return: Full path command if exists or just a given command
*/

char *_insert_path(char **args, char **path)
{
	char *cwd = getcwd(NULL, 0);
	struct stat verify;
	int counter = 0;
	int count_char = 0;
	char *tmp2 = NULL;
	char *dirpath = NULL;

	if (string_str(args[0], "/") || string_str(args[0], "."))
	{
		free_freely(1, cwd);
		cwd = NULL;
		tmp2 = malloc(sizeof(char *) * (length_string(args[0])));
		string_copy(tmp2, args[0]);
		return (tmp2);
	}
	else
	{
		while (path[counter] != NULL)
		{
			chdir(path[counter]);
			if (stat(args[0], &verify) == 0)
			{
				count_char = length_string(path[counter]) + 1 + length_string(args[0]);
				tmp2 = malloc(sizeof(char *) * count_char);
				string_copy(tmp2, path[counter]);
				str_str(tmp2, "/"), str_str(tmp2, args[0]);
				break;
			}
			counter++;
		}
	}
	chdir(cwd);
	if (tmp2 == NULL)
	{
		free_freely(1, cwd), cwd = NULL;
		free_freely(1, tmp2), tmp2 = NULL;
		return (dirpath);
	}
	dirpath = tmp2, free_freely(1, cwd), cwd = NULL;
	return (dirpath);
}

/**
 * getenvpath - Creates an array of pointers to the PATH directories
 * Return: Pointer to an array of tokenized directories
*/

char **getenvpath()
{
	char *tmp = NULL;
	int size_args = 0;
	char **env_args;

	tmp = find_paths();
	changes_to_char(tmp); /*Change  PATH= for PATH:*/
	size_args = pearl_used(tmp);
	env_args = pars_given(tmp, size_args);
	free_freely(1, tmp);
	tmp =  NULL;
	return (env_args);
}

/**
 * buff_bust - Creates an array of pointers to the PATH directories
 * @buffer: given string
 * Return: Pointer to an array of tokenized directories
*/

int buff_bust(char *buffer)
{
	int i = 0;

	while (buffer[i] != '\0')
	{
		if (buffer[i] != 32)
		{
			return (0);
		}
	i++;
	}
	return (1);
}
