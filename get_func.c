#include "monty.h"
/**
 * get_func - get the corresponding function
 * @tok: token
 * @flag: says if we are in loop
 *
 * Return: correct function
 */
void (*func_p(char *tok, int flag))(stack_t **head, unsigned int line_number)
{
	int i = 0;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{NULL, NULL}};
	if (flag == 1)
		tok = strtok(NULL, " ");
	printf("Token: %s\n", tok);
	if (tok == NULL)
	{
		printf("Token was null.\n");
		exit_check = 1;
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
