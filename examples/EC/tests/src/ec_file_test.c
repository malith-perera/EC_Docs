#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "ec_file_test.h"
#include "ec_file.h"

void
Test_Lines_Of_Code ()
{
    EC_Lines_Of_Code ("../testdata/ec_file_test_file1.c");
}

void
Run_File_Test ()
{
    printf ("------------------\n");
    printf ("Test: ec_file      \n");
    printf ("==================\n");

    Test_Lines_Of_Code ();
    printf ("\n");

    EC_Print_Error ("Test: ec_file", "PASS");
    printf ("\n");
}
