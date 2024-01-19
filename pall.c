#include "monty.h"

/**
 * fpall - Prints all the values on the stack
 * @stack_head: Double pointer to the head of the stack
 * @stack_value: This is where the opcode appears
 **/
void fpall(stack_t **stack_head, unsigned int stack_value)
{
	stack_t *sh;

	(void)stack_value;

	sh = *stack_head;
	if (sh == NULL)
		return;
	while (sh)
	{
		printf("%d\n", sh->n);
		sh = sh->next;
	}
}
