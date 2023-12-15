#include "monty.h"
/**
 * execute - finds function for command and executes
 * 
 * 
 * Return: void
*/
stack_t *execute(char *line, unsigned int line_number, stack_t *head)
{
	char *token;
	int flag = 0;
	unsigned int tmp;
	instruction_t obj;

	token = strtok(line, " "); /*string = "push\0"*/
	while (flag != 2)
	{
		tmp = global;
		global = line_number;
		obj.f = func_p(token, flag);
		if (tmp != 0)
			tmp = 0;
		if (global != line_number)
		{
			if (global >= 10000 )
				return (head);
			else if (obj.f == NULL)
			{
				flag = 1;
				continue;
			}
		}
		global = 0;
		obj.f(&head, line_number);
		if (global == 10000) /*global 1 if needing to exit from error*/
			return (head);
		flag = 2;
	}
	return (head);
}
