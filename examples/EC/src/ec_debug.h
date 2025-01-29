#include "ec.h"


#ifndef EC_DEBUG_H
#define EC_DEBUG_H

#ifndef EC_MSG_WIDTH
#define EC_MSG_WIDTH 80
#endif

void
EC_Debug_Print_Adr (char *msg, void *adr);

#define EC_DEBUG_PRINT_ADR(msg, adr, line)                  \
    printf ("%-7s> %-*s %p\n", "", EC_MSG_WIDTH, msg, adr);


size_t
EC_Debug_Required_String_Size(char s[]);

#define EC_DEBUG_REQUIRED_STRING_SIZE(var)                                         \
    printf("%s: %d\nRequired size: %ld\nAlloced size : %ld\n", __FILE__, __LINE__, EC_Check_Required_String_Size(var), sizeof(var));
        
#if 0  // use to check required string size 
EC_CHECK_REQUIRED_STRING_SIZE(main_file)
#endif
    




#endif // EC_DEBUG_H
