#include "monty.h"
/**
 * get_func - get the corresponding function
 * @getline_string: array to use
 *
 * Return: correct function
 */
void (*get_func(char *token, int flag))(stack_t **head, unsigned int line_number)
{
	int i = 0;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}};
	/*use strtok to get first element and set strtok to the string in memory*/
	/*then compare op[i].opcode to the token*/
	if (flag == 1)
		token = strtok(NULL, " ");
	if (token == NULL)
		return (NULL);
	while (ops[i].opcode)
	{
		if (strcmp(ops[i].opcode, token) == 0)
		{
			return (ops[i].f);
		}
		i++;
	}
	return (NULL);
}
