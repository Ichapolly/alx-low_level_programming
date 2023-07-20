#include <stdio.h>
#ifndef STRNCAT
#define _strncat

char *strncat(char *, char *, int);

/**
 * main -concatenates two strings
 * Return: Always 0.
 */
int main(void)
{
	char s1[98] = "Holberton ";
	char s2[] = "School!\n";
	char p ;

	printf("%s\n", s1);
	printf("%s", s2);
	char *p = _strncat(s1, s2, 5);
	printf("%s\n", s1);
	printf("%s", s2);
	printf("%s\n", p);
	return (0);
	#endif
}
