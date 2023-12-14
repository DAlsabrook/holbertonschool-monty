#include "monty.h"
/**
 * pall - prints all nodes
 * @head: stack to use
 * @line_number: line number of command
 *
 * Return: void
 */
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (*head == NULL || line_number <= 0)
		return;
	tmp = *head;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
