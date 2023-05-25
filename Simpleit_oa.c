#include "MY_shell.h"
/**
 * l_number - LENgth of number in this code
 * @n: intiger
 * Return: length,
 */
int l_number(int n)
{
	int height = 0;

	while (n / 10 != 0)
	{
		height++;
		n /= 10;
	}
	return (height);
}

/**
 * int_charac_ter - this func convert to str in my code
 * @num: int to be printed out
 * Return: a String
 */

char *int_charac_ter(int num)
{
	int in = 0;
	int gin = 0;
	char *string;
	int divisor = 1000000000;
	int tric = l_number(num);

	string = malloc(tric * sizeof(char) + 1);
	if (!string)
		return (NULL);

	if (num < 10)
	{
		string[gin++] = num + '0';
		string[gin] = '\0';
		return (string);
	}

	while (divisor)
	{
		in = (num / divisor) % 10;
		if (in != 0 || (tric >= 0 && string[gin - 1] >= '0'))
		{
			string[gin] = in + '0';
			gin++;
			tric--;
		}
		divisor /= 10;
	}
	string[gin] = '\0';
	return (string);
}
