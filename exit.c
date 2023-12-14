#include "monty.c"
/**
 * free_exit - frees all memory and then exits
 * @getline_string: string from getline may need free
 * @head: head to free
 *
 * Return: void
 */
void free_exit(char *getline_string, stack_t *head, int i)
{
	stack_t *tmp;

	if (getline_string)
		free(getline_string);
	if (head)
	{
		while (head->next != NULL)
		{
			tmp = head->next;
			free(head);
			head = tmp;
		}
		free(head);
	}
	if (i == 2)
		exit(EXIT_FAILURE);
	return;
}
