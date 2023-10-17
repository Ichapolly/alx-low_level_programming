#include "main.h"

/**
 * cmp_env_name - Compares environment variable names with the name passed.
 *
 * @nenv: Name of the environment variable
 * @name: Name passed for comparison
 *
 * Return: 0 if the names are not equal, or another value if they are.
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * _getenv - Gets the value of an environment variable by name.
 *
 * @name: Name of the environment variable
 * @_environ: Environment variable array
 *
 * Return: The value of the environment variable if found, or NULL if not found.
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int i, mov;

	/* Initialize ptr_env value */
	ptr_env = NULL;
	mov = 0;
	/* Compare all environment variables */
	/* environ is declared in the header file */
	for (i = 0; _environ[i]; i++)
	{
		/* If name and environment variable name are equal */
		mov = cmp_env_name(_environ[i], name);
		if (mov)
		{
			ptr_env = _environ[i];
			break;
		}
	}

	return (ptr_env + mov); /* Return the value of the environment variable */
}

/**
 * _env - Prints the environment variables.
 *
 * @datash: Data relevant to the shell
 * Return: 1 on success.
 */
int _env(data_shell *datash)
{
	int i, j;

	for (i = 0; datash->_environ[i]; i++)
	{
		for (j = 0; datash->_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, datash->_environ[i], j); /* Write the environment variable to the standard output */
		write(STDOUT_FILENO, "\n", 1); /* Write a newline character */
	}
	datash->status = 0; /* Set the status to 0 (success) */

	return (1); /* Return success */
}
