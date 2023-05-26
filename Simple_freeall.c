#include "MY_shell.h"
/**
* free_freely - free the memory
* @n: args
* Return: null
*/

void free_freely(int n, ...)
{
	int k = 0;
	char **p = NULL;
	char *t = NULL;
	va_list arg;

	va_start(arg, n);

	if (n == 1)
	{
		t = va_arg(arg, char *);
		free(t);
	}

	if (n == 2)
	{
		p = va_arg(arg, char **);
		while (p[k] != NULL)
		{
			free(p[k]);
			k++;
		}
		free(p);
	}
}

/**
* free_all - IT frees tokenized PATH directories and user's
* arguments
* @dptr1: first double pointER
* @dptr2: second double poinTER
* @sptr1: first single pointER
* @sptr2: second double pointER
* Return: nothing
*/

void free_all(char **dptr1, char **dptr2, char *sptr1, char *sptr2)
{

	if (dptr1 != NULL)
	{
		free_freely(2, dptr1);
		dptr1 = NULL;
	}
	if (dptr2 != NULL)
	{
		free_freely(2, dptr2);
		dptr2 = NULL;
	}
	if (sptr1 != NULL)
	{
		free(sptr1);
		sptr1 = NULL;
	}
	if (sptr2 != NULL)
	{
		free(sptr2);
		sptr2 = NULL;
	}
}
