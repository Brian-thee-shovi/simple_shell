#include "MY_shell.h"
/**
 * envy_function - Prints eviroment variables
 * Return: 0 on success
*/
int envy_function(void)
{
	int counter = 0, lenght = 0;

	while (environ[counter] != NULL)
	{
		lenght = length_string(environ[counter]);
		write(STDOUT_FILENO, environ[counter], lenght);
		write(STDOUT_FILENO, "\n", 1);
		counter++;
	}
	return (0);
}
