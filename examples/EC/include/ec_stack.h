#ifndef EC_STACK_H
#define EC_STACK_H

#include "ec.h"

#define foreach_stack(stack)                                                            \
  for (stack->var = stack->first;  stack->var != NULL; stack->var = stack->var->next)


/* Function name macros */

#define EC_STACK_FREE_FUNCTION_NAME(TYPE)               EC_CONCAT(TYPE, _Free, ) // memory Free
#define EC_STACK_NEW_FUNCTION_NAME(TYPE)                EC_CONCAT(TYPE, _Stack,)
#define EC_STACK_NEW_VAR_FUNCTION_NAME(TYPE)            EC_CONCAT(TYPE, _Stack_Var,)
#define EC_STACK_FOREACH(TYPE)                          EC_CONCAT(TYPE, _Foreach,)
#define EC_STACK_FREE_VAR_FUNCTION_NAME(TYPE)           EC_CONCAT(TYPE, _Free, _Stack_Var)
#define EC_STACK_PUSH_FUNCTION_NAME(TYPE)               EC_CONCAT(TYPE, _Push,)
#define EC_STACK_POP_FUNCTION_NAME(TYPE)                EC_CONCAT(TYPE, _Pop,)
#define EC_STACK_FREE_STACK_FUNCTION_NAME(TYPE)         EC_CONCAT(TYPE, _Free, _Stack)
#define EC_STACK_SORT_FUNCTION_NAME(TYPE, SW)           EC_CONCAT4(Sort_, TYPE, _Stack_With_, SW)

/* Structure macros */
// defined in ec_memory.h

#define EC_STACK_STRUCT(TYPE)                  EC_CONCAT(TYPE, Stack,)
#define EC_STACK_VAR_STRUCT(TYPE)              EC_CONCAT(TYPE, StackVar,)


#define EC_STACK(TYPE, VAR)                         \
typedef struct EC_STACK_VAR_STRUCT(TYPE){           \
    VAR                                             \
    struct EC_STACK_VAR_STRUCT(TYPE)* next;         \
} EC_STACK_VAR_STRUCT(TYPE);                        \
                                                    \
typedef struct EC_STACK_STRUCT(TYPE){               \
    EC_STACK_VAR_STRUCT(TYPE)* top;                 \
    EC_MEMORY_REF                                   \
} EC_STACK_STRUCT(TYPE);


/* Function prototype macros */

#define EC_STACK_FREE_FUNCTION_PROTOTYPE(TYPE)             \
void                                                       \
EC_STACK_FREE_FUNCTION_NAME(EC_STACK_STRUCT(TYPE))         \
(                                                          \
    void* var                                              \
);


#define EC_STACK_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)         \
void                                                       \
EC_STACK_FREE_VAR_FUNCTION_NAME(TYPE)                      \
(                                                          \
    void* var                                              \
);


#define EC_STACK_NEW_FUNCTION_PROTOTYPE(TYPE)              \
EC_STACK_STRUCT(TYPE)*                                     \
EC_STACK_NEW_FUNCTION_NAME(TYPE)                           \
();


#define EC_STACK_NEW_VAR_FUNCTION_PROTOTYPE(TYPE)           \
EC_STACK_VAR_STRUCT(TYPE)*                                  \
EC_STACK_NEW_VAR_FUNCTION_NAME(TYPE)                        \
();


#define EC_STACK_PUSH_FUNCTION_PROTOTYPE(TYPE)              \
void                                                        \
EC_STACK_PUSH_FUNCTION_NAME(TYPE)                           \
(                                                           \
    EC_STACK_STRUCT(TYPE)* stack,                           \
    EC_STACK_VAR_STRUCT(TYPE)* var                          \
);


#define EC_STACK_POP_FUNCTION_PROTOTYPE(TYPE)               \
EC_STACK_VAR_STRUCT(TYPE)*                                  \
EC_STACK_POP_FUNCTION_NAME(TYPE)                            \
(                                                           \
    EC_STACK_STRUCT(TYPE)* stack                            \
);


