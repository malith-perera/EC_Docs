#ifndef EC_TODO
#define EC_TODO

#include "ec.h"

typedef struct EC_Todo {
    char *title;
    char *work_type;
    char *assigned;
    char *description;
} EC_Todo;

void
EC_Todo_Create_File(char *argv[], char *path);

void
EC_Todo_Print_List(char *path);

void
EC_Todo_Append(int argc, char *argv[], char *path);

void
EC_Todo_Change_Title(int argc, char *argv[]);

void
EC_Todo_Discription(int argc, char *argv[]);

void
EC_Todo_Remove(char *argv[], int argc, char *path);

void
EC_Todo_Help_Options();

#endif //EC_TODO
