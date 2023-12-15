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
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{NULL, NULL}};
	if (flag == 1)
		tok = strtok(NULL, " ");
	if (tok == NULL)
	{
		global = 20000;
		return (NULL);
	}
	//printf("strcmp Token: |%s|\n", tok);
	while (ops[i].opcode)
	{
		if (strcmp(ops[i].opcode, tok) == 0)
		{
			//printf("Found matching func\n");
			return (ops[i].f);
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n",global, tok);
	global = 10000;
	return (NULL);
}
