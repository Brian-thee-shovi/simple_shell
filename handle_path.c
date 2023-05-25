#include "MY_shell.h"

/**
 * find_paths - it finds the path variable from env in this code
 * Return: Its the pointer position of path var
*/

char *find_paths()
{
	char *var = NULL;
	int j = 0;

	for (j = 0; environ[j] != NULL; j++)
	{
		if (comp_str(environ[j], "PATH") == 0)
		{
			var = malloc(sizeof(char *) * (length_string(environ[j])));
			if (var == NULL)
			{
				free_freely(1, var);
				exit(-1);
			}
			string_copy(var, environ[j]);
			break;
		}
	}
	return (var);
}

/**
 * changes_to_char - It changes a given strings = to : char
 * @str: given string in this code
 * Return:returns nothing
*/

void changes_to_char(char *str)
{
	char **_string = NULL;
	int k = 0;

	_string = &str;

	while ((*(*_string + k)) != '=')
	{
		(*(*_string + k)) = ':';
		k++;
	}
	(*(*_string + k)) = ':';
}

/**
 * _insert_path - IT Inserts the dir into  command in this code
 * @args: given command in this code
 * @path: tokenized path env in my code
 * Return: a full Path cmd if exists or just a given cmd
*/

char *_insert_path(char **args, char **path)
{
	char *yip = getcwd(NULL, 0);
	struct stat verify;
	int cant = 0;
	int t_char = 0;
	char *ret = NULL;
	char *pat_h = NULL;

	if (string_str(args[0], "/") || string_str(args[0], "."))
	{
		free_freely(1, yip);
		yip = NULL;
		ret = malloc(sizeof(char *) * (length_string(args[0])));
		string_copy(ret, args[0]);
		return (ret);
	}
	else
	{
		while (path[cant] != NULL)
		{
			chdir(path[cant]);
			if (stat(args[0], &verify) == 0)
			{
				t_char = length_string(path[cant]) + 1 + length_string(args[0]);
				ret = malloc(sizeof(char *) * t_char);
				string_copy(ret, path[cant]);
				str_str(ret, "/"), str_str(ret, args[0]);
				break;
			}
			cant++;
		}
	}
	chdir(yip);
	if (ret == NULL)
	{
		free_freely(1, yip), yip = NULL;
		free_freely(1, ret), ret = NULL;
		return (pat_h);
	}
	pat_h = ret, free_freely(1, yip), yip = NULL;
	return (pat_h);
}

/**
 * getenvpath - It creates an arr of pointers to pathof dir
 * Return: its aPointer to an arr of tokenized dir
*/

char **getenvpath()
{
	char *t = NULL;
	int max = 0;
	char **me;

	t = find_paths();
	changes_to_char(t); /*Change  PATH= for PATH:*/
	max = pearl_used(t);
	me = pars_given(t, max);
	free_freely(1, t);
	t =  NULL;
	return (me);
}

/**
 * buff_bust - creates an arr of pointers to the path dir
 * @buffer: given string in this code
 * Return: its a pointer to an arr of tokenized dir
*/

int buff_bust(char *buffer)
{
	int k = 0;

	while (buffer[k] != '\0')
	{
		if (buffer[k] != 32)
		{
			return (0);
		}
	k++;
	}
	return (1);
}
