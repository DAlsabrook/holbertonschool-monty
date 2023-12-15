#include "monty.h"
/**
 * get_input - reads each single_line from the file and allocates memory for it
 * @file: file passed in to parse
 *
 * Return: string of all lines from file
 */
char *get_input(char *file)
{
	char *getline_string = NULL, *single_line = NULL;
	size_t size = 0;
	int file_fd;
	struct stat file_info;
	FILE *opened_file;
	/*open file*/
	file_fd = open(file, O_RDONLY);
	opened_file = fopen(file, "r");
	if (opened_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		close(file_fd);
		return (NULL);
	}
	/*get file size in bytes from fstat and malloc*/
	fstat(file_fd, &file_info);
	getline_string = malloc(file_info.st_size + 1);
	if (!getline_string)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	/*use getline() to put all lines into getline_string*/
	getline_string[0] = '\0';
	while (getline(&single_line, &size, opened_file) != -1)
	{
		strcat(getline_string, single_line);
		free(single_line);
		single_line = NULL;
	}
	string_clean(getline_string);
	close(file_fd);
	fclose(opened_file);
	free(single_line);
	return (getline_string);
}
/**
 * string_clean - cleans string of newline and $
 * @getline_string: string to clean
 *
 * Return: cleaned string
 */
char *string_clean(char *getline_string)
{
	int i;

	for (i = 0; getline_string[i]; i++)
	{
		if (getline_string[i] == '$')
			getline_string[i] = ' ';
	}
	return (getline_string);
}
