#include "monty.h"

char *operand;

/**
 * parseFile - parses file
 * @filename: operator string
 */
void parseFile(char *filename)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	void (*operation)(stack_t**, unsigned int);
	stack_t *stack;
	char *token;
	char **tokens = malloc(256 * sizeof(char));
	int i = 0;
	unsigned int j = 1;

	stack = NULL;
	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &len, file)) != -1)
	{
		token = strtok(line, " \t\r\n\a");
		while (token != NULL)
		{
			tokens[i] = token;
			token = strtok(NULL, " \t\r\n\a");
			i++;
		}
		tokens[i] = NULL;
		operation = get_opr(tokens[0]);
		if (operation == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", j, tokens[0]);
			free(line);
			free_stack(stack);
			fclose(file);

			exit(EXIT_FAILURE);
		}
		operand = tokens[1];
		operation(&stack, j);
		j++;
	}
	free(tokens);
	free(line);
	free_stack(stack);
	fclose(file);
	}

/**
 * get_opr - get operation
 * @str: operator string
 *
 * Return: function
 *
*/
void (*get_opr(char *str))(stack_t**, unsigned int)
{
	instruction_t operations[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"mul", mul},
		{"div", div_op},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	int i = 0;

	while (operations[i].opcode != NULL && strcmp((operations[i].opcode), str))
		i++;
	return (operations[i].f);
}


/**
 * isNumber - check if str is numeric
 * @str: operator string
 *
 * Return: 0 or 1
 *
*/
int isNumber(char *str)
{
	unsigned int i;

	for (i = 0; i < strlen(str); i++)
	{
		if (!isdigit((unsigned char)(str[i])))
		{
			return (0);
		}
	}
	return (1);
}

/**
 * free_stack - frees a stack_t list
 * @head: head of linked list
 */
void free_stack(stack_t *head)
{
	stack_t *current;
	stack_t *next;

	current = head;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
