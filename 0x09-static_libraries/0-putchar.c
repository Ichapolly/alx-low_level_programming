#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: the character
 *
 *Return: returns 1 on successful execution
 */
int_putchar(char c)
{
	return (write(1, &c, 1));
}
