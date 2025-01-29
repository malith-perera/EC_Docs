#ifndef __EC_STACK_H__
#define __EC_STACK_H__

#include "ec.h"

#define for_stack(stack)                                                                                                                                \
    for (stack->stack_var = stack->first, stack->var = stack->stack_var != NULL ? stack->stack_var->var: NULL;                                          \
         stack->stack_var != NULL;                                                                                                                      \
         stack->stack_var = stack->stack_var != NULL ? stack->stack_var->next: NULL, stack->var = stack->stack_var != NULL ? stack->stack_var->var: NULL)

/* Function name macros */
#define EC_STACK_VAR_FREE_FUNCTION_NAME(TYPE)           EC_CONCAT(TYPE, _Stack_Var_Free)
#define EC_STACK_FREE_FUNCTION_NAME(TYPE)               EC_CONCAT(TYPE, _Stack_Free)
#define EC_STACK_NEW_FUNCTION_NAME(TYPE)                EC_CONCAT(TYPE, _Stack)
#define EC_STACK_NEW_VAR_FUNCTION_NAME(TYPE)            EC_CONCAT(TYPE, _Stack_Var)
#define EC_STACK_COPY_FUNCTION_NAME(TYPE)               EC_CONCAT(TYPE, _Stack_Copy)

#define EC_STACK_PUSH_FUNCTION_NAME(TYPE)               EC_CONCAT(TYPE, _Push)
#define EC_STACK_POP_FUNCTION_NAME(TYPE)                EC_CONCAT(TYPE, _Pop)
#define EC_STACK_SORT_FUNCTION_NAME(TYPE, SW)           EC_CONCAT4(Sort_, TYPE, _Stack_With_, SW)

/* Structure macros */
// defined in ec_memory.h

#define EC_STACK_STRUCT(TYPE)                   EC_CONCAT(TYPE, Stack)
#define EC_STACK_VAR_STRUCT(TYPE)               EC_CONCAT(TYPE, StackVar)




/* Function prototype macros */

#define EC_STACK_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)  \
void                                                \
EC_STACK_VAR_FREE_FUNCTION_NAME(TYPE)               \
(                                                   \
    EC_STACK_STRUCT(TYPE) *stack                    \
);


#define EC_STACK_FREE_FUNCTION_PROTOTYPE(TYPE)      \
void                                                \
EC_STACK_FREE_FUNCTION_NAME(TYPE)                   \
(                                                   \
    void *var                                       \
);


#define EC_STACK_NEW_FUNCTION_PROTOTYPE(TYPE)       \
EC_STACK_STRUCT(TYPE) *                             \
EC_STACK_NEW_FUNCTION_NAME(TYPE)                    \
();


#define EC_STACK_NEW_VAR_FUNCTION_PROTOTYPE(TYPE)   \
EC_STACK_VAR_STRUCT(TYPE) *                         \
EC_STACK_NEW_VAR_FUNCTION_NAME(TYPE)                \
();


#define EC_STACK_PUSH_FUNCTION_PROTOTYPE(TYPE)      \
void                                                \
EC_STACK_PUSH_FUNCTION_NAME(TYPE)                   \
(                                                   \
    EC_STACK_STRUCT(TYPE)   *stack,                 \
    TYPE                    *var                    \
);


#define EC_STACK_POP_FUNCTION_PROTOTYPE(TYPE)       \
EC_STACK_VAR_STRUCT(TYPE) *                         \
EC_STACK_POP_FUNCTION_NAME(TYPE)                    \
(                                                   \
    EC_STACK_STRUCT(TYPE) *stack                    \
);


#define EC_STACK_COPY_FUNCTION_PROTOTYPE(TYPE)      \
EC_STACK_STRUCT(TYPE) *                             \
EC_STACK_COPY_FUNCTION_NAME(TYPE)                   \
(                                                   \
    EC_STACK_STRUCT(TYPE) *stack                    \
);


