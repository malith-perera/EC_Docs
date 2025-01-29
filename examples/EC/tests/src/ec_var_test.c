#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "ec_var_test.h"
#include "ec_var.h"


/* Test: Type_Var(Type = any time ex: Student_Var)
 * Creating and accessing a new variable */
void
Test_Type_Var()
{
    EC_Error_Print_Msg("Test_Type_Var: ", "BEGIN");

    Student *st = Student_New();
    EC_Error_Print_Msg("Create ec var", "OK");

    st->no = 1;
    st->name = "Malith";
    EC_Error_Print_Msg("Assign ec var", "OK");

    assert(st->no == 1);
    assert(strcmp(st->name, "Malith") == 0);
    EC_Error_Print_Msg("Access variables", "OK");

    EC_Error_Print_Msg("Test_Type_Var:", "END");
}


/* Test: Local_Var 
 * Creating and accessing local variables */
void
Test_Local_Var()
{
    EC_Error_Print_Msg("Test_Local_Var: ", "BEGIN");

    Student st_local;
    EC_Error_Print_Msg("Create local ec var", "OK");

    st_local.no = 2;
    st_local.name = "Geethike";
    EC_Error_Print_Msg("Assign local ec var", "OK");

    assert(st_local.no == 2);
    assert(strcmp(st_local.name, "Geethike") == 0);
    EC_Error_Print_Msg("Access variables", "OK");

    EC_Error_Print_Msg("Test_Local_Var:", "END");
}


/* Test: Var copy without functions
 * This function should not affect copied vars each other */
void
Test_Var_Copy_Default()
{
    EC_Error_Print_Msg("Test_Var_Copy_Default: ", "BEGIN");

    StudentVar *st1 = Student_New();
    StudentVar *st2 = Student_New();
    EC_Error_Print_Msg("Create new ec var", "OK");

    st1->no = 1;
    st1->name = "Malith";
    EC_Error_Print_Msg("Assign new ec var", "OK");

    *st2 = *st1;

    assert(st2->no == 1);
    assert(strcmp(st2->name, "Malith") == 0);
    EC_Error_Print_Msg("Var copied: ", "OK");

    st1->no = 2;
    st2->name = "Geethike";

    assert(st2->no == 1);
    assert(strcmp(st1->name, "Geethike") != 0);

    EC_Error_Print_Msg("Changing one var should not affect other", "OK");

    StudentVar st_local;
    st_local.no = 3;
    st_local.name = "Perera";

    EC_Error_Print_Msg("Create and assign local var", "OK");

    *st2 = st_local;
    assert(st2->no == 3);
    assert(strcmp(st2->name, "Perera") == 0);

    EC_Error_Print_Msg("Copy local var: ", "OK");

    st_local = *st1;
    assert(st_local.no == 2);
    assert(strcmp(st_local.name, "Malith") == 0);

    EC_Error_Print_Msg("Copy var to local variable: ", "OK");

    EC_Error_Print_Msg("Test_Var_Copy_Default: ", "END");
}


/* Test: Var_Copy
 * This function should not affect copied vars each other */
void
Test_Var_Copy()
{
    EC_Error_Print_Msg("Test_Var_Copy: ", "BEGIN");

    StudentVar *st1 = Student_New();
    st1->no = 1;
    st1->name = "Malith";
    EC_Error_Print_Msg("Create and assign new ec var", "OK");

    StudentVar *st2 = Student_New();
    Student_Copy(st2, st1);
    EC_Error_Print_Msg("Var copied: ", "OK");

    assert(st2->no == 1);
    assert(strcmp(st2->name, "Malith") == 0);
    EC_Error_Print_Msg("Var copy access: ", "OK");

    st1->no = 2;
    st2->name = "Geethike";

    assert(st2->no != 2);
    assert(strcmp(st1->name, "Geethike") != 0);
    EC_Error_Print_Msg("Changing one var should not affect other", "OK");

    StudentVar st_local;
    st_local.no = 3;
    st_local.name = "Perera";
    EC_Error_Print_Msg("Create and assign local var", "OK");

    Student_Copy(st2, &st_local);
    assert(st2->no == 3);
    assert(strcmp(st2->name, "Perera") == 0);
    EC_Error_Print_Msg("Copy local var: ", "OK");

    Student_Copy(&st_local, st1);
    assert(st_local.no == 2);
    assert(strcmp(st_local.name, "Malith") == 0);
    EC_Error_Print_Msg("Copy var to local variable: ", "OK");

    EC_Error_Print_Msg("Test_Copy: ", "END");
}


/* Test: Var_Clone
 * This function should not affect copied vars each other */
void
Test_Var_Clone()
{
    EC_Error_Print_Msg("Test_Var_Clone: ", "BEGIN");

    StudentVar *st1 = Student_New();
    EC_Error_Print_Msg("Create new ec var", "OK");

    st1->no = 1;
    st1->name = "Malith";

    StudentVar *st2 = Student_Clone(st1);
    assert(st2->no == 1);
    assert(strcmp(st2->name, "Malith") == 0);
    EC_Error_Print_Msg("Var cloned: ", "OK");

    st2->no = 2;
    st2->name = "Geethike";
    assert(st2->no == 2);
    assert(strcmp(st1->name, "Geethike") != 0);
    EC_Error_Print_Msg("Changing one var should not affect other", "OK");

    StudentVar st_local;
    st_local.no = 3;
    st_local.name = "Perera";
    EC_Error_Print_Msg("create and assign local var", "OK");

    st2 = Student_Clone(&st_local);
    assert(st2->no == 3);
    assert(strcmp(st2->name, "Perera") == 0);
    EC_Error_Print_Msg("Clone local var: ", "OK");

    st_local = *Student_Clone(st1);
    assert(st_local.no == 1);
    assert(strcmp(st_local.name, "Malith") == 0);
    EC_Error_Print_Msg("Clone var to local variable: ", "OK");

    EC_Error_Print_Msg("Test_Var_Clone: ", "END");
}


void
Run_Var_Test()
{
    printf("--------------\n");
    printf("Test: ec_var.h\n");
    printf("==============\n");

    Test_Type_Var();
    printf("\n");

    Test_Local_Var();
    printf("\n");

    Test_Var_Copy_Default();
    printf("\n");

    Test_Var_Copy();
    printf("\n");

    Test_Var_Clone();
    printf("\n");

    //Test_Var_Free();
    //printf("\n");

    /*Test_Var_Unlock();*/
    /*printf("\n");*/

    /*Test_Var_Free_Unlocked();*/
    /*printf("\n");*/

    EC_Test_Print_Msg("Test: ec_var.h", "PASS", __LINE__);
    printf("\n");
}
