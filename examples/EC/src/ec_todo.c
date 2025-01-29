#include "ec_todo.h"

/* todo file structure
   total number of works to do 
   EC Todo
   -------
   Title
   Assigned
   Desctiption
 */

void
EC_Todo_Create_File(char *argv[], char *path)
{
    FILE *fptr;
    char path_file[512];
    
    sprintf(path_file, "%s%s", path, ".ec/ec_todo");

    // Open file in write mode
    fptr= fopen(path_file, "w");

    if (fptr == NULL) {
        printf("Error: Cannot open todo file in write mode.\n");
    }
    else {
        fclose(fptr);
    }
}


void
Todo_Print_Urgency_Options()
{
    printf("Urgency: [ u = urgent ] [ e = essential ] [ r = required ] [ o = optional ]\n");
}


void
Todo_Print_Type_Options()
{
    printf("Type: [ a = addition ] [ b = bugfix ]\n");
}


void
EC_Todo_Help_Options()
{
        printf("Type options:\n\n"); 
        printf("   ec todo [ \"Write something to do\" ] [ -a = Addition ] [ -b = Bugfix ]\n\n");
        printf("   Examples:\n");
        printf("      ec todo 'Write here something to add to todo list'\n");
        printf("      ec todo -a 'Write here something to add as a new addtion'\n");
        printf("      ec todo -b 'Write here something to add as a bug fix'\n");
        printf("\n");
        printf("Urgency options:\n\n"); 
        printf("   ec todo [ -u = Urgent ] [ -e = Essential ] [ -r = Required ] [ -o = Optional ]\n");
        printf("\n");
        printf("   Examples:\n");
        printf("      ec todo -u  'Wrong total calculation'     Urgent to do\n"); 
        printf("      ec todo -e  'Total isn't displayed'       Essential to do\n"); 
        printf("\n");
        printf("Combined options:\n\n");
        printf("   Examples:\n");
        printf("      ec todo -bu 'Display bug'                 Urgent bug fix\n");
        printf("      ec todo -ao 'Calculate time duration'     Optional addition\n");
}


void
EC_Todo_Print(FILE *fptr)
{
    char todo_str[512];
    char c;
    int total_todo = 0;
    char title[128];
    char color[32];
    char urgency;
    char urgency_txt[32];
    char type;
    char type_txt[322];
    int i = 0, j = 0;

    printf (" %5s%-60s%-15s%-15s%-20s\n %5s%-60s%-15s%-15s%-20s\n %5s%-60s%-15s%-15s%-20s\n",
           "", "-------------", "----------", " ---------", "----------", 
           "", "   EC Todo   ", "   Type   ", "  Urgency ", " Assigned ", 
           "", "-------------", "----------", " ---------", "----------"); 

    while ((c = fgetc(fptr)) != EOF) {
        if(c != '\n')
            todo_str[i++] = c;
        else
        {
            total_todo++;
            todo_str[i++] = '\0';

            while(todo_str[j] != '\0') {
                if (todo_str[j] != ':')
                    title[j] = todo_str[j];
                else {
                    if (todo_str[j + 1] == ';') {
                        title[j] = '\0';
                        break;
                    }
                    else {
                        title[j] = todo_str[j];
                    }
                }
                j++;
            }

            type = todo_str[j + 2];
            urgency = todo_str[j + 5];

            // Type
            if (type == 'a') {
                strcpy (type_txt, "Addition"); 
            }
            else if (type == 'b') {
                strcpy (type_txt, "Bugfix"); 
            }

            // Urgency
            if (urgency == 'u') {
                strcpy(urgency_txt, "Urgent");
                strcpy(color, "\x1B[0;31m ");
            }
            else if (urgency == 'e') {
                strcpy(urgency_txt, "Essential");
                strcpy(color, "\x1B[0;32m ");
            }
            else if (urgency == 'r') {
                strcpy(urgency_txt, "Required");
                strcpy(color, "\x1B[0;34m ");
            }
            else if (urgency == 'o') {
                strcpy(urgency_txt, "Optional");
                strcpy(color, "\x1B[0;37m ");
            }
 
            printf(" %-5d %-60s%-15s%s%-15s\033[0m%-20s\n", total_todo, title, type_txt, color, urgency_txt, "No");

            strcpy(todo_str, "");
            i = j = 0;
        }
    }

    if(total_todo == 0) {

        printf(" %-5d %-60s%-15s%s%-15s\033[0m%-20s\n", total_todo, "Nothing to do ;)", "Party Type", "\x1B[1;31m", "Very Urgent", "Everyone");
        printf("\n");
        printf(" (Use \"ec -h todo\" for help)\n");
    }
}        


