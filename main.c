#include "monty.h"
void readLineIgnoringWhitespace(char line[256]);

int main(int ac, char **av)
{
        FILE *fl;
        char buff[256];
        char *code;
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

        }


        return (0);
}

