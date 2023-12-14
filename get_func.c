#include "monty.h"
/**
 * get_func - get the corresponding function
 * @tok: token
 * @flag: says if we are in loop
 *
 * Return: correct function
 */
void (*func_p(char *tok, int flag, int u))(stack_t **head, unsigned int line_number)
{
	int i = 0;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}};
	u = 0;
	if (flag == 1)
		tok = strtok(NULL, " ");
	if (tok == NULL)
	{
		u = 1;
		return (NULL);
	}
	while (ops[i].opcode)
	{
		if (strcmp(ops[i].opcode, tok) == 0)
		{
			return (ops[i].f);
		}
		i++;
	}
	return (NULL);
}
