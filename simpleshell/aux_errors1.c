#include "main.h"

/**
 * strcat_cd - Concatenates an error message for the "cd" command.
 * @datash: Data relevant to the error (directory).
 * @msg: Message to print.
 * @error: Output message.
 * @ver_str: Counter lines.
 * Return: Error message.
 */
char *strcat_cd(data_shell *datash, char *msg, char *error, char *ver_str)
{
	char *illegal_flag;

	_strcpy(error, datash->av[0]);  /* Copy the executable name to the error message */
	_strcat(error, ": ");  /* Concatenate a separator and counter */
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);  /* Concatenate the argument causing the error */
	_strcat(error, msg);  /* Concatenate the error message */
	if (datash->args[1][0] == '-')  /* Check if the second argument starts with '-' (a flag) */
	{
		illegal_flag = malloc(3);  /* Allocate memory for the illegal flag message */
		illegal_flag[0] = '-';
		illegal_flag[1] = datash->args[1][1];
		illegal_flag[2] = '\0';
		_strcat(error, illegal_flag);  /* Concatenate the illegal flag */
		free(illegal_flag);  /* Free the memory allocated for the flag message */
	}
	else
	{
		_strcat(error, datash->args[1]);  /* Concatenate the directory that "cd" attempted to change to */
	}

	_strcat(error, "\n");  /* Add a new line and null-terminate the error message */
	_strcat(error, "\0");

	return (error);
}

/**
 * error_get_cd - Generates an error message for the "cd" command in get_cd.
 * @datash: Data relevant to the error (directory).
 * Return: Error message.
 */
char *error_get_cd(data_shell *datash)
{
	int length, len_id;
	char *error, *ver_str, *msg;

	ver_str = aux_itoa(datash->counter);  /* Convert the counter to a string */
	if (datash->args[1][0] == '-')  /* Check if the second argument starts with '-' (an illegal option) */
	{
		msg = ": Illegal option ";  /* Error message for illegal option */
		len_id = 2;  /* Length of the illegal option */
	}
	else
	{
		msg = ": can't cd to ";  /* Error message for inability to change to a directory */
		len_id = _strlen(datash->args[1]);  /* Length of the directory path */
	}

	length = _strlen(datash->av[0]) + _strlen(datash->args[0]);  /* Calculate the total length needed for the error message */
	length += _strlen(ver_str) + _strlen(msg) + len_id + 5;
	error = malloc(sizeof(char) * (length + 1));  /* Allocate memory for the error message */

	if (error == 0)  /* Check if memory allocation failed */
	{
		free(ver_str);
		return (NULL);
	}

	error = strcat_cd(datash, msg, error, ver_str);  /* Concatenate the error message */

	free(ver_str);  /* Free the counter string */

	return (error);
}

/**
 * error_not_found - Generates a generic error message for a command not found.
 * @datash: Data relevant to the error (counter, arguments).
 * Return: Error message.
 */
char *error_not_found(data_shell *datash)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(datash->counter);  /* Convert the counter to a string */
	length = _strlen(datash->av[0]) + _strlen(ver_str);  /* Calculate the total length needed for the error message */
	length += _strlen(datash->args[0]) + 16;
	error = malloc(sizeof(char) * (length + 1));  /* Allocate memory for the error message */
	if (error == 0)  /* Check if memory allocation failed */
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);  /* Copy the executable name to the error message */
	_strcat(error, ": ");  /* Concatenate a separator and counter */
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);  /* Concatenate the command name that was not found */
	_strcat(error, ": not found\n");  /* Concatenate the error message */
	_strcat(error, "\0");  /* Null-terminate the error message */
	free(ver_str);  /* Free the counter string */

	return (error);
}

/**
 * error_exit_shell - Generates a generic error message for the "exit" command in get_exit.
 * @datash: Data relevant to the error (counter, arguments).
 * Return: Error message.
 */
char *error_exit_shell(data_shell *datash)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(datash->counter);  /* Convert the counter to a string */
	length = _strlen(datash->av[0]) + _strlen(ver_str);  /* Calculate the total length needed for the error message */
	length += _strlen(datash->args[0]) + _strlen(datash->args[1]) + 23;
	error = malloc(sizeof(char) * (length + 1));  /* Allocate memory for the error message */
	if (error == 0)  /* Check if memory allocation failed */
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);  /* Copy the executable name to the error message */
	_strcat(error, ": ");  /* Concatenate a separator and counter */
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);  /* Concatenate the command name ("exit") */
	_strcat(error, ": Illegal number: ");  /* Concatenate part of the error message */
	_strcat(error, datash->args[1]);  /* Concatenate the illegal number that caused the error */
	_strcat(error, "\n\0");  /* Null-terminate the error message */
	free(ver_str);  /* Free the counter string */

	return (error);
}
