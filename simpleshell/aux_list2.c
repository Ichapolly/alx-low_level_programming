#include "main.h"

/**
 * add_rvar_node - Adds a variable at the end of a r_var list.
 * @head: Pointer to the head of the linked list.
 * @lvar: Length of the variable.
 * @val: Value of the variable.
 * @lval: Length of the value.
 * Return: Address of the head.
 */
r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval)
{
	r_var *new, *temp;

	new = malloc(sizeof(r_var));  /* Allocate memory for a new r_var node */
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;  /* Set the length of the variable */
	new->val = val;       /* Set the value of the variable */
	new->len_val = lval;  /* Set the length of the value */

	new->next = NULL;     /* Initialize the next pointer of the new node */
	temp = *head;         /* Store the address of the head in a temporary variable */

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
 * free_rvar_list - Frees a r_var list.
 * @head: Pointer to the head of the linked list.
 * Return: No return.
 */
void free_rvar_list(r_var **head)
{
	r_var *temp;
	r_var *curr;

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
