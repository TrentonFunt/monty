#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", fpush}, {"pall", fpall}, {"pint", fpint},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op_arg;

	op_arg = strtok(content, " \n\t");
	if (op_arg && op_arg[0] == '#')
		return (0);
	data.argument = strtok(NULL, " \n\t");
	while (opst[i].opcode && op_arg)
	{
		if (strcmp(op_arg, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op_arg && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op_arg);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
