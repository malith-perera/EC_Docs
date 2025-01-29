#include "ec.h"


#ifndef EC_ERROR_H
#define EC_ERROR_H


void
EC_Error_Print_Msg (char *test, char *result);


void
EC_Print_Error (char *msg, void *adrs);


// Memory allocation error relative macro and functions are available
// EC_ERROR_MEM_ALLOC()
// EC_Error_Mem_Alloc (__FILE__, __LINE__);


#define EC_ERROR_MEM_ALLOC(var, file, line)                                             \
    if (var == NULL) {                                                                  \
        fprintf(stderr, "Error: Cannot allocate memory in file:%s: %d\n", file, line);  \
    }

void
EC_Error_Mem_Alloc (char* file, int line);


#endif // EC_ERROR_H
