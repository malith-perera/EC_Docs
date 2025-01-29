#include "ec_c_file_test.h"
#include "c_file.h"
#include "ec_c_file.h"


void
Test_EC_C_Fuctions() {
    char **functions = EC_C_Functions("ec_c_test.c");

    assert(strcmp(functions[0], "First_Function") == 0);
}


void
Run_C_File_Test()
{
    printf("-----------------\n");
    printf("Test: ec_c_file.c\n");
    printf("=================\n");

    Test_EC_C_Fuctions(); 
}