void
EC_Todo_Print_List(char *path)
{
    FILE *fptr;

    // Open file in read mode
    fptr = fopen(".ec/ec_todo", "r");

    if (fptr == NULL) {
        printf("Error: Cannot open todo file in read.\n");
    }
    else {
        EC_Todo_Print(fptr);
        fclose(fptr);
    }
}


char
Todo_Check_Type(char option[])
{
    int i = 1;

    while (option[i] != '\0') {
        if (option[i] == 'a')
            return 'a';
        if (option[i] == 'b')
            return 'b';
        i++;
    }


    return '\0';
}


char
Todo_Check_Urgency(char option[])
{
    int i = 1;

    while (option[i] != '\0') {
        if (option[i] == 'u')
            return 'u';
        if (option[i] == 'e')
            return 'e';
        if (option[i] == 'r')
            return 'r';
        if (option[i] == 'o')
            return 'o';
        i++;
    }

    return '\0';
}


void
EC_Todo_Append(int argc, char *argv[], char *path)
{
    FILE *fptr;
    char todo_str[512];

    char type;
    char urgency;

    char type_str[3];
    char urgency_str[3];

    static int a = 1;

    // Open file in append mode
    fptr = fopen(".ec/ec_todo", "a+");

    if (fptr == NULL) {
        printf("Error: Cannot open todo file in append mode.\n");
    }
    else {
        if (argc == 3) {
            if(argv[2][0] == '-') {
                type = Todo_Check_Type(argv[2]);
                urgency = Todo_Check_Urgency(argv[2]);

                printf("Todo: ");
                fgets(todo_str, 512, stdin);
                todo_str[strlen(todo_str) - 1] = '\0'; // remove last appended \n by fgets
            }
            else {
                strcpy(todo_str, argv[2]); 
            }

            if (type == '\0') {
                Todo_Print_Type_Options();
                printf("Type: "); 
                fgets(type_str, 3, stdin);
                printf("\n");

                type = type_str[0];
                if(type == '-' )
                    type = type_str[1];
            }

            if (urgency == '\0') {
                Todo_Print_Urgency_Options();
                printf("Urgency: "); 
                fgets(urgency_str, 3, stdin);
                printf("\n");
                
                urgency = urgency_str[0];
                if(urgency == '-' )
                    urgency = urgency_str[1];
            }

            fprintf(fptr, "%s:;%c:;%c\n", todo_str, type, urgency);
        }

        else if (argc == 4) {
            type = Todo_Check_Type(argv[2]);
            urgency = Todo_Check_Urgency(argv[2]); 

            if (type == '\0') {
                Todo_Print_Type_Options();
                printf("Type: "); 
                scanf("%s", type_str);
                printf("\n");
                type = type_str[0];
            }

            if (urgency == '\0') {
                Todo_Print_Urgency_Options();
                printf("Urgency: "); 
                scanf("%s", urgency_str);
                printf("\n");
                urgency = urgency_str[0];
            }

            fprintf(fptr, "%s:;%c:;%c\n", argv[3], type, urgency);
        }
        else {
            printf ("Unknown number of arguments\n");
            return;
        }

        fseek(fptr, 0, SEEK_SET);
        EC_Todo_Print(fptr);

        fclose(fptr);
    }
}


