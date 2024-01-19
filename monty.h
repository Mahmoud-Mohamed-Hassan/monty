#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#define openError 2
#define mallocFailed 4

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void fileOpen(char *fileName);
int parseLine(char *buf, int lineNum, int format);
void fileRead(FILE *);
int len_chars(FILE *);
void find_func(char *, char *, int, int);

/*Stack operations*/
stack_t *createNode(int data);
void freeNodes(void);
void printStack(stack_t **, unsigned int);
void AddToStack(stack_t **, unsigned int);
void AddToQueue(stack_t **, unsigned int);

void call_fun(op_func, char *, char *, int, int);

void printTop(stack_t **, unsigned int);
void popTop(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void nodes_swap(stack_t **, unsigned int);

/*Math operations with nodes*/
void nodes_add(stack_t **, unsigned int);
void nodes_sub(stack_t **, unsigned int);
void nodes_divide(stack_t **, unsigned int);
void nodes_mul(stack_t **, unsigned int);
void nodes_mod(stack_t **, unsigned int);

/*String operations*/
void print_character(stack_t **, unsigned int);
void print_string(stack_t **, unsigned int);
void stack_rotl(stack_t **, unsigned int);

/*Error hanlding*/
void print_error(int errorName, ...);
void print_more_err(int errorName, ...);
void string_err(int errorName, ...);
void stack_rotr(stack_t **, unsigned int);

#endif
