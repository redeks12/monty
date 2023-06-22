#include "monty.h"
void pop(stack_t *stack, int item)
{
	stack_t *t;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n");
		exit(EXIT_FAILURE);
	}
}
