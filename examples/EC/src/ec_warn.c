#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include "ec_warn.h"


void
EC_Warn_Print_Msg (char *msg, char *result, int line)
{
    printf ("%-50s %s\n", msg, result);
    printf ("%-7d: %-*s ", line, EC_MSG_WIDTH, msg);
    EC_Set_Text_Color(stdout, EC_LIGHTRED);
    printf ("%s\n", result);
    printf("\033[0m");
}


void
EC_Warn_Print_Adr (char *msg, void *adr)
{
    printf ("%-50s %p\n", msg, adr);
}
