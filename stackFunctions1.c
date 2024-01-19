#include "monty.h"

/**
 * AddToStack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @line: Interger representing the line number of of the opcode.
 */
void AddToStack(stack_t **new_node, __attribute__((unused)) unsigned int line)
{
	stack_t *temp;

	if (*new_node == NULL || new_node == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	head = *new_node;
	(*new_node)->prev = NULL;
	(*new_node)->next = temp;
	temp->prev = *new_node;
}

/**
 * printStack - prints all stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNum: line number of  the opcode.
 */
void printStack(stack_t **stack, unsigned int lineNum)
{
	stack_t *temp;

	(void)lineNum;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * popTop - Adds a node to the stack.
 * @stack_head: Pointer to a pointer pointing to top node of the stack.
 * @lineNum: Interger representing the line number of of the opcode.
 */
void popTop(stack_t **stack_head, unsigned int lineNum)
{
	stack_t *temp;

	if (stack_head == NULL || *stack_head == NULL)
		print_more_err(7, lineNum);

	temp = *stack_head;
	*stack_head = temp->next;
	if (*stack_head != NULL)
		(*stack_head)->prev = NULL;
	free(temp);
}

/**
 * printTop - Prints the top node of the stack.
 * @stack_head: Pointer to a pointer pointing to top node of the stack.
 * @lineNum: Interger representing the line number of of the opcode.
 */
void printTop(stack_t **stack_head, unsigned int lineNum)
{
	if (stack_head == NULL || *stack_head == NULL)
		print_more_err(6, lineNum);
	printf("%d\n", (*stack_head)->n);
}
