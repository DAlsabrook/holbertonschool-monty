#include "monty.h"
/**
 * main - Program entry point
 * @argc: count of arguments
 * @argv: Array of arguments given to program (should contain fd to read)
 *
 * Return: 0 on success
 */

unsigned int global = 0;
int main(int argc, char *argv[])
{
	char *getline_string = NULL, *token, line[100];
	instruction_t obj;
	stack_t *head = NULL;
	int flag = 0, i = 0, j = 0;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	getline_string = get_input(argv[1]);
	if (!getline_string)
		free_exit(getline_string, head, 2);
	//printf("getline: %s", getline_string);/*string = "push 1   push 2 \npush 3 pall \n   push 4    push 5 pall\0"*/
	while (getline_string[i] != '\0')
	{
		while (getline_string[i] != '\n' && getline_string[i])
		{
			line[j] = getline_string[i];
			i++;
			j++;
		}
		i++;
		line[j] = '\0';
		j = 0;
		line_number++;
		//printf("Line #%d\n", line_number);
		//printf("Line after newline loop: |%s|\n", line);
		token = strtok(line, " "); /*string = "push\0"*/
		while (flag != 2)
		{
			obj.f = func_p(token, flag);
			//printf("Global: %u\n", global);
			if (global == 1)/*means end of single_line (strtok was NULL)*/
				free_exit(getline_string, head, 2);
			else if (global == 2)
				break;
			else if (obj.f == NULL)
			{
				flag = 1;
				continue;
			}
			obj.f(&head, line_number);
			if (global == 1) /*global 1 if needing to exit from error*/
				free_exit(getline_string, head, 2);
			flag = 2;
		}
		global = 0;
		line[0] = '\0';
		flag = 0;
		//printf("Loops end\n\n");
	}
	//printf("EXIT\n");
	free_exit(getline_string, head, 0);
	return (0);
}
