#include "monty.h"
/**
 * add_node - added node to head stack
 * @stack_head: Double pointer to the head of the stack
 * @num: new value
*/
void add_node(stack_t **stack_head, int num)
{

	stack_t *added_node, *hs;

	hs = *stack_head;
	added_node = malloc(sizeof(stack_t));
	if (added_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (hs)
		hs->prev = added_node;
	added_node->n = num;
	added_node->next = *stack_head;
	added_node->prev = NULL;
	*stack_head = added_node;
}

/**
 * add_queue - queue added node to stack
 * @num: new value
 * @stack_head: Double pointer to the head of the stack
*/
void add_queue(stack_t **stack_head, int num)
{
	stack_t *added_node, *hs;

	hs = *stack_head;
	added_node = malloc(sizeof(stack_t));
	if (added_node == NULL)
	{
		printf("Error\n");
	}
	added_node->n = num;
	added_node->next = NULL;
	if (hs)
	{
		while (hs->next)
			hs = hs->next;
	}
	if (!hs)
	{
		*stack_head = added_node;
		added_node->prev = NULL;
	}
	else
	{
		hs->next = added_node;
		added_node->prev = hs;
	}
}