#define EC_STACK_FUNCTION_PROTOTYPES(TYPE)          \
    EC_STACK_FREE_FUNCTION_PROTOTYPE(TYPE)          \
    EC_STACK_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)      \
    EC_STACK_NEW_FUNCTION_PROTOTYPE(TYPE)           \
    EC_STACK_NEW_VAR_FUNCTION_PROTOTYPE(TYPE)       \
    EC_STACK_PUSH_FUNCTION_PROTOTYPE(TYPE)          \
    EC_STACK_POP_FUNCTION_PROTOTYPE(TYPE)


/* Function macros */

#define EC_STACK_FREE_FUNCTION(TYPE)                                \
void                                                                \
EC_STACK_FREE_FUNCTION_NAME(EC_STACK_STRUCT(TYPE))                  \
(                                                                   \
    void* var                                                       \
)                                                                   \
{                                                                   \
    EC_STACK_STRUCT(TYPE)* p = (EC_STACK_STRUCT(TYPE)*) var;        \
    free (p);                                                       \
}


#define EC_STACK_VAR_FREE_FUNCTION(TYPE)                            \
void                                                                \
EC_STACK_FREE_VAR_FUNCTION_NAME(TYPE)                               \
(                                                                   \
    void* var                                                       \
)                                                                   \
{                                                                   \
    TYPE* p = (TYPE*) var;                                          \
    free (p);                                                       \
}


