#include "monty.h"

void push( int item);
void pall();
int line_num = 0;

int main(int ac, char **av)
{
        FILE *fl;
        char buff[256];
        char *code;
        int bs;
        stack_size = 0;
        stack_t *mainstack = NULL;
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
                        push(top, bs);
                }
                else if (strcmp(code, "pall") == 0)
                        pall();
                line_num++;
                printf("%d\n", line_num);
                        

        }

        return (0);
}

// int main(void)
// {
//         stack_t *newstack = NULL;
//         push(newstack, 10);
//         push(newstack, 21);
//         push(newstack, 32);
//         push(newstack, 45);
//         pall();

// }

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
        while (temp)
        {
                printf("%d\n", temp->n);
                temp = temp->next;
        }       
}
