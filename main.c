#include "monty.h"

int stack_size = 0;
int line_num = 1;
stack_t *top = NULL;

int main(int ac, char **av)
{
        FILE *fl;
        char buff[256];

        if (ac != 2)
        {
                fprintf(stderr, "USAGE: monty file\n");
                exit(EXIT_FAILURE);
        }
        fl = fopen(av[1], "r");
        if (!fl)
        {
                fprintf(stderr, "Error: Can't open file %s\n", av[1]);
                exit(EXIT_FAILURE);       
        }

        while(fgets(buff, sizeof(buff), fl))
        {
                execute(buff);
                line_num++;                        
        }
        free(top);
        return (0);
}


void push(stack_t **stack, unsigned int line_number)
{
        stack_t *temp = malloc(sizeof(stack_t));

        (void) line_number;
        (void) stack;
        if (!temp)
        {
                fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }

        temp->n = line_number;
        temp->next = top;
        top = temp;
        stack_size++;
}

void pall(stack_t **stack, unsigned int line_number)
{
        stack_t *temp;
        temp = top;

        (void) line_number;
        (void) stack;
        if (stack_size > 0)
        {
                while (temp)
                {
                        printf("%d\n", temp->n);
                        temp = temp->next;
                }       
        }
        
                
}

void execute(char *buffer)
{
        char *code;
        int i = 0, ra;      

        instruction_t opps[] = {{"push", push},
                                {"pall", pall},
                                {"pint", pint},
                                {NULL, NULL}};
        code = strtok(buffer, " \t\n");

        while(opps[i].opcode)
        {
                if (!strcmp(opps[i].opcode, code))
                {
                        if (strcmp(opps[i].opcode, "push") == 0)
                        {
                                code = strtok(NULL, " \t\n");
                                ra = atoi(code);
                                if (!ra)
                                {
                                        fprintf(stderr,"L%d: usage: push integer\n", line_num);
                                        exit(EXIT_FAILURE);
                                }
                                opps[i].f(&top, ra);
                        }
                        else
                        {
                               opps[i].f(&top, ra); 
                        }

                }
                i++;
        }
}
