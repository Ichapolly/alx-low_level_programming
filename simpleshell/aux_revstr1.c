#include "main.h"

/**
 * _strcat - Concatenates two strings.
 * @dest: Destination string where the source string will be appended.
 * @src: Source string that will be appended to the destination.
 * Return: A pointer to the destination string.
 */
char *_strcat(char *dest, const char *src)
{
	int i;
	int j;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}

/**
 * _strcpy - Copies the string pointed to by src to dest.
 * @dest: Destination string where the source string will be copied.
 * @src: Source string that will be copied to the destination.
 * Return: A pointer to the destination string.
 */
char *_strcpy(char *dest, char *src)
{
	size_t a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';

	return (dest);
}

/**
 * _strcmp - Compares two strings.
 * @s1: First string to compare.
 * @s2: Second string to compare.
 * Return: 0 if the strings are equal, 1 if s1 > s2, -1 if s1 < s2.
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;

	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

/**
 * _strchr - Locates a character in a string.
 * @s: String in which to locate the character.
 * @c: Character to be located.
 * Return: A pointer to the first occurrence of the character c in the string s.
 */
char *_strchr(char *s, char c)
{
	unsigned int i = 0;

	for (; *(s + i) != '\0'; i++)
		if (*(s + i) == c)
			return (s + i);
	if (*(s + i) == c)
		return (s + i);
	return ('\0');
}

/**
 * _strspn - Gets the length of a prefix substring.
 * @s: Initial segment to be checked.
 * @accept: String containing the accepted characters.
 * Return: The number of characters in the initial segment of s that match any character in accept.
 */
int _strspn(char *s, char *accept)
{
	int i, j, bool;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		bool = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + i) == *(accept + j)
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (i);
}
