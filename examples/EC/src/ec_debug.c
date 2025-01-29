#include "ec_debug.h"


void
EC_Debug_Print_Adr (char *msg, void *adr)
{
    printf ("%-*s %p\n", EC_MSG_WIDTH, msg, adr);
}

size_t
EC_Debug_Required_String_Size(char s[])
{
    size_t required_size = strlen(s) + 1; // + 1 for \0 charactor
    required_size += 4 - required_size % 4; // nearest word (4 byte) size

    return required_size; 
}
