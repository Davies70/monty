#include "monty.h"

/**
 * add - add top two elements of stack
 * @stack: stack
 * @line_number: file line number
 * Return: nothing
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	int n;

	if (curr == NULL || curr->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	n = curr->next->n + curr->n;
	pop(stack, line_number);
	pop(stack, line_number);
	curr->n = n;
	curr->next = *stack;
	curr->prev = NULL;
	*stack = curr;
}

/**
 * nop - do nothing
 * @stack: stack
 * @line_number: file line number
 * Return: nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)*stack;
}

/**
 * sub - subtract top two elements of stack
 * @stack: stack
 * @line_number: file line number
 * Return: nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	int n;

	if (curr == NULL || curr->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	n = curr->next->n - curr->n;
	pop(stack, line_number);
	pop(stack, line_number);
	curr->n = n;
	curr->next = *stack;
	curr->prev = NULL;
	*stack = curr;
}

/**
 * div_op - divide top two elements of stack
 * @stack: stack
 * @line_number: file line number
 * Return: nothing
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	int n;

	if (curr == NULL || curr->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	if (curr->n == 0)
	{
		fprintf(stderr, "L%d: can't div, division by zero\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	n = curr->next->n / curr->n;
	pop(stack, line_number);
	pop(stack, line_number);
	curr->n = n;
	curr->next = *stack;
	curr->prev = NULL;
	*stack = curr;
}


/**
 * mul - multiply top two elements of stack
 * @stack: stack
 * @line_number: file line number
 * Return: nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	int n;

	if (curr == NULL || curr->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	n = curr->next->n * curr->n;
	pop(stack, line_number);
	pop(stack, line_number);
	curr->n = n;
	curr->next = *stack;
	curr->prev = NULL;
	*stack = curr;
}
