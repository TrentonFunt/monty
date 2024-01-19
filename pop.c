#include "monty.h"

/**
 * fpop - Removes the top element from the stack.
 * @stack_head: Pointer to the head of the stack.
 * @stack_value: Line number in the Monty file.
 * This function removes the top element from the stack.
 * If the stack is empty, it prints an error message,
 * frees allocated memory, and exits
 * with failure status.
 */
void fpop(stack_t **stack_head, unsigned int stack_value)
{
	/* Declare a temporary pointer to the stack node */
	stack_t *sh;

	/* Check if the stack is empty */
	if (*stack_head == NULL)
	{
		/* Print error message and exit if stack is empty */
		fprintf(stderr, "L%d: can't pop an empty stack\n", stack_value);
		fclose(data.file_pointer);
		free(data.line_content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}

	/* Store the current head of the stack in the temporary pointer */
	sh = *stack_head;

	/* Update the stack head to the next element in the stack */
	*stack_head = sh->next;

	/* Free the memory allocated for the removed stack node */
	free(sh);
}
