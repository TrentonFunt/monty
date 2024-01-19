#include "monty.h"
/**
 * fpint - Prints the top element of the stack.
 * @stack_head: Pointer to the head of the stack.
 * @stack_value: Line number where the instruction appears.
 * If the stack is empty, prints an error message with line number,
 * closes the file, frees allocated memory, and exits with failure.
*/
void fpint(stack_t **stack_head, unsigned int stack_value)
{
	if (*stack_head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", stack_value);
		fclose(data.file_pointer);
		free(data.line_content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack_head)->n);
}
