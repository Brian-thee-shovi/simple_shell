#include <stdio.h>

/**
 * com_pare - compares two strings at a given position
 * @x: string to be compared
 * @y: string to compare
 * Return: Nohing
*/
int com_pare(char *x, char *y)
{
	while (*x && *y)
	{
		if (*x != *y)
			return (0);

		x++;
		y++;
	}

	return (*y == '\0');
}

/**
 * string_str - compares two strings at a given position
 * @x: string to be compared
 * @y: string to compare
 * Return: pointer to the first occurence
*/
char *string_str(char *x, char *y)
{
	while (*x != '\0')
	{
		if ((*x == *y) && com_pare(x, y))
			return (x);
		x++;
	}

	return (NULL);
}


/**
 * string_copy - unction that copies the string pointed to by src
 *@dest: char
 *@src:_ char
 * Return: dest
 */
char *string_copy(char *dest, char *src)
{
	int i = 0, j;

	while (src[i] != '\0')
	{
		i++;
	}
	for (j = 0; j <= i; j++)
	{
		dest[j] = src[j];
	}
	return (dest);
}
