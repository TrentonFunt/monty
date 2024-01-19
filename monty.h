#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
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
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct monty_data - Carries values through the program
 * @argument: Value passed as an argument
 * @file_pointer: Pointer to the Monty file
 * @line_content: Content of the current line in the file
 * @stack_mode: Flag to change stack <-> queue
 * Description: This structure is used to pass values
 * through the program efficiently
 */
typedef struct monty_data
{
	char *argument;
	FILE *file_pointer;
	char *line_content;
	int stack_mode;
}  data_t;
extern data_t data;
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file);
void add_queue(stack_t **stack_head, int num);
void add_node(stack_t **stack_head, int num);
void free_stack(stack_t *stack_head);
void fpush(stack_t **stack_head, unsigned int stack_value);
void fpall(stack_t **stack_head, unsigned int stack_value);
void fpint(stack_t **stack_head, unsigned int stack_value);
void fpop(stack_t **stack_head, unsigned int stack_value);
void fswap(stack_t **stack_head, unsigned int stack_value);
void fnop(stack_t **stack_head, unsigned int stack_value);
void fadd(stack_t **stack_head, unsigned int value);
#endif /* MONTY_H */
