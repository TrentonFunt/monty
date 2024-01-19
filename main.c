#define _POSIX_C_SOURCE 200809L

#include "monty.h"
data_t data = {NULL, NULL, NULL, 0};
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
