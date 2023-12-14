#include "monty.h"
/**
 * get_func - get the corresponding function
 * @tok: token
 * @flag: says if we are in loop
 *
 * Return: correct function
 */
void (*get_func(char *tok, int flag))(stack_t **head, unsigned int line_number)
{
	int i = 0;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}};
	/*use strtok to get first element and set strtok to the string in memory*/
	/*then compare op[i].opcode to the tok*/
	if (flag == 1)
		tok = strtok(NULL, " ");
	if (tok == NULL)
		return (NULL);
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
