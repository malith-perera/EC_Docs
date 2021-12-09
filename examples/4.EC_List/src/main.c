#include <stdio.h>
#include <string.h>

#include "main.h"

int main ()
{
    StudentArray* sta = Student_Array(2);

    /*strcpy(sta->array[0].name, "Malith");*/
    /*sta->index[0].index = 0;*/
    /*sta->array[0].grade = 5;*/

    /*strcpy(sta->array[1].name, "Perera");*/
    /*sta->array[1].index = 1;*/
    /*sta->array[1].grade = 5;*/

/*    printf("%5s%10s%8s\n", "Index", "Name", "Grade");*/
    /*printf("%5d%10s%8d\n", sta->array[0].index, sta->array[0].name, sta->array[0].grade);*/
    /*printf("%5d%10s%8d\n", sta->array[1].index, sta->array[1].name, sta->array[1].grade);*/

    EC_Clean();

    return 0;
}
