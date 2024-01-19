#include "monty.h"
/**
 * fswap - function swaps the values of the top two elements
 * of the stack
 * @stack_head: Pointer to the head of the stack
 * @stack_value: Line number in the Monty where the opcode appears
*/
void fswap(stack_t **stack_head, unsigned int stack_value)
{
	stack_t *sh;
	int i = 0, hs;

	sh = *stack_head;
	while (sh)
	{
		sh = sh->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", stack_value);
		fclose(data.file_pointer);
		free(data.line_content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	sh = *stack_head;
	hs = sh->n;
	sh->n = sh->next->n;
	sh->next->n = hs;
}
