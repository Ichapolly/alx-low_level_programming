#include "main.h"

/**
 * _strdup - Duplicates a string in the heap memory.
 * @s: Input string.
 * Return: Duplicated string.
 */
char *_strdup(const char *s)
{
	char *new;
	size_t len;

	len = _strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, s, len + 1);
	return (new);
}

/**
 * _strlen - Returns the length of a string.
 * @s: Input string.
 * Return: Length of the string.
 */
int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * cmp_chars - Compares characters of strings with a delimiter.
 * @str: Input string.
 * @delim: Delimiter.
 * Return: 1 if characters are equal, 0 if not.
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * _strtok - Splits a string by a delimiter.
 * @str: Input string.
 * @delim: Delimiter.
 * Return: The next token in the string.
 */
char *_strtok(char str[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		splitted = str; /* Store the first address */
		i = _strlen(str);
		str_end = &str[i]; /* Store the last address */
	}
	str_start = splitted;
	if (str_start == str_end) /* Reaching the end */
		return (NULL);

	for (bool = 0; *splitted; splitted++)
	{
		/* Breaking the loop when finding the next token */
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		/* Replacing the delimiter for a null character */
		for (i = 0; delim[i]; i++)
		{
			if (*splitted == delim[i])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted) /* String is not equal to the delimiter */
			bool = 1;
	}
	if (bool == 0) /* String is equal to the delimiter */
		return (NULL);
	return (str_start);
}

/**
 * _isdigit - Defines if a string passed is a number.
 * @s: Input string.
 * Return: 1 if the string is a number, 0 in other case.
 */
int _isdigit(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}
