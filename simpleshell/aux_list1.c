#include "main.h"

/**
 * add_sep_node_end - Adds a separator found at the end of a sep_list.
 * @head: Pointer to the head of the linked list.
 * @sep: Separator found (; | &).
 * Return: Address of the head.
 */
sep_list *add_sep_node_end(sep_list **head, char sep)
{
	sep_list *new, *temp;

	new = malloc(sizeof(sep_list));  /* Allocate memory for a new sep_list node */
	if (new == NULL)
		return (NULL);

	new->separator = sep;  /* Set the separator value */
	new->next = NULL;      /* Initialize the next pointer of the new node */
	temp = *head;          /* Store the address of the head in a temporary variable */

	if (temp == NULL)      /* If the list is empty, set the new node as the head */
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)  /* Traverse the list to find the last node */
			temp = temp->next;
		temp->next = new;  /* Set the new node as the next node of the last node */
	}

	return (*head);  /* Return the address of the head */
}

/**
 * free_sep_list - Frees a sep_list.
 * @head: Pointer to the head of the linked list.
 * Return: No return.
 */
void free_sep_list(sep_list **head)
{
	sep_list *temp;
	sep_list *curr;

	if (head != NULL)
	{
		curr = *head;  /* Set curr to the head of the list */
		while ((temp = curr) != NULL)  /* Traverse the list and free each node */
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;  /* Set the head to NULL after freeing all nodes */
	}
}

/**
 * add_line_node_end - Adds a command line at the end of a line_list.
 * @head: Pointer to the head of the linked list.
 * @line: Command line.
 * Return: Address of the head.
 */
line_list *add_line_node_end(line_list **head, char *line)
{
	line_list *new, *temp;

	new = malloc(sizeof(line_list));  /* Allocate memory for a new line_list node */
	if (new == NULL)
		return (NULL);

	new->line = line;    /* Set the command line value */
	new->next = NULL;    /* Initialize the next pointer of the new node */
	temp = *head;        /* Store the address of the head in a temporary variable */

	if (temp == NULL)    /* If the list is empty, set the new node as the head */
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)  /* Traverse the list to find the last node */
			temp = temp->next;
		temp->next = new;  /* Set the new node as the next node of the last node */
	}

	return (*head);  /* Return the address of the head */
}

/**
 * free_line_list - Frees a line_list.
 * @head: Pointer to the head of the linked list.
 * Return: No return.
 */
void free_line_list(line_list **head)
{
	line_list *temp;
	line_list *curr;

	if (head != NULL)
	{
		curr = *head;  /* Set curr to the head of the list */
		while ((temp = curr) != NULL)  /* Traverse the list and free each node */
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;  /* Set the head to NULL after freeing all nodes */
	}
}
