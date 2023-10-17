#include "main.h"

/**
 * aux_help_env - Displays help information for the "env" built-in command.
 * Return: No return.
 */
void aux_help_env(void)
{
	char *help = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, help, _strlen(help));  /* Write the help message to standard output */
	help = "Print the environment of the shell.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_setenv - Displays help information for the "setenv" built-in command.
 * Return: No return.
 */
void aux_help_setenv(void)
{
	char *help = "setenv: setenv (const char *name, const char *value, int replace)\n\t";

	write(STDOUT_FILENO, help, _strlen(help));  /* Write the help message to standard output */
	help = "Add a new definition to the environment.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_unsetenv - Displays help information for the "unsetenv" built-in command.
 * Return: No return.
 */
void aux_help_unsetenv(void)
{
	char *help = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, help, _strlen(help));  /* Write the help message to standard output */
	help = "Remove an entry completely from the environment.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_general - Entry point for displaying general help information.
 * Return: No return.
 */
void aux_help_general(void)
{
	char *help = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, help, _strlen(help));  /* Write the help message to standard output */
	help = "These commands are defined internally. Type 'help' to see the list.";
	write(STDOUT_FILENO, help, _strlen(help));
	help = " Type 'help name' to find out more about the function 'name'.\n\n";
	write(STDOUT_FILENO, help, _strlen(help));
	help = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "unsetenv [variable]\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * aux_help_exit - Displays help information for the "exit" built-in command.
 * Return: No return.
 */
void aux_help_exit(void)
{
	char *help = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, help, _strlen(help));  /* Write the help message to standard output */
	help = "Exits the shell with a status of N. If N is omitted, the exit";
	write(STDOUT_FILENO, help, _strlen(help));
	help = " status is that of the last command executed.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}
