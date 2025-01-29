#ifndef EC_WARN_H
#define EC_WARN_H

#include "ec.h"

#define EC_GET_VAR_NAME(ec_var_name)  #ec_var_name

void
EC_Warn_Print_Msg (char *test, char *result, int line);


void
EC_Warn_Print_Adr (char *msg, void *adrs);


#define EC_UNLOCK_FUNCTION(TYPE)                \
void                                            \
EC_UNLOCK_FUNCTION_NAME(TYPE)                   \
(                                               \
    void *var                                   \
)                                               \
{                                               \
    TYPE *v = (TYPE *) var;                     \
    v->ec_mem->lock = EC_UNLOCK;                \
}


#define EC_Warn_List_Var_Not_Exist(ec_var_name, ec_list_name) \
    EC_Set_Text_Color(stdout, EC_LIGHTRED);     \
    printf ("Warning: ");                       \
    printf ("\033[0m");                         \
    printf ("list variable %s is not exist in %s\n list", EC_GET_VAR_NAME (ec_var_name), EC_GET_VAR_NAME (ec_list_name));


#define EC_WARN_PRINT_MSG(msg, result)                  \
    printf ("%-7d: %-80s ", __LINE__, msg);             \
    EC_Set_Text_Color(stdout, EC_YELLOW);               \
    printf ("%s\n", result);                            \
    printf("\033[0m");


#ifdef EC_WARN

#define EC_WARN_PRINT_ADR_MACRO(msg, adr)       \
    EC_Warn_Print_Adr (msg, adr);

#define EC_WARN_PRINT_MSG_MACRO(msg, result)    \
    EC_Warn_Print_Msg (msg, result);

#else

#define EC_WARN_PRINT_ADR_MACRO(msg, adr)
#define EC_WARN_PRINT_MSG_MACRO(msg, result)

#endif


/*#define getName(var, str)  sprintf(str, "%s", #var)*/
/*char str[20];*/
/*getName(myVar, str);*/
/*printf("%s", str)*/


#endif // EC_WARN_H
