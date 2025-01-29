#include <assert.h>
#include "ec_ec_test.h"

EC(Book)

void
Test_EC()
{
    EC_Test_Print_Title(__func__, __FILE__);
    EC_Test_Print_Subtitle("Test: EC(TYPE)");

    Book *book1 = Book_New();
    strcpy(book1->name, "Harry Potter");
    book1->no = 323;

    assert(strcmp(book1->name ,"Harry Potter") == 0);
    assert(book1->no == 323);

    EC_Test_Print_Msg("EC_VAR Created", "OK", __LINE__);
}

void
Run_EC_Test()
{
    printf("----------\n");
    printf("Test: ec.h\n");
    printf("==========\n");

    Test_EC();
    printf("\n");
}
