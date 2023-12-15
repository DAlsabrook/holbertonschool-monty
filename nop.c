#include "monty.h"
/**
 * nop - does nothin
 * @head: stack
 * @line_number: line number
 * 
 * Return void
*/
void nop(stack_t **head, unsigned int line_number)
{
	if (*head && line_number)
	{
		return;
	}
}
