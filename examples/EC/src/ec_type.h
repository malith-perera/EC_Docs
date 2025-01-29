#ifndef EC_TYPE_H
#define EC_TYPE_H

/* EC defined types
 * Related with ec_type_name[] in ec_type.c
 * If you change anything here change it too */
typedef enum {
    EC_TYPE_VAR,
    EC_TYPE_ARRAY,
    EC_TYPE_LIST,
    EC_TYPE_STACK,
    EC_TYPE_QUEUE,
    EC_LIST_VAR_TYPE,
    EC_QUEUE_VAR_TYPE,
    EC_STACK_TYPE,
    EC_STACK_VAR_TYPE
} ECType;

/* portability */

//#define int32(VAR) \
    //int32_t *VAR = (int32_t*) malloc (sizeof(int32_t))
/*int32(y);*/
/**y = 7;*/


/*
#define foreach(ec_data_structure)                                                                                                                  \
  for (ec_data_structure->var = ec_data_structure->first; ec_data_structure->var != NULL; ec_data_structure->var = ec_data_structure->var->next)

*/


/* Return ECVarType in string
 * ECType type defined in ec_type.h*/
char*
EC_Type_Get_Name (ECType type);

#endif // EC_TYPE_H
