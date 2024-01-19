#include "monty.h"

/**
 * print_character - Prints the ASCII value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNum: Interger representing the line number of of the opcode.
 */
void print_character(stack_t **stack, unsigned int lineNum)
{
	int ASCII;

	if (stack == NULL || *stack == NULL)
		string_err(11, lineNum);

	ASCII = (*stack)->n;
	if (ASCII < 0 || ASCII > 127)
		string_err(10, lineNum);
	printf("%c\n", ASCII);
}

/**
 * print_string - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line: Interger representing the line number of of the opcode.
 */
void print_string(stack_t **stack, __attribute__((unused))unsigned int line)
{
	int ASCII;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		ASCII = temp->n;
		if (ASCII <= 0 || ASCII > 127)
			break;
		printf("%c", ASCII);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * stack_rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line: Interger representing the line number of of the opcode.
 */
void stack_rotl(stack_t **stack, __attribute__((unused))unsigned int line)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * stack_rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line: Interger representing the line number of of the opcode.
 */
void stack_rotr(stack_t **stack, __attribute__((unused))unsigned int line)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
