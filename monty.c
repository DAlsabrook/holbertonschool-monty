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
	char *getline_string = NULL, *token, *single_line, line[100];
	instruction_t obj;
	stack_t *head = NULL;
	int flag = 1, flag2 = 0;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	getline_string = get_input(argv[1]);
	if (!getline_string)
		free_exit(getline_string, head, 2);
	printf("getline: %s", getline_string);/*string = "push 1   push 2 \npush 3 pall \n   push 4    push 5 pall\0"*/
	single_line = strtok(getline_string, "\n");
	while (single_line)
	{
		printf("start\n");
		printf("Single_line check |%s|\n", single_line);
		if (flag == 0)
			single_line = strtok(NULL, "\n"); /*string = "push 1   push 2 \0"*/
		/**
		 * make a loop that itterates to \n and sends everything before that
		 * while (getline_string[j] != "\n")
		 * {
		 * 	new_string[j] = getline_string[j];
		 * 	j++;
		 * }
		 * j++; to get past new line
		 * Its iterator "j" then holds its spot for the next loop
		 */
		printf("Single_line check |%s|\n", single_line);
		if (single_line == NULL) /*end of getline_string*/
			break;
		strcpy(line, single_line);
		line_number++;
		printf("Line# %d\n", line_number);
		printf("single_line: |%s|\n", line);
		token = strtok(line, " "); /*string = "push\0"*/
		while (flag2 != 2)
		{
			printf("Token: |%s|\n", token);
			obj.f = func_p(token, flag);
			if (global == 1)/*means end of single_line (strtok was NULL)*/
				break;
			else if (obj.f == NULL)
			{
				flag2 = 1;
				continue;
			}
			obj.f(&head, line_number);
			if (global == 1) /*global 1 if needing to exit from error*/
				free_exit(getline_string, head, 2);
			flag2 = 2;
		}
		flag2 = 0;
		flag = 0;
	}
	free_exit(getline_string, head, 0);
	return (0);
}
