#include "monty.h"
/**
 * swap - swap top two nodes
 * @head: stack to use
 * @line_number: line we are on
 *
 * Return: void
*/
void swap(stack_t **head, unsigned int line_number)
{
	stack_t *tmp, *tmp2;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		global = 10000;
		return;
	}
	tmp = *head;
	tmp2 = tmp->next;
	tmp->next = tmp2->next;
	if (tmp2->next != NULL)
	{
		tmp2->next->prev = tmp;
	}
	tmp2->prev = NULL;
	tmp2->next = tmp;
	tmp->prev = tmp2;
	*head = tmp2;
}