#define EC_STACK_H(TYPE)                            \
    typedef struct EC_STACK_VAR_STRUCT(TYPE) {      \
        TYPE                                *var;   \
        struct EC_STACK_VAR_STRUCT(TYPE)    *next;  \
    } EC_STACK_VAR_STRUCT(TYPE);                    \
                                                    \
    typedef struct EC_STACK_STRUCT(TYPE) {          \
        EC_STACK_VAR_STRUCT(TYPE)   *first;         \
        TYPE                        *var;           \
        EC_STACK_VAR_STRUCT(TYPE)   *stack_var;     \
        EC_MEMORY_REF                               \
    } EC_STACK_STRUCT(TYPE);                        \
                                                    \
    EC_STACK_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)      \
    EC_STACK_FREE_FUNCTION_PROTOTYPE(TYPE)          \
    EC_STACK_NEW_FUNCTION_PROTOTYPE(TYPE)           \
    EC_STACK_NEW_VAR_FUNCTION_PROTOTYPE(TYPE)       \
    EC_STACK_PUSH_FUNCTION_PROTOTYPE(TYPE)          \
    EC_STACK_POP_FUNCTION_PROTOTYPE(TYPE)           \
    EC_STACK_COPY_FUNCTION_PROTOTYPE(TYPE)


/* Function macros */
#define EC_STACK_VAR_FREE_FUNCTION(TYPE)            \
void                                                \
EC_STACK_VAR_FREE_FUNCTION_NAME(TYPE)               \
(                                                   \
    EC_STACK_STRUCT(TYPE) *stack                    \
)                                                   \
{                                                   \
    EC_STACK_VAR_STRUCT(TYPE) *temp;                \
    if (stack->first != NULL)                       \
    {                                               \
        temp = stack->first;                        \
        stack->first = stack->first->next;          \
        free (temp);                                \
    }                                               \
}


/******* stack free functions not finished yet */
#define EC_STACK_FREE_FUNCTION(TYPE)                            \
void                                                            \
EC_STACK_FREE_FUNCTION_NAME(TYPE)                               \
(                                                               \
    void *stack                                                 \
)                                                               \
{                                                               \
    EC_STACK_STRUCT(TYPE) *s = (EC_STACK_STRUCT(TYPE)*) stack;  \
}


#define EC_STACK_NEW_FUNCTION(TYPE)                                     \
EC_STACK_STRUCT(TYPE) *                                                 \
EC_STACK_NEW_FUNCTION_NAME(TYPE)                                        \
()                                                                      \
{                                                                       \
    EC_VAR_CREATE(EC_STACK_STRUCT(TYPE), new_stack, __LINE__)                     /*TYPE *var is in this macro in ec_var.h*/\
                                                                        \
    return new_stack;                                                   \
}


/* New Stack Variable Method */
#define EC_STACK_NEW_VAR_FUNCTION(TYPE)              \
EC_STACK_VAR_STRUCT(TYPE) *                          \
EC_STACK_NEW_VAR_FUNCTION_NAME(TYPE)                 \
()                                                   \
{                                                    \
                                                     \
}


#define EC_STACK_PUSH_FUNCTION(TYPE)                \
void                                                \
EC_STACK_PUSH_FUNCTION_NAME(TYPE)                   \
(                                                   \
    EC_STACK_STRUCT(TYPE)   *stack,                 \
    TYPE                    *var                    \
)                                                   \
{                                                   \
    EC_VAR_CREATE(EC_STACK_VAR_STRUCT(TYPE), stack_var, __LINE__);    \
    stack_var->var = var;                           \
    stack_var->next = stack->first;                 \
    stack->first = stack_var;                       \
}


#define EC_STACK_POP_FUNCTION(TYPE)                 \
EC_STACK_VAR_STRUCT(TYPE) *                         \
EC_STACK_POP_FUNCTION_NAME(TYPE)                    \
(                                                   \
    EC_STACK_STRUCT(TYPE) *stack                    \
)                                                   \
{                                                   \
    if (stack->first == NULL)                       \
    {                                               \
        return NULL;                                \
    }                                               \
                                                    \
    EC_STACK_VAR_STRUCT(TYPE) *pop_var = stack->first; \
    stack->first = stack->first->next;              \
                                                    \
    return pop_var;                                 \
}


