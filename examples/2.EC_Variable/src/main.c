#include <stdio.h>
#include <string.h>

#include "main.h"

int main ()
{
    Student* st1 = Student_Var();

    strcpy(st1->name, "Malith");
    st1->index = 0;
    st1->grade = 5;

    Student* st2 = Student_Var();

    strcpy(st2->name, "Perera");
    st2->index = 1;
    st2->grade = 5;

    printf("%5s%10s%8s\n", "Index", "Name", "Grade");
    printf("%5d%10s%8d\n", st1->index, st1->name, st1->grade);
    printf("%5d%10s%8d\n", st2->index, st2->name, st2->grade);

    EC_Clean();

    return 0;
}
