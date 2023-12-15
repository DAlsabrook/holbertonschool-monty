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
		fprintf(stderr, "L%u: can't add, stack too short", line_number);
		global = 10000;
	}
	(*head)->next->n += (*head)->n;
	pop(head, line_number);

}