// Copy stack
#define EC_STACK_COPY_FUNCTION(TYPE)                                        \
EC_STACK_STRUCT(TYPE) *                                                     \
EC_STACK_COPY_FUNCTION_NAME(TYPE)                                           \
(                                                                           \
    EC_STACK_STRUCT(TYPE) *stack                                            \
)                                                                           \
{                                                                           \
    EC_STACK_STRUCT(TYPE) *stack_copy = EC_STACK_NEW_FUNCTION_NAME(TYPE)(); \
    EC_STACK_STRUCT(TYPE) *stack_temp = EC_STACK_NEW_FUNCTION_NAME(TYPE)(); \
                                                                            \
    EC_STACK_VAR_STRUCT(TYPE) *var;                                         \
                                                                            \
    for_stack(stack)                                                        \
    {                                                                       \
        EC_STACK_PUSH_FUNCTION_NAME(TYPE)(stack_temp, stack->var);          \
    }                                                                       \
                                                                            \
    for_stack(stack_temp)                                                   \
    {                                                                       \
        EC_STACK_PUSH_FUNCTION_NAME(TYPE)(stack_copy, stack_temp->var);     \
    }                                                                       \
                                                                            \
    return stack_copy;                                                      \
}


#define EC_STACK_C(TYPE)                    \
    EC_STACK_VAR_FREE_FUNCTION(TYPE)        \
    EC_STACK_FREE_FUNCTION(TYPE)            \
    EC_STACK_NEW_FUNCTION(TYPE)             \
    EC_STACK_NEW_VAR_FUNCTION(TYPE)         \
    EC_STACK_PUSH_FUNCTION(TYPE)            \
    EC_STACK_POP_FUNCTION(TYPE)             \
    EC_STACK_COPY_FUNCTION(TYPE)


#define EC_STACK(TYPE) 		\
	EC_STACK_H(TYPE) 		\
	EC_STACK_C(TYPE)

#endif // __EC_STACK_H__


/*-------------------------------------------------------------------------------------*
 *                                  Stack Drop Method                                  *
 *=====================================================================================*/

//void
//EC_STACK_DROP_FUNCTION_NAME(TYPE)
//(
    //EC_STACK_STRUCT(TYPE) *list,
    //EC_STACK_VAR_STRUCT(TYPE) *item
//)
//{
    //if (item == list->first)  // drop the first item in the list
    //{
        //if (item->next == NULL)
        //{
            //list->first = NULL;
        //}
        //else
        //{
            //item->next->previous  = NULL;
            //list->first = item->next;
        //}
    //}
    //else if (item == list->last) // drop the last item in the list
    //{
        //item->previous->next = NULL;
    //}
    //else
    //{
        //item->previous->next = item->next;
        //item->next->previous = item->previous;
    //}
//}


/*-------------------------------------------------------------------------------------*
 *                                  Stack Free Variable Method                         *
 *=====================================================================================*/

//void
//EC_STACK_FREE_VAR_FUNCTION_NAME(TYPE)
//(
    //EC_STACK_STRUCT(TYPE) *list,
    //EC_STACK_VAR_STRUCT(TYPE) *item
//)
//{
    //EC_STACK_DROP_FUNCTION_NAME(TYPE) (list, item);
    //free (item);
//}


/*-------------------------------------------------------------------------------------*
 *                                  Stack Free Stack Method                            *
 *=====================================================================================*/

/*void*/
//EC_STACK_FREE_STACK_FUNCTION_NAME(TYPE)
//(
  //void *list_ptr
//)
//{
  //EC_STACK_STRUCT(TYPE) **list;

  //*list = (EC_STACK_STRUCT(TYPE) *) list_ptr;

  //EC_STACK *current, *temp;

  //current = *(*list)->first;

  //while (current != NULL)
  //{
    //temp = current;
    //current = current->next;
    //free (temp);
    //temp = NULL;
  //}
//}
