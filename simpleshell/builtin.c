#include "main.h"

/**
 * get_builtin - Function that pairs the command in the argument with a builtin function
 *
 * @cmd: Command name
 * Return: Function pointer to the corresponding builtin command
 */
int (*get_builtin(char *cmd))(data_shell *)
{
	builtin_t builtin[] = {
		{ "env", _env },        /* Builtin for the 'env' command */
		{ "exit", exit_shell }, /* Builtin for the 'exit' command */
		{ "setenv", _setenv },  /* Builtin for the 'setenv' command */
		{ "unsetenv", _unsetenv }, /* Builtin for the 'unsetenv' command */
		{ "cd", cd_shell },     /* Builtin for the 'cd' command */
		{ "help", get_help },   /* Builtin for the 'help' command */
		{ NULL, NULL }
	};
	int i;

	/* Iterate through the 'builtin' array to find the matching command */
	for (i = 0; builtin[i].name; i++)
	{
		if (_strcmp(builtin[i].name, cmd) == 0)
			break;
	}

	return (builtin[i].f); /* Return the corresponding function pointer for the command */
}
