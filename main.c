#include "monty.h"

data_t data;

/**
 * execute - Executes the opcode from the Monty file.
 * @content: Line content from the Monty file.
 * @stack: Pointer to the head of the linked list representing the stack.
 * @counter: Line number being processed.
 * @file: Pointer to the Monty file being read.
 * Return: No explicit return value.
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
		{"push", fpush}, {"pall", fpall}, {"pint", fpint}, {"pop", fpop}, {"swap", fswap}, {"add", fadd}, {"nop", fnop}, {NULL, NULL}
	};
	unsigned int i = 0;
	char *op_arg;

	/* Extract the opcode from the line content */
	op_arg = strtok(content, " \n\t");

	/* Ignore lines starting with '#' (comments) */
	if (op_arg && op_arg[0] == '#')
		return (0);

	/* Extract the argument for the opcode, if any */
	data.argument = strtok(NULL, " \n\t");

	/* Loop through the opcode-function pairs */
	while (opst[i].opcode && op_arg)
	{
		/* Execute the corresponding function if opcode is found */
		if (strcmp(op_arg, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}

	/* Handle case when opcode is not found */
	if (op_arg && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op_arg);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}

/**
* main - Monty bytecode interpreter
* @argc: Number of command-line arguments
* @argv: Array of command-line argument
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int value = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	data.file_pointer = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		data.line_content = content;
		value++;
		if (read_line > 0)
		{
			execute(content, &stack, value, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);

	return (0);
}
