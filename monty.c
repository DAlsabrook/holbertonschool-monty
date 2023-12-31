#include "monty.h"
unsigned int global = 0;
/**
 * main - Program entry point
 * @argc: count of arguments
 * @argv: Array of arguments given to program (should contain fd to read)
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *getline_string = NULL, line[100];
	stack_t *head = NULL;
	int i = 0, j = 0;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	/*get input from file and put all lines in 1 string*/
	getline_string = get_input(argv[1]);
	if (!getline_string)
		free_exit(getline_string, head, 2);
	while (getline_string[i] != '\0')
	{
		/*grab the first line from the file and set to char *line*/
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
		/*send line in to be tokenized and ran(if possible)*/
		head = execute(line, line_number, head);
		/*global 10000 if needing to exit from error*/
		if (global == 10000)
			free_exit(getline_string, head, 2);
		/*global 20000 if no command found in line*/
		else if (global == 20000)
			global = 0;
		line[0] = '\0';
	}
	free_exit(getline_string, head, 0);
	return (0);
}
