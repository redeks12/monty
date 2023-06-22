#include "monty.h"

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
                printf("%s\n", buff);
        }


        return (0);
}