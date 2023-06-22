#include "monty.h"


int line_num = 1;

int main(int ac, char **av)
{
        FILE *fl;
        char buff[256];
        char *code;
        int bs;
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
                code = strtok(buff, " \t\n");
                if (strcmp(code, "push") == 0)
                {
                        code = strtok(NULL," \t\n");

                        bs = atoi(code);
                        if (!bs)
                        {
                                fprintf(stderr,"L%d: usage: push integer\n", line_num);
                                exit(EXIT_FAILURE);
                        }
                        push(bs);
                }
                else if (strcmp(code, "pall") == 0)
                        pall();
                line_num++;                        

        }

        return (0);
}


void push(int item)
{
        stack_t *temp = malloc(sizeof(stack_t));

        if (!temp)
        {
                fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
        }

        temp->n = item;
        temp->next = top;
        top = temp;
        stack_size++;
}

void pall()
{
        stack_t *temp;
        temp = top;
        if (stack_size > 0)
        {
                while (temp)
                {
                        printf("%d\n", temp->n);
                        temp = temp->next;
                }       
        }
        
                
}
