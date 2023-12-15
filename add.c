#include "monty.h"
/**
 * add - add top two elements of list
 * @head: stack to use
 * @line_number: line number we are on
 * 
 * Return: void
*/
void add(stack_t **head, unsigned int line_number)
{
	if (!*head || !(*head)-> next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		global = 10000;
		return;
	}
	(*head)->next->n += (*head)->n;
	pop(head, line_number);

}
