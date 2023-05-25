#include "MY_shell.h"

/**
 * envy_function - It prints an eviroment variables
 * Return: on success 0
*/
int envy_function(void)
{
	int count = 0, leng = 0;

	while (environ[count] != NULL)
	{
		leng = length_string(environ[count]);
		write(STDOUT_FILENO, environ[count], leng);
		write(STDOUT_FILENO, "\n", 1);
		count++;
	}
	return (0);
}
