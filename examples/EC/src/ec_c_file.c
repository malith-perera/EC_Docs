#include "ec_c_file.h"
#include "ec.h"

void
Skip_Parantheses(FILE *fptr)
{
    char c;
    int paranthises_counter = 1;

    while (paranthises_counter != 0) {
        c = fgetc(fptr);

        if (c == '(' || c == '{') {
            paranthises_counter++;
        }

        if (c == ')' || c == '}') {
            paranthises_counter--;
        }
        
        if (c == EOF) {
            printf("Error: Reached end of the file without matching parantheses or braces\n");
            break;
        }
    }
}


char
Skip_Space(FILE *fptr) {
    char c;
    while ((c = fgetc(fptr)) != ' ' && c != EOF);
    return c;
}


void
Skip_Macros(FILE *fptr)
{
    char c;
    char last_char;

    c = fgetc(fptr);

    while (c != EOF) {
        if (c != '\n' && last_char != '\\')
            break;
        else {
            c = Skip_Space(fptr); // return first char after space
            last_char = c;
        }
    }
}


char **
EC_C_Functions(char *file_name)
{
    FILE *fptr;
    char c;
    char word[256] = "";
    char last_word[256] = "";
    int i = 0;
    int paranthises_counter = 0;

    fptr = fopen(file_name, "r");

    if(fptr != NULL) {
        while ((c = fgetc(fptr)) != EOF) {

            if(c == '#')
                Skip_Macros(fptr); // Skip macros
            
            if(c == ' ' || c == '(' || c == '\n') {
                word[i] = '\0';

                printf("%s", word);
                
                i = 0;

                if (c == '(')
                    Skip_Parantheses(fptr); // Skip parantheses

                c = Skip_Space(fptr);

                if (c == '{')
                    printf("%s\n", word);
                else {
                    i = 0;
                    word[i] = c;
                    i++;
                }
            }
            else {
                word[i] = c;
                i++;
            }
        }

        fclose(fptr);
    }
    else
        printf("file not found");
}
