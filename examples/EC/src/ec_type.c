#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "ec_type.h"

/* Related with ECType in ec_type.h
 * If you change anything here change it too */
char *ec_type_names[] = {
    "EC_VAR",
    "EC_ARRAY",
    "EC_LIST",
    "EC_LIST_VAR",
    "EC_QUEUE",
    "EC_QUEUE_VAR",
    "EC_STACK",
    "EC_STACK_VAR"
};


/* Return ECVarType in string
 * ECType type defined in ec_type.h*/
char*
EC_Type_Get_Name (ECType type)
{
    return ec_type_names[type];
}



int32_t*
ec_int(int32_t val)
{
    int32_t *var =  (int32_t*) malloc (sizeof(int32_t));
    *var = val;

    return var;
}
/*i32 *x = ec_int(6);*/