void
EC_Todo_Change_Title(int argc, char *argv[])
{
    FILE *fptr, *fptr2;
    char c;
    int i = 0, j = 0;
    int current_todo_line = 1;
    int change_line = 0;
    char todo_str[1024];
    char new_todo_str[512];
    char type = '\0';
    char urgency = '\0';

    if (argc == 3) {
        printf("Line Number: ");
        scanf("%d", &change_line);

        EC_Flush();

        printf("Todo: ");
        fgets(new_todo_str, 512, stdin);
        new_todo_str[strlen(new_todo_str) - 1] = '\0';
    }
    else if (argc == 4) {
        change_line = atoi(argv[3]);

        printf("Todo: ");
        fgets(new_todo_str, 512, stdin);
        new_todo_str[strlen(new_todo_str) - 1] = '\0';
    }
    else if (argc == 5) {
        change_line = atoi(argv[3]);
        strcpy(new_todo_str, argv[4]);
    }
    else {
        printf ("Unknown amount of arguments\n");
    }

    fptr = fopen(".ec/ec_todo", "r");
    fptr2 = fopen(".ec/ec_todo.tmp", "w");

    if (fptr != NULL && fptr2 != NULL) {
        while ((c = fgetc(fptr)) != EOF) {
            if(c != '\n')
                todo_str[i++] = c;
            else {
                if(current_todo_line == change_line) {
                    while (todo_str[j] != '\0') {
                        if (todo_str[j] == ':') {
                            j += 2;
                            type = todo_str[j];
                            j += 3;
                            urgency = todo_str[j];
                        }
                        j++;
                    }
                    sprintf(todo_str, "%s:;%c:;%c", new_todo_str, type, urgency);
                    j = 0;
                }
                else
                    todo_str[i++] = '\0';

                fprintf(fptr2, "%s\n", todo_str);

                current_todo_line++;
                strcpy(todo_str, "");
                i = 0;
            }
        }
        fclose(fptr);
        fclose(fptr2);
    }
    else {
        printf("Error: Todo_Change Cannot open todo file in write mode.\n");
    }

    fptr = fopen(".ec/ec_todo", "w");
    fptr2 = fopen(".ec/ec_todo.tmp", "r");

    if (fptr != NULL && fptr2 != NULL) {
        while ((c = fgetc(fptr2)) != EOF)
            fputc(c, fptr);

        fseek(fptr2, 0, SEEK_SET);

        EC_Todo_Print(fptr2);

        fclose(fptr);
        fclose(fptr2);
    }
    else {
        printf ("Error: could not update ec_todo file\n");
    }
}


void
EC_Todo_Discription(int argc, char *argv[])
{
    char id[32];

    printf("EC Todo Description\n");

    printf("Enter EC ID to assign or 'q' to quit\n");
    printf("Enter : ");
    scanf("%s", id);

    if( id[0] != 'q') {
        printf ("view %d\n", atoi(id));
    }
}

void
EC_Todo_Remove(char *argv[], int argc, char *path)
{
    FILE *fptr, *fptr2;
    char c;
    int urgency = 0;
    int i = 0;
    int current_todo_line = 1;
    int remove_line = 0;
    char todo_str[512];

    if (argc == 3) {
        printf ("Remove todo: ");
        scanf("%d", &remove_line);
        printf ("\n");
    }
    else if (argc == 4) {
        remove_line = atoi(argv[3]);
    }
    else {
        printf ("Unknown removing option\n");
        return;
    }

    fptr = fopen(".ec/ec_todo", "r");
    fptr2 = fopen(".ec/ec_todo.tmp", "w");

    if (fptr != NULL && fptr2 != NULL) {
        while ((c = fgetc(fptr)) != EOF) {
            if(c != '\n')
                todo_str[i++] = c;
            else {
                if(current_todo_line == remove_line) {
                    strcpy(todo_str, "");
                    i = 0;
                    current_todo_line++;
                    continue;
                }

                current_todo_line++;
                todo_str[i++] = '\0';
                fprintf(fptr2, "%s\n", todo_str);
                strcpy(todo_str, "");
                i = 0;
            }
        }
        fclose(fptr);
        fclose(fptr2);
    }
    else {
        printf("Error: Todo_Remove Cannot open todo file in write mode.\n");
    }

    fptr = fopen(".ec/ec_todo", "w");
    fptr2 = fopen(".ec/ec_todo.tmp", "r");

    if (fptr != NULL && fptr2 != NULL) {
        while ((c = fgetc(fptr2)) != EOF)
            fputc(c, fptr);

        fseek(fptr2, 0, SEEK_SET);

        EC_Todo_Print(fptr2);

        fclose(fptr);
        fclose(fptr2);
    }
    else {
        printf ("Error: could not update ec_todo file\n");
    }
}
