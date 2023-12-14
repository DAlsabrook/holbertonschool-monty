#include "monty.h"
/**
 * main - Program entry point
 * @argc: count of arguments
 * @argv: Array of arguments given to program (should contain fd to read)
 *
 * Return: 0 on success
 */

int exit_check = 0;
int main(int argc, char *argv[])
{
	char *getline_string = NULL, *token;
	instruction_t obj;
	stack_t *head = NULL;
	int flag = 0;
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	/*get each line and put into single string*/
	getline_string = get_input(argv[1]);
	if (!getline_string)
		free_exit(getline_string, head, 2);
	/*Find func and store in obj. Then run obj.f*/
	token = strtok(getline_string, " ");
	/*line_check = 1*/
	while (token)
	{
		/*add the  $ back and if token = $ line_number++, line_check = 1, strtok again to advance to next command*/
		obj.f = get_func(token, flag);
		if (obj.f == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
			line_number++;
			flag = 1;
			break;
		}
		/*line_check = 0 aka we ran a command*/
		obj.f(&head, line_number);
		/*global variable exit_check 1 if needing to exit*/
		if (exit_check == 1)
			free_exit(getline_string, head, 2);
		line_number++;
		flag = 1;
	}
	free_exit(getline_string, head, 0);
	return (0);
}
