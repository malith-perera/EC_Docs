#ifndef __EC_VAR_H__
#define __EC_VAR_H__

#include "ec.h"
#define EC_VAR_DEBUG 1

/* Function name macros */
#define EC_VAR_NEW_FUNCTION_NAME(TYPE)          EC_CONCAT(TYPE, _New)
#define EC_VAR_FREE_FUNCTION_NAME(TYPE)         EC_CONCAT(TYPE, _Free)
#define EC_VAR_CLONE_FUNCTION_NAME(TYPE)        EC_CONCAT(TYPE, _Clone)
#define EC_VAR_COPY_FUNCTION_NAME(TYPE)         EC_CONCAT(TYPE, _Copy)

/*---------*/
/* EC Free */
/*---------*/

#ifdef EC_MEMORY

#define EC_Free(var)                            \
    var->ec_mem->lock = EC_UNLOCK;              \
    free(var)

#define EC_Free_Mem(var)                        \
    var->ec_mem->lock = EC_UNLOCK;              \
    free(var)

#else // EC_MEMORY not defined  

#define EC_Free(var)                            \
    free(var)

#define EC_Free_Mem(var)                        \
    free(var)

#endif  // EC_MEMORY 


/* Function Prototypes */
#define EC_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)    \
void                                            \
EC_VAR_FREE_FUNCTION_NAME(TYPE)                 \
(                                               \
    void *var                                   \
);


#define EC_VAR_NEW_FUNCTION_PROTOTYPE(TYPE)     \
TYPE *                                          \
EC_VAR_NEW_FUNCTION_NAME(TYPE)(void);


#define EC_VAR_CLONE_FUNCTION_PROTOTYPE(TYPE)   \
TYPE *                                          \
EC_VAR_CLONE_FUNCTION_NAME(TYPE)                \
(                                               \
    TYPE *var                                   \
);


#define EC_VAR_COPY_FUNCTION_PROTOTYPE(TYPE)    \
void                                            \
EC_VAR_COPY_FUNCTION_NAME(TYPE)                 \
(                                               \
    TYPE *var_copy,                             \
    TYPE *var                                   \
);


/* Macro functions */

#define EC_VAR_FREE_FUNCTION(TYPE)                      \
void                                                    \
EC_VAR_FREE_FUNCTION_NAME(TYPE)                         \
(                                                       \
    void *var                                           \
)                                                       \
{                                                       \
    TYPE *v =(TYPE *) var;                             	\
    EC_DEBUG_PRINT_ADR("ec var free", v, __LINE__);     \
    free(v);                                           	\
    v = NULL;                                           \
}


/* Create memory for any variable type ex: var, arry, list, list var */
#define EC_VAR_CREATE(TYPE, var, line)                      \
    TYPE *var = (TYPE *) malloc(sizeof(TYPE));             	\
	EC_Memory_Add(var);                                     \
    EC_ERROR_MEM_ALLOC(var, __FILE__, line)                 /* when memory allocation failed */\
    EC_DEBUG_PRINT_ADR("Create: ec var", var, line)         /* only when EC_DEBUG */


#define EC_VAR_NEW_FUNCTION(TYPE)                           \
TYPE *                                                      \
EC_VAR_NEW_FUNCTION_NAME(TYPE)(void)                        \
{                                                           \
    EC_VAR_CREATE(TYPE, var, __LINE__)                      /* var is created variable */\
															\
    return var;                                             \
}


// Clone variable var to var_clone
#define EC_VAR_CLONE_FUNCTION(TYPE)                         \
TYPE *                                                      \
EC_VAR_CLONE_FUNCTION_NAME(TYPE)                            \
(                                                           \
    TYPE *var                                               \
)                                                           \
{                                                           \
    TYPE *var_clone = EC_VAR_NEW_FUNCTION_NAME(TYPE)();     \
    memcpy(var_clone, var, sizeof(TYPE));                  	\
    return var_clone;                                       \
}


// Copy variable var to var_copy
#define EC_VAR_COPY_FUNCTION(TYPE)                          \
void                                                        \
EC_VAR_COPY_FUNCTION_NAME(TYPE)                             \
(                                                           \
    TYPE *var_copy,                                         \
    TYPE *var                                               \
)                                                           \
{                                                           \
    *var_copy = *var;                                       \
}


/* All function prototypes */
#define EC_VAR_H(TYPE)    \
    typedef struct TYPE EC_CONCAT(TYPE, Var);   /* optional StudentVar for Student */\
    EC_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)    	\
    EC_VAR_NEW_FUNCTION_PROTOTYPE(TYPE)     	\
    EC_VAR_CLONE_FUNCTION_PROTOTYPE(TYPE)   	\
    EC_VAR_COPY_FUNCTION_PROTOTYPE(TYPE)


/* All functions */
#define EC_VAR_C(TYPE)         			\
    EC_VAR_FREE_FUNCTION(TYPE)         	\
    EC_VAR_NEW_FUNCTION(TYPE)          	\
    EC_VAR_CLONE_FUNCTION(TYPE)        	\
    EC_VAR_COPY_FUNCTION(TYPE)


/* All prototypes and functions */
#define EC_VAR(TYPE) 					\
		EC_VAR_H(TYPE)         			\
		EC_VAR_C(TYPE)


#endif // __EC_VAR_H__
