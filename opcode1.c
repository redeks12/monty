#include "monty.h"

void pint(stack_t **stack, unsigned int line_number)
{
        (void)line_number;
        (void)stack;
        if (stack_size <= 0)
        {
                fprintf(stderr, "L%d: can't pint, stack empty", line_num);
                exit(EXIT_FAILURE);
        }
        printf("%d\n", top->n);
}