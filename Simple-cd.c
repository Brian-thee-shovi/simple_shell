#include <stdio.h>

#include <stdlib.h>

#include <fcntl.h>

#include <unistd.h>

#include <errno.h>

#include "MY_shell.h"

/**

 * execute_cd - Function that executes the cd command.

 * @args: Command arguments.

 */

void execute_cd(char **args)

{

	char *new_dir = args[1];	char oldpwd[4096];

	int f;

	if (new_dir == NULL || _strcmp(new_dir, "~") == 0)

	{

		new_dir = getenv("HOME");

	}

	else if (_strcmp(new_dir, "-") == 0)

	{

		new_dir = getenv("OLDPWD");

		f = open("/dev/stderr", O_WRONLY);

		if (f != -1)

		{

			write(f, new_dir, _strlen(new_dir));

			write(f, "\n", 1);

			close(f);

		}

	}

	if (chdir(new_dir) == -1)

	{

		perror("cd");

		return;

	}

	if (getenv("PWD") != NULL)

	{

		strcpy(oldpwd, getenv("PWD"));

		if (setenv("OLDPWD", oldpwd, 1) == -1)

		{

			perror("setenv");

			return;

		}

	}

} 
