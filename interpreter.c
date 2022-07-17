#include "monty.h"

/**
 * main - monty
 * @argc: number of arguments
 * @argv: list of command line arguments
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	parseFile(argv[1]);

	return (0);
}
