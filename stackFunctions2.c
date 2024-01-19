#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNum: Interger representing the line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int lineNum)
{
	(void)stack;
	(void)lineNum;
}


/**
 * nodes_swap - Swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNum: Interger representing the line number of of the opcode.
 */
void nodes_swap(stack_t **stack, unsigned int lineNum)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_more_err(8, lineNum, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * nodes_add - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNum: Interger representing the line number of of the opcode.
 */
void nodes_add(stack_t **stack, unsigned int lineNum)
{
	int total_sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_more_err(8, lineNum, "add");

	(*stack) = (*stack)->next;
	total_sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = total_sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * nodes_sub - subtracts the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNum: Interger representing the line number of of the opcode.
 */
void nodes_sub(stack_t **stack, unsigned int lineNum)
{
	int sub;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		print_more_err(8, lineNum, "sub");


	(*stack) = (*stack)->next;
	sub = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sub;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * nodes_divide - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNum: Interger representing the line number of of the opcode.
 */
void nodes_divide(stack_t **stack, unsigned int lineNum)
{
	int total_div;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_more_err(8, lineNum, "div");

	if ((*stack)->n == 0)
		print_more_err(9, lineNum);
	(*stack) = (*stack)->next;
	total_div = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = total_div;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
