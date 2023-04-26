#include "shell.h"

/**
 * copy_string - copies a string
 * @destination: the destination string to be copied to
 * @source: the source string
 * @num: the amount of characters to be copied
 * Return: the concatenated string
 */
char *copy_string(char *destination, char *source, int num)
{
	int k, l;
	char *str = destination;

	for (k = 0; k < num - 1 && source[k] != '\0'; k++)
		destination[k] = source[k];

	if (k < num)
	{
		l = k;
		while (l < num)
			destination[l++] = '\0';
	}
	return (str);
}

/**
 * concatenate_string - concatenates two strings
 * @destination: the first string
 * @source: the second string
 * @num: the amount of bytes to be maximally used
 * Return: the concatenated string
 */
char *concatenate_string(char *destination, char *source, int num)
{
	int k, l;
	char *str = destination;

	for (k = 0; destination[k] != '\0'; k++)
		;

	for (l = 0; l < num && source[l] != '\0'; l++)
		destination[k + l] = source[l];

	destination[k + l] = '\0';
	return (str);
}

/**
 * find_char - locates a character in a string
 * @str: the string to be parsed
 * @ch: the character to look for
 * Return: (str) a pointer to the memory area str
 */
char *find_char(char *str, char ch)
{
    int i = 0;
	do {
		if (*str == ch)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
