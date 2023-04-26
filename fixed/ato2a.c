#include "shell.h"

/**
 * interactive - checks if the shell is running interactively
 * @info: pointer to struct containing information about the shell
 * Return: 1 if running interactively, 0 otherwise
 */
int interactive(info_t *info)
{
	if (isatty(STDIN_FILENO) && info->readfd <= 2)
		return (1);
	else
		return (0);
}

/**
 * is_delim - checks if a character is a delimiter
 * @c: character to check
 * @delim: string of delimiters
 * Return: 1 if c is a delimiter, 0 otherwise
 */
int is_delim(char c, char *delim)
{
	while (*delim)
	{
		if (*delim == c)
			return (1);
		delim++;
	}
	return (0);
}

/**
 * _isalpha - checks if a character is alphabetic
 * @c: character to check
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int _isalpha(int c)
{
	switch (c)
	{
		case 'a'...'z':
		case 'A'...'Z':
			return (1);
		default:
			return (0);
	}
}

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 * Return: converted integer value of s
 */
int _atoi(char *a)
{
	int i, sign = 1, flag = 0;
    unsigned int result = 0;
    int output;

    for (i = 0; a[i] != '\0' && flag != 2; i++)
    {
        switch (a[i])
        {
            case '-':
                sign *= -1;
                break;
            default:
                if (a[i] >= '0' && a[i] <= '9')
                {
                    flag = 1;
                    result *= 10;
                    result += (a[i] - '0');
                }
                else
				{
					switch (flag)
					{
						case 1:
						flag = 2;
						break;
						default:
						break;
					}
				}
		}
	}
    if (sign == -1)
        output = -result;
    else
        output = result;
    return (output);
}