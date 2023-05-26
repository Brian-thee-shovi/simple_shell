#include "MY_shell.h"

/**
 * size_comp - It compares 2 strings with n sizes in this code
 * @s1: Given String 1 in this code
 * @s2: Given String two in this code
 * @n: Size to character compare
 * Return: 0 both strings are equals
*/
int size_comp(char *s1,  char *s2, size_t n)
{
	while (n && *s1 && (*s1 == *s2))
	{
		++s1;
		++s2;
		--n;
	}
	if (n == 0)
	{
		return (0);
	}
	else
	{
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
	}
}

/**
 * length_string - The func that returns length of a given string
 * @s: string given
 * Return: number of elements in this code
*/
int length_string(char *s)
{
	int l;

	for (l = 0; s[l] != '\0'; l++)
		;
	return (l);
}

/**
 * dup_string - it duplicates a string
 * @s: given string in this code
 * Return: Copy of given string
*/
char *dup_string(char *s)
{
	char *ter;
	int e, leng;

	leng = 0;
	if (s == NULL)
		return (NULL);
	leng = length_string(s);
	ter = malloc(sizeof(char) * (leng + 1));
	if (ter == NULL)
		return (NULL);
	for (e = 0; e < leng; e++)
		ter[e] = s[e];
	ter[e] = '\0';
	return (ter);
}

/**
 * comp_str - it compares 2 given  strings
 * @s1: String 1
 * @s2: String 2
 * Return: 0 if both are equals or ascii diff
*/
int comp_str(char *s1, char *s2)
{
	int fer, indexin;

	fer = indexin = 0;
	if (s1 == NULL || s2 == NULL)
		return (-1);
	while (s1[indexin] != '\0' && s2[indexin] != '\0')
	{
		fer = s1[indexin] - s2[indexin];
		if (fer != 0)
			break;
		indexin++;
	}
	return (fer);
}

/**
 *str_str - concentrates two strings.
 *@dest: destiny string in this code
 *@src: source string in this code
 *Return: dest
 */
char *str_str(char *dest, char *src)
{
	int p, a;

	for (p = 0; dest[p] != '\0'; p++)
	{
	}
	for (a = 0; src[a] != '\0'; a++)
	{
		dest[p + a] = src[a];
	}
	dest[p + a] = '\0';

	return (dest);
}
