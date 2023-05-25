#include "MY_shell.h"

/**
 * pearl_used - It counts the commands and options entered by user
 * @buffer:  command given
 * Return: Number of the arguments
*/
int pearl_used(char *buffer)
{
	int pearlins = 0;
	char *delim = " =:'\n''\t'";
	int d = 0;
	int f = 0;

	while (buffer[d] != '\0')
	{
		for (f = 0; delim[f] != '\0'; f++)
		{
			if (buffer[d] == delim[f])
			{
				pearlins++;
				break;
			}
		}
		d++;
	}
	return (pearlins + 1);
}

/**
 * pars_given - Funct that splits a given string
 * @buffer: string given
 * @characters: number of the elements
 * Return: Tokenized string
*/

char **pars_given(char *buffer, int characters)
{
	int count = 0;
	char *tokenz = NULL;
	char *delim = " :'\n''\t'";
	char **tokenz_necklace = malloc(sizeof(char *) * characters);

	if (tokenz_necklace == NULL)
	{
		return (NULL);
	}
	tokenz = strtok(buffer, delim);
	while (tokenz != NULL)
	{
		tokenz_necklace[count] = dup_string(tokenz);
		if (tokenz_necklace[count] == NULL)
		{
			free_freely(2, tokenz_necklace);
			return (NULL);
		}
		tokenz = strtok(NULL, delim);
		count++;
	}
	tokenz_necklace[count] = NULL;
	return (tokenz_necklace);
}
