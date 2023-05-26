#include "MY_shell.h"
/**
 * main - Entry point of Shell in my code
 * @ac: Argument counter in my code
 * @av: Argument values in my code
 * Return: Exit if success = 0
*/

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{

	int mo_me = 1;
	int code = 0;


	code = code + 0;

	mo_me = isatty(STDIN_FILENO);
	if (mo_me == 0)
	{
		entered_nty(av);
	}
	else
	{

		inter_collabo(av);
	}
	return (0);
}
