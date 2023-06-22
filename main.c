#include "monty.h"
void readLineIgnoringWhitespace(char *line);

int main(int ac, char **av)
{
        FILE *fl;
        char *buff;
        char **code;
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
                readLineIgnoringWhitespace(buff);
                printf("%s\n", buff);
        }


        return (0);
}


void readLineIgnoringWhitespace(char *line) {
    int c;
    int i = 0;
    int leadingWhitespace = 1; // Flag to track leading whitespace
    
    // Read characters until newline or EOF is encountered
    while ((c = getchar()) != '\n' && c != EOF) {
        if (leadingWhitespace && isspace(c)) {
            // Ignore leading whitespace
            continue;
        } else {
            leadingWhitespace = 0; // Clear the flag
        }
        
        line[i] = c; // Store the character in the line
        i++;
    }
    
    line[i] = '\0'; // Null-terminate the string
}
