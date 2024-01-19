#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fileOpen(argv[1]);
	freeNodes();
	return (0);
}

/**
 * createNode - Creates a new node.
 * @data: data to insert to node.
 * Return: in sucess : pointer to the node. Otherwise: NULL.
 */
stack_t *createNode(int data)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		print_error(4);
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = data;
	return (new_node);
}

/**
 * freeNodes - free all the nodes in the stack.
 */
void freeNodes(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}


/**
 * AddToQueue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void AddToQueue(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *new_node;
	(*new_node)->prev = temp;

}
