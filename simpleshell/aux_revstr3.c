#include "main.h"

/**
 * rev_string - Reverses a string.
 * @s: Input string.
 * Return: No return.
 */
void rev_string(char *s)
{
	int count = 0, i, j;
	char *str, temp;

	/* Calculate the length of the string */
	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	str = s;

	/* Reverse the characters in the string */
	for (i = 0; i < (count - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			/* Swap characters in the string */
			temp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = temp;
		}
	}
}
