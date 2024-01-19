#include "monty.h"

/**
 * fileOpen - opens a file
 * @fileName: the file namepath
 * Return: void
 */

void fileOpen(char *fileName)
{
	FILE *fd = fopen(fileName, "r");

	if (fileName == NULL || fd == NULL)
		print_error(openError, fileName);

	fileRead(fd);
	fclose(fd);
}


/**
 * fileRead - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void fileRead(FILE *fd)
{
	int lineNum, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (lineNum = 1; getline(&buffer, &len, fd) != -1; lineNum++)
	{
		format = parseLine(buffer, lineNum, format);
	}
	free(buffer);
}


/**
 * parseLine - Separates each line into tokens to determine
 * which function to call
 * @buf: line from the file
 * @lineNum: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int parseLine(char *buf, int lineNum, int format)
{
	char *opCode, *value;
	const char *delimeter = "\n ";

	if (buf == NULL)
		print_error(mallocFailed);

	opCode = strtok(buf, delimeter);
	if (opCode == NULL)
		return (format);
	value = strtok(NULL, delimeter);

	if (strcmp(opCode, "stack") == 0)
		return (0);
	if (strcmp(opCode, "queue") == 0)
		return (1);

	find_func(opCode, value, lineNum, format);
	return (format);
}

/**
 * find_func - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_func(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", AddToStack},
		{"pall", printStack},
		{"pint", printTop},
		{"pop", popTop},
		{"nop", nop},
		{"swap", nodes_swap},
		{"add", nodes_add},
		{"sub", nodes_sub},
		{"div", nodes_divide},
		{"mul", nodes_mul},
		{"mod", nodes_mod},
		{"pchar", print_character},
		{"pstr", print_string},
		{"rotl", stack_rotl},
		{"rotr", stack_rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		print_error(3, ln, opcode);
}


/**
 * call_fun - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			print_error(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				print_error(5, ln);
		}
		node = createNode(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			AddToQueue(&node, ln);
	}
	else
		func(&head, ln);
}
