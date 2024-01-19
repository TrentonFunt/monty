#include "monty.h"

/**
 * free_stack - prints the top
 * @stack_head: Double pointer to the head of the stack
*/
void free_stack(stack_t *stack_head)
{
	stack_t *hs;

	hs = stack_head;
	while (stack_head)
	{
		hs = stack_head->next;
		free(stack_head);
		stack_head = hs;
	}
}

/**
 * fpush - add node to the stack
 * @stack_head: Double pointer to the head of the stack
 * @stack_value: line_number
 */
void fpush(stack_t **stack_head, unsigned int stack_value)
{
	int i, j;

	if (!data.argument)
	{
		fprintf(stderr, "L%d: usage: push integer\n", stack_value);
		fclose(data.file_pointer);
		free(data.line_content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}

	for (j = (data.argument[0] == '-'); data.argument[j]; j++)
	{
		if (!isdigit(data.argument[j]))
		{
			fprintf(stderr, "L%d: usage: push integer\n", stack_value);
			fclose(data.file_pointer);
			free(data.line_content);
			free_stack(*stack_head);
			exit(EXIT_FAILURE);
		}
	}

	i = atoi(data.argument);
	if (data.stack_mode == 0)
		add_node(stack_head, i);
	else
		add_queue(stack_head, i);
}