#define EC_STACK_NEW_FUNCTION(TYPE)                                                                         \
EC_STACK_STRUCT(TYPE)*                                                                                      \
EC_STACK_NEW_FUNCTION_NAME(TYPE)                                                                            \
(                                                                                                           \
    int max                                                                                                 \
)                                                                                                           \
{                                                                                                           \
    EC_STACK_STRUCT(TYPE)* var = (EC_STACK_STRUCT(TYPE)*) malloc (sizeof (EC_STACK_STRUCT(TYPE)));          \
                                                                                                            \
    if (var == NULL)                                                                                        \
    {                                                                                                       \
        EC_ERROR_MEM_ALLOC()                                                                                \
        return NULL;                                                                                        \
    }                                                                                                       \
                                                                                                            \
    var->top = NULL;                                                                                        \
                                                                                                            \
    if (EC_MEMORY)                                                                                          \
    {                                                                                                       \
        ECMemory* ec_memory_new = (ECMemory*) malloc (sizeof(ECMemory));                                    \
                                                                                                            \
        if (ec_memory_new == NULL)                                                                          \
        {                                                                                                   \
            EC_ERROR_MEM_ALLOC()                                                                            \
            return NULL;                                                                                    \
        }                                                                                                   \
                                                                                                            \
        ec_memory_new->type = EC_STACK_TYPE;                                                                \
        ec_memory_new->var = var;                                                                           \
        ec_memory_new->memory = NULL;                                                                       \
        ec_memory_new->Free_Func = EC_STACK_FREE_FUNCTION_NAME(EC_STACK_STRUCT(TYPE));                      \
        ec_memory_new->next = NULL;                                                                         \
                                                                                                            \
        if (ec_memory != NULL)                                                                              \
        {                                                                                                   \
            ec_memory_new->next = ec_memory;                                                                \
            ec_memory = ec_memory_new;                                                                      \
        }                                                                                                   \
        else                                                                                                \
        {                                                                                                   \
            ec_memory = ec_memory_new;                                                                      \
        }                                                                                                   \
                                                                                                            \
        var->mem_ref = ec_memory_new;                                                                       \
        var->lock = true;                                                                                   \
                                                                                                            \
    return var;                                                                                             \
}


/* New Stack Variable Method */
#define EC_STACK_NEW_VAR_FUNCTION(TYPE)                                                                         \
EC_STACK_VAR_STRUCT (TYPE)*                                                                                     \
EC_STACK_NEW_VAR_FUNCTION_NAME(TYPE)                                                                            \
()                                                                                                              \
{                                                                                                               \
    EC_STACK_VAR_STRUCT(TYPE)* var = (EC_STACK_VAR_STRUCT(TYPE)*) malloc (sizeof (EC_STACK_VAR_STRUCT(TYPE)));  \
                                                                                                                \
    if (var == NULL)                                                                                            \
    {                                                                                                           \
        EC_ERROR_MEM_ALLOC()                                                                                    \
        return NULL;                                                                                            \
    }                                                                                                           \
                                                                                                                \
    if (EC_MEMORY)                                                                                              \
    {                                                                                                           \
        ECMemory* ec_memory_new = (ECMemory*) malloc (sizeof (ECMemory));                                       \
                                                                                                                \
        if (ec_memory_new == NULL)                                                                              \
        {                                                                                                       \
            EC_ERROR_MEM_ALLOC()                                                                                \
            return NULL;                                                                                        \
        }                                                                                                       \
                                                                                                                \
        ec_memory_new->type = EC_STACK_VAR_TYPE;                                                                \
        ec_memory_new->var = var;                                                                               \
        ec_memory_new->memory = NULL;                                                                           \
        ec_memory_new->Free_Func = EC_STACK_FREE_VAR_FUNCTION_NAME(TYPE);                                       \
        ec_memory_new->next = NULL;                                                                             \
                                                                                                                \
        if (ec_memory != NULL)                                                                                  \
        {                                                                                                       \
            ec_memory_new->next = ec_memory;                                                                    \
            ec_memory = ec_memory_new;                                                                          \
        }                                                                                                       \
        else                                                                                                    \
        {                                                                                                       \
            ec_memory = ec_memory_new;                                                                          \
        }                                                                                                       \
    }                                                                                                           \
                                                                                                                \
  return var;                                                                                                   \
}


#define EC_STACK_PUSH_FUNCTION(TYPE)                        \
void                                                        \
EC_STACK_PUSH_FUNCTION_NAME(TYPE)                           \
(                                                           \
    EC_STACK_STRUCT(TYPE)* stack,                           \
    EC_STACK_VAR_STRUCT(TYPE)* var                          \
)                                                           \
{                                                           \
    var->next = stack->top;                                 \
    stack->top = var;                                       \
}


#define EC_STACK_POP_FUNCTION(TYPE)                         \
EC_STACK_VAR_STRUCT(TYPE)*                                  \
EC_STACK_POP_FUNCTION_NAME(TYPE)                            \
(                                                           \
    EC_STACK_STRUCT(TYPE)* stack                            \
)                                                           \
{                                                           \
    if (stack->top == NULL)                                 \
    {                                                       \
        return NULL;                                        \
    }                                                       \
                                                            \
    EC_STACK_VAR_STRUCT(TYPE)* pop_var = stack->top;        \
    stack->top = stack->top->next;                          \
                                                            \
    return pop_var;                                         \
}


#define EC_STACK_FUNCTIONS(TYPE)            \
    EC_STACK_VAR_FREE_FUNCTION(TYPE)        \
    EC_STACK_FREE_FUNCTION(TYPE)            \
    EC_STACK_NEW_FUNCTION(TYPE)             \
    EC_STACK_NEW_VAR_FUNCTION(TYPE)         \
    EC_STACK_PUSH_FUNCTION(TYPE)            \
    EC_STACK_POP_FUNCTION(TYPE)

#endif // EC_STACK_H



/*-------------------------------------------------------------------------------------*
 *                                  Stack Drop Method                                   *
 *=====================================================================================*/

//void
//EC_STACK_DROP_FUNCTION_NAME(TYPE)
//(
    //EC_STACK_STRUCT(TYPE)* list,
    //EC_STACK_VAR_STRUCT(TYPE)* item
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
 *                                  Stack Free Variable Method                            *
 *=====================================================================================*/

//void
//EC_STACK_FREE_VAR_FUNCTION_NAME(TYPE)
//(
    //EC_STACK_STRUCT(TYPE)* list,
    //EC_STACK_VAR_STRUCT(TYPE)* item
//)
//{
    //EC_STACK_DROP_FUNCTION_NAME(TYPE) (list, item);
    //free (item);
//}


/*-------------------------------------------------------------------------------------*
 *                                  Stack Free Stack Method                              *
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
