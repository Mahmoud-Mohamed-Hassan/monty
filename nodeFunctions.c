#include "monty.h"

/**
 * nodes_mul - multiply the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNum: Interger representing the line number of of the opcode.
 */
void nodes_mul(stack_t **stack, unsigned int lineNum)
{
	int total_mul;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_more_err(8, lineNum, "mul");

	(*stack) = (*stack)->next;
	total_mul = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = total_mul;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * nodes_mod - modelus the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @lineNum: Interger representing the line number of of the opcode.
 */
void nodes_mod(stack_t **stack, unsigned int lineNum)
{
	int total_mod;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		print_more_err(8, lineNum, "mod");


	if ((*stack)->n == 0)
		print_more_err(9, lineNum);
	(*stack) = (*stack)->next;
	total_mod = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = total_mod;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
