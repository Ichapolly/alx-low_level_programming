#include "main.h"

/**
 * cd_shell - Changes the current directory.
 *
 * @datash: Data relevant
 * Return: 1 on success
 */
int cd_shell(data_shell *datash)
{
	char *dir;
	int ishome, ishome2, isddash;

	dir = datash->args[1];

	// Check if the directory argument is empty or special cases
	if (dir != NULL)
	{
		ishome = _strcmp("$HOME", dir);   // Check if the argument is "$HOME"
		ishome2 = _strcmp("~", dir);      // Check if the argument is "~"
		isddash = _strcmp("--", dir);     // Check if the argument is "--"
	}

	// If the argument is empty or one of the special cases, change to the home directory
	if (dir == NULL || !ishome || !ishome2 || !isddash)
	{
		cd_to_home(datash);
		return (1);
	}

	// If the argument is "-", change to the previous directory
	if (_strcmp("-", dir) == 0)
	{
		cd_previous(datash);
		return (1);
	}

	// If the argument is "." or "..", handle accordingly
	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		cd_dot(datash);
		return (1);
	}

	// Otherwise, change to the specified directory
	cd_to(datash);

	return (1);
}
