#include "monty.h"
/**
 * pop - prints value at the top of the stack
 * @head: stack to use
 * @line_number: line number
 *
 * Return: void
 */
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *tmp;
	if (*head && line_number > 0)
	{
		tmp = *head;
		*head = tmp->next;
		if (tmp->next != NULL)
		{
			tmp->next->prev = NULL;
		}
		free(tmp);
	}
	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		global = 1;
	}
}
