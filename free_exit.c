#include "monty.h"
/**
 * free_exit - frees all memory and then exits
 * @getline_string: string from getline may need free
 * @head: head to free
 * @return_code: int to hold return flag
 *
 * Return: void
 */
void free_exit(char *getline_string, stack_t *head, int return_code)
{
	stack_t *tmp;

	if (getline_string != NULL)
		free(getline_string);
	if (head != NULL)
	{
		while (head->next != NULL)
		{
			tmp = head->next;
			free(head);
			head = tmp;
		}
		free(head);
	}
	if (return_code == 2)
		exit(EXIT_FAILURE);
}
