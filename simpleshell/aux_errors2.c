#include "main.h"

/**
 * error_env - Generates an error message for the "env" command in get_env.
 * @datash: Data relevant to the error (counter, arguments).
 * Return: The error message.
 */
char *error_env(data_shell *datash)
{
	int length;
	char *error;
	char *ver_str;
	char *msg;

	ver_str = aux_itoa(datash->counter);  /* Convert the counter to a string */
	msg = ": Unable to add/remove from environment\n";  /* Error message */
	length = _strlen(datash->av[0]) + _strlen(ver_str);  /* Calculate the total length needed for the error message */
	length += _strlen(datash->args[0]) + _strlen(msg) + 4;
	error = malloc(sizeof(char) * (length + 1));  /* Allocate memory for the error message */
	if (error == 0)  /* Check if memory allocation failed */
	{
		free(error);  /* Free previously allocated memory, if any */
		free(ver_str);
		return (NULL);
	}

	_strcpy(error, datash->av[0]);  /* Copy the executable name to the error message */
	_strcat(error, ": ");  /* Concatenate a separator and counter */
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);  /* Concatenate the argument causing the error */
	_strcat(error, msg);  /* Concatenate the error message */
	_strcat(error, "\0");  /* Null-terminate the error message */
	free(ver_str);  /* Free the counter string */

	return (error);
}

/**
 * error_path_126 - Generates an error message for the "path" command when permission is denied.
 * @datash: Data relevant to the error (counter, arguments).
 * Return: The error message.
 */
char *error_path_126(data_shell *datash)
{
	int length;
	char *ver_str;
	char *error;

	ver_str = aux_itoa(datash->counter);  /* Convert the counter to a string */
	length = _strlen(datash->av[0]) + _strlen(ver_str);  /* Calculate the total length needed for the error message */
	length += _strlen(datash->args[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));  /* Allocate memory for the error message */
	if (error == 0)  /* Check if memory allocation failed */
	{
		free(error);  /* Free previously allocated memory, if any */
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);  /* Copy the executable name to the error message */
	_strcat(error, ": ");  /* Concatenate a separator and counter */
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);  /* Concatenate the argument causing the error */
	_strcat(error, ": Permission denied\n");  /* Concatenate the error message */
	_strcat(error, "\0");  /* Null-terminate the error message */
	free(ver_str);  /* Free the counter string */

	return (error);
}
