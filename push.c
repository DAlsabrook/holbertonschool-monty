#include "monty.h"
/**
 * push - push node at the top of the list
 * @head: stack to use
 * @line_number: line number of command
 *
 * Return: void
 */
void push(stack_t **head, unsigned int line_number)
{
	const char *token = NULL;
	int n;
	stack_t *new_node;

	if (line_number <= 0)
		return;
	token = strtok(NULL, " ");
	//printf("(push) Token: %s\n", token);
	if (token == NULL || strcmp(token, "-0") == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		global = 1;
		return;
	}
	printf("Token: %s\n", token);
	n = atoi(token); /*when fails returns 0 so when no token it prints 0*/
	printf("n: %d\n", n);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		printf("Error: malloc failed\n");
		return;
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *head;
	if (*head)
		(*head)->prev = new_node;
	*head = new_node;
	printf("New node value: %d\n", new_node->n);
}
