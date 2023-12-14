#include "monty.h"
/**
 * pint - prints value at the top of the stack
 * @head: stack to use
 * @line_number: line number
 * 
 * Return: void
*/
void pint(stack_t **head, unsigned int line_number)
{
	if (*head && line_number > 0)
	{
		printf("%d", (*head)->n);
		return;
	}
	fprintf(stderr, "L%u: can't pint, stack empty", line_number);
	exit_check = 1;
}