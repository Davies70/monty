#include "monty.h"

/**
 * mod - multiply top two elements of stack
 * @stack: stack
 * @line_number: file line number
 * Return: nothing
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	int n;

	if (curr == NULL || curr->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (curr->n == 0)
	{
		fprintf(stderr, "L%d: can't div, division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = curr->next->n % curr->n;
	pop(stack, line_number);
	pop(stack, line_number);
	curr->n = n;
	curr->next = *stack;
	curr->prev = NULL;
	*stack = curr;
}

/**
 * pchar - print head of stack
 * @stack: stack
 * @line_number: file line number
 * Return: nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * pstr - print elements in stack
 * @stack: stack
 * @line_number: file line number
 * Return: nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	const stack_t *current = *stack;
	(void)line_number;

	while (current != NULL)
	{
		if (current->n > 127 || current->n <= 0)
		{
			break;
		}
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}

/**
 * rotl - rotate elements left
 * @stack: stack
 * @line_number: file line number
 * Return: nothing
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	(void)line_number;

	new_node = malloc(sizeof(stack_t));
	new_node->n = (*stack)->n;
	new_node->next = NULL;
	pop(stack, line_number);
	new_node->prev = *stack;
	while (new_node->prev != NULL)
	{
		new_node = new_node->prev;
	}
	*stack = new_node;
}

/**
 * rotr - rotate elements right
 * @stack: stack
 * @line_number: file line number
 * Return: nothing
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	stack_t *current;
	(void)line_number;

	current = *stack;
	new_node = malloc(sizeof(stack_t));
	while (current->next != NULL)
	{
		current = current->next;
	}
	new_node->n = current->n;
	new_node->prev = NULL;
    new_node->next = *stack;
	*stack = new_node;
}
