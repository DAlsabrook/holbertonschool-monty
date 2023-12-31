#ifndef MONTY
#define MONTY
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*Global variable*/
extern unsigned int global;

/*prototypes*/
void add(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);
void nop(stack_t **head, unsigned int line_number);
void pop(stack_t **head, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void pall(stack_t **head, unsigned int line_number);
void push(stack_t **head, unsigned int line_number);
void new_line(stack_t **head, unsigned int line_number);
char *get_input(char *file);
char *string_clean(char *getline_string);
void (*func_p(char *tok, int flag))(stack_t **head, unsigned int line_number);
void free_exit(char *getline_string, stack_t *head, int i);
stack_t *execute(char *line, unsigned int line_number, stack_t *head);

#endif
