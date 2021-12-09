#include <stdio.h>
#include <string.h>

#include "main.h"

int main ()
{
    StudentArray* sta = Student_Array(2); // sta = student array

    strcpy(sta->index[0].name, "Malith");
    sta->index[0].ref_no = 0;
    sta->index[0].grade = 5;

    strcpy(sta->index[1].name, "Perera");
    sta->index[1].ref_no = 1;
    sta->index[1].grade = 5;

    printf("%s    %s     %s\n", "Index", "Name", "Grade");

    foreach_array (Student, sta)
    {
        printf("  %d     %s      %d\n", sta->index[sta->i].ref_no, sta->index[sta->i].name, sta->index[sta->i].grade);
    }

    // Or you can use
    for (int i = 0; i < sta->count; i++)
    {
        printf("  %d     %s      %d\n", sta->index[i].ref_no, sta->index[i].name, sta->index[i].grade);
    }

    EC_Clean();

    return 0;
}
