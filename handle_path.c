#include "MY_shell.h"

/**
 * find_paths - it finds the path variable from env in this code
 * Return: Its the pointer position of path var
*/

char *find_paths()
{
	char *var = NULL;
	int m = 0;

	for (m = 0; environ[m] != NULL; m++)
	{
		if (comp_str(environ[m], "PATH") == 0)
		{
			var = malloc(sizeof(char *) * (length_string(environ[m])));
			if (var == NULL)
			{
				free_freely(1, var);
				exit(-1);
			}
		string_copy(var, environ[m]);
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
	int l = 0;

	_string = &str;

	while ((*(*_string + l)) != '=')
	{
		(*(*_string + l)) = ':';
		l++;
	}
	(*(*_string + l)) = ':';
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
	char *u = NULL;
	int max = 0;
	char **me;

	u = find_paths();
	changes_to_char(u); /*Change  PATH= for PATH:*/
	max = pearl_used(u);
	me = pars_given(u, max);
	free_freely(1, u);
	u =  NULL;
	return (me);
}

/**
 * buff_bust - creates an arr of pointers to the path dir
 * @buffer: given string in this code
 * Return: its a pointer to an arr of tokenized dir
*/

int buff_bust(char *buffer)
{
	int l = 0;

	while (buffer[l] != '\0')
	{
		if (buffer[l] != 32)
		{
			return (0);
		}
	l++;
	}
	return (1);
}
