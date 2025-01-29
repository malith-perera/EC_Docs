#include "ec_macro_test.h"


void
Test_Args()
{
    /* check for arg tests */
    assert (EC_COUNT_ARGS() == 0);
    assert (EC_COUNT_ARGS(1) == 1);
    assert (EC_COUNT_ARGS(1, 2) == 2);
    assert (EC_COUNT_ARGS(1, 2, 3) == 3);
    assert (EC_COUNT_ARGS(1, 2, 3, 4, 5, 6, 7, 8) == 8);
    assert (EC_COUNT_ARGS(1, 2, 3, 4, 5, 6, 7, 8, 9) == 9);
    assert (EC_COUNT_ARGS(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) == 10);

    //foreach_entity(player, position, velocity, size);
}


void
Run_EC_Macro_Test ()
{
    printf ("----------------\n");
    printf ("Test: ec_macro.h\n");
    printf ("================\n");


    Test_Args();

    EC_Error_Print_Msg ("Test: ec_macro.h", "PASS");
    printf ("\n");
}
