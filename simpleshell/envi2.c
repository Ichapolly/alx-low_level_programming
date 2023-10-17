#include "main.h"

/**
 * copy_info - Creates a new environment variable or alias by combining name and value.
 *
 * @name: Name of the environment variable or alias
 * @value: Value of the environment variable or alias
 * Return: New environment variable or alias.
 */
char *copy_info(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = _strlen(name);
	len_value = _strlen(value);
	len = len_name + len_value + 2; /* Calculate the length of the new environment variable or alias */
	new = malloc(sizeof(char) * (len));
	_strcpy(new, name); /* Copy the name into the new variable */
	_strcat(new, "="); /* Add the equal sign */
	_strcat(new, value); /* Add the value */
	_strcat(new, "\0"); /* Null-terminate the string */

	return (new); /* Return the new environment variable or alias */
}

/**
 * set_env - Sets an environment variable by updating or creating it.
 *
 * @name: Name of the environment variable
 * @value: Value of the environment variable
 * @datash: Data structure (environ)
 * Return: No return
 */
void set_env(char *name, char *value, data_shell *datash)
{
	int i;
	char *var_env, *name_env;

	/* Loop through the existing environment variables */
	for (i = 0; datash->_environ[i]; i++)
	{
		var_env = _strdup(datash->_environ[i]); /* Duplicate the current environment variable */
		name_env = _strtok(var_env, "="); /* Tokenize it to get the name part */
		if (_strcmp(name_env, name) == 0) /* If the name matches the target name */
		{
			free(datash->_environ[i]); /* Free the existing environment variable */
			datash->_environ[i] = copy_info(name_env, value); /* Update it with the new value */
			free(var_env); /* Free the duplicated variable */
			return;
		}
		free(var_env); /* Free the duplicated variable */
	}

	/* If the environment variable does not exist, create a new one */
	datash->_environ = _reallocdp(datash->_environ, i, sizeof(char *) * (i + 2));
	datash->_environ[i] = copy_info(name, value); /* Create the new environment variable */
	datash->_environ[i + 1] = NULL;
}

/**
 * _setenv - Sets or updates an environment variable.
 *
 * @datash: Data relevant (env name and env value)
 * Return: 1 on success.
 */
int _setenv(data_shell *datash)
{

	if (datash->args[1] == NULL || datash->args[2] == NULL)
	{
		get_error(datash, -1); /* If arguments are missing, report an error */
		return (1);
	}

	set_env(datash->args[1], datash->args[2], datash); /* Set or update the environment variable */

	return (1); /* Return success */
}

/**
 * _unsetenv - Deletes an environment variable.
 *
 * @datash: Data relevant (env name)
 * Return: 1 on success.
 */
int _unsetenv(data_shell *datash)
{
	char **realloc_environ;
	char *var_env, *name_env;
	int i, j, k;

	if (datash->args[1] == NULL)
	{
		get_error(datash, -1); /* If argument is missing, report an error */
		return (1);
	}
	k = -1;
OBOBOBOBOB	for (i = 0; datash->_environ[i]; i++)
	{
		var_env = _strdup(datash->_environ[i]); /* Duplicate the current environment variable */
		name_env = _strtok(var_env, "="); /* Tokenize it to get the name part */
OBOBOBOBOB		if (_strcmp(name_env, datash->args[1]) == 0) /* If the name matches the target name */
OBOBOBOBOBOBOBOBOBOB		{
			k = i; /* Mark the index for deletion */
OBOBOBOBOB		}
		free(var_env); /* Free the duplicated variable */
	}
	if (k == -1)
	{
		get_error(datash, -1); /* If the environment variable doesn't exist, report an error */
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (i));
	for (i = j = 0; datash->_environ[i]; i++)
	{
		if (i != k)
		{
			realloc_environ[j] = datash->_environ[i]; /* Copy non-deleted environment variables */
			j++;
		}
	}
	realloc_environ[j] = NULL; /* Null-terminate the new environment variable list */
	free(datash->_environ[k]); /* Free the deleted environment variable */
	free(datash->_environ); /* Free the old environment variable list */
	datash->_environ = realloc_environ; /* Update the environment variable list */
	return (1); /* Return success */
}
