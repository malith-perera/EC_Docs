#ifndef __EC_LIST_H__
#define __EC_LIST_H__

#include "ec.h"


#define for_list(ec_list, ec_var)                                                      		\
    for (ec_list->list_var = ec_list->first, 												\
		ec_var = ec_list->list_var != NULL ? ec_list->list_var->var: NULL;                  \
		ec_list->list_var != NULL;                                                  		\
		ec_list->list_var = ec_list->list_var != NULL ? ec_list->list_var->next: NULL,		\
		ec_var = ec_list->list_var != NULL ? ec_list->list_var->var: NULL)


#define for_list_reverse(list, ec_var) 					                                  	\
    for (list->list_var = list->last, 														\
		ec_var = list->list_var != NULL ? list->list_var->var: NULL;                        \
        list->list_var != NULL;                                                            	\
        list->list_var = list->list_var != NULL ? list->list_var->previous: NULL, 			\
 		ec_var = list->list_var != NULL ? list->list_var->var: NULL)


/* Function name macros */
#ifdef EC_DEV
#define EC_LIST_VAR_EXISTANCE_FUNCTION_NAME(TYPE)   EC_CONCAT(TYPE, _List_Var_Existance)
#endif

#define EC_LIST_VAR_FREE_FUNCTION_NAME(TYPE)        EC_CONCAT(TYPE, _List_Var_Free_Func) // *** when change errors
#define EC_LIST_FREE_FUNCTION_NAME(TYPE)            EC_CONCAT(TYPE, _List_Free)
#define EC_LIST_NEW_FUNCTION_NAME(TYPE)             EC_CONCAT(TYPE, _List)
#define EC_LIST_VAR_FUNCTION_NAME(TYPE)             EC_CONCAT(TYPE, _List_New)
#define EC_LIST_COPY_FUNCTION_NAME(TYPE)            EC_CONCAT(TYPE, _List_Copy)

#define EC_LIST_APPEND_FUNCTION_NAME(TYPE)          EC_CONCAT(TYPE, _Append)
#define EC_LIST_INSERT_FUNCTION_NAME(TYPE)          EC_CONCAT(TYPE, _Insert)
#define EC_LIST_REPLACE_FUNCTION_NAME(TYPE)         EC_CONCAT(TYPE, _Replace)
#define EC_LIST_DROP_FUNCTION_NAME(TYPE)            EC_CONCAT(Drop_, TYPE)
#define EC_LIST_SORT_FUNCTION_NAME(TYPE, SW)        EC_CONCAT4(Sort_, TYPE, _List_With_, SW)

#define EC_LIST_MOVE_FUNCTION_NAME(TYPE)            EC_CONCAT(TYPE, _Move)
#define EC_LIST_VAR_MOVE_DOWN_FUNCTION_NAME(TYPE)   EC_CONCAT(TYPE, _List_Var_Move_Down)
#define EC_LIST_VAR_DELETE_FUNCTION_NAME(TYPE)      EC_CONCAT(TYPE, _List_Var_Delete)
#define EC_LIST_VAR_DROP_FUNCTION_NAME(TYPE)        EC_CONCAT(TYPE, _Drop)

#define EC_LIST_EXCHANGE_FUNCTION_NAME(TYPE)        EC_CONCAT(TYPE, _Exchange)
#define EC_LIST_VAR_REPLACE_FUNCTION_NAME(TYPE)     EC_CONCAT(TYPE, _List_Var_Replace)
#define EC_LIST_VAR_CHANGE_LIST_FUNCTION_NAME(TYPE) EC_CONCAT(TYPE, _List_Var_Change_List)

//#define EC_LIST_VAR_UNLIST_FUNCTION_NAME(TYPE)    EC_CONCAT(TYPE, _Unlist)
//#define EC_UNLIST_NAME(TYPE)                      EC_CONCAT(TYPE, _unlisted_list)


/* Structure macros */
// EC_MEMORY_REF defined in ec_memory.h
#define EC_LIST_STRUCT(TYPE)                        EC_CONCAT(TYPE, List)
#define EC_LIST_VAR_STRUCT(TYPE)                    EC_CONCAT(TYPE, ListVar)


/*---------------------------*/
/* Function prototype macros */
/*---------------------------*/

#ifdef EC_DEV

#define EC_LIST_VAR_EXISTANCE_FUNCTION_PROTOTYPE(TYPE)  \
bool                                                    \
EC_LIST_VAR_EXISTANCE_FUNCTION_NAME(TYPE)               \
(                                                       \
    EC_LIST_STRUCT(TYPE)        *list,                  \
    EC_LIST_VAR_STRUCT(TYPE)    *ref,                   \
    EC_LIST_VAR_STRUCT(TYPE)    *var                    \
);

#else

#define EC_LIST_VAR_EXISTANCE_FUNCTION_PROTOTYPE(TYPE)

#endif


#define EC_LIST_FREE_FUNCTION_PROTOTYPE(TYPE)           \
void                                                    \
EC_LIST_FREE_FUNCTION_NAME(TYPE)                        \
(                                                       \
    void *list                                          \
);


#define EC_LIST_NEW_FUNCTION_PROTOTYPE(TYPE)            \
EC_LIST_STRUCT(TYPE) *                                  \
EC_LIST_NEW_FUNCTION_NAME(TYPE)                         \
(void);


#define EC_LIST_NEW_VAR_FUNCTION_PROTOTYPE(TYPE)        \
EC_LIST_VAR_STRUCT (TYPE) *                             \
EC_LIST_VAR_FUNCTION_NAME(TYPE)                         \
(                                                       \
    EC_LIST_STRUCT(TYPE)    *list,                      \
    TYPE                    *var                        \
);


#define EC_LIST_APPEND_FUNCTION_PROTOTYPE(TYPE)         \
void                                                    \
EC_LIST_APPEND_FUNCTION_NAME(TYPE)                      \
(                                                       \
    EC_LIST_STRUCT(TYPE)        *list,                  \
    TYPE                        *var                    \
);


/* List Insert Function Prototype */
#define EC_LIST_INSERT_FUNCTION_PROTOTYPE(TYPE)         \
void                                                    \
EC_LIST_INSERT_FUNCTION_NAME(TYPE)                      \
(                                                       \
    EC_LIST_STRUCT(TYPE)        *list,                  \
    EC_LIST_VAR_STRUCT(TYPE)    *ref,                   \
    TYPE                        *var                    \
);


/* List Move UP Function Prototype */
#define EC_LIST_MOVE_FUNCTION_PROTOTYPE(TYPE)           \
void                                                    \
EC_LIST_MOVE_FUNCTION_NAME(TYPE)                        \
(                                                       \
    EC_LIST_STRUCT(TYPE)        *list,                  \
    EC_LIST_VAR_STRUCT(TYPE)    *ref,                   \
    EC_LIST_VAR_STRUCT(TYPE)    *var                    \
);


#define EC_LIST_EXCHANGE_FUNCTION_PROTOTYPE(TYPE)       \
void                                                    \
EC_LIST_EXCHANGE_FUNCTION_NAME(TYPE)                    \
(                                                       \
    EC_LIST_VAR_STRUCT(TYPE)    *var1,                  \
    EC_LIST_VAR_STRUCT(TYPE)    *var2                   \
);


#define EC_LIST_REPLACE_FUNCTION_PROTOTYPE(TYPE)        \
void                                                    \
EC_LIST_REPLACE_FUNCTION_NAME(TYPE)                     \
(                                                       \
    EC_LIST_STRUCT(TYPE)        *list,                  \
    EC_LIST_VAR_STRUCT(TYPE)    *ref,                   \
    EC_LIST_VAR_STRUCT(TYPE)    *var                    \
);


#define EC_LIST_COPY_FUNCTION_PROTOTYPE(TYPE)           \
EC_LIST_STRUCT(TYPE) *                                  \
EC_LIST_COPY_FUNCTION_NAME(TYPE)                        \
(                                                       \
    EC_LIST_STRUCT(TYPE) *list                          \
);


#define EC_LIST_VAR_DROP_FUNCTION_PROTOTYPE(TYPE)       \
void                                                    \
EC_LIST_VAR_DROP_FUNCTION_NAME(TYPE)                    \
(                                                       \
    EC_LIST_STRUCT(TYPE)        *list,                  \
    EC_LIST_VAR_STRUCT(TYPE)    *var                    \
);


#define EC_LIST_H(TYPE)           						\
	typedef struct EC_LIST_VAR_STRUCT(TYPE) {           \
		TYPE                            *var;           \
		struct EC_LIST_VAR_STRUCT(TYPE) *next;          \
		struct EC_LIST_VAR_STRUCT(TYPE) *previous;      \
	} EC_LIST_VAR_STRUCT(TYPE);                         \
														\
	typedef struct EC_LIST_STRUCT(TYPE) {               \
		EC_LIST_VAR_STRUCT(TYPE) *first;                /* first var in the list */\
		EC_LIST_VAR_STRUCT(TYPE) *last;                 /* last var in the list */\
		EC_LIST_VAR_STRUCT(TYPE) *list_var;             /* hold var temporaly in for_list repeatition */\
		EC_MEMORY_REF                                   \
	} EC_LIST_STRUCT(TYPE); 							\
														\
	EC_LIST_VAR_EXISTANCE_FUNCTION_PROTOTYPE(TYPE)      \
	EC_LIST_FREE_FUNCTION_PROTOTYPE(TYPE)               \
	EC_LIST_NEW_FUNCTION_PROTOTYPE(TYPE)                \
	EC_LIST_NEW_VAR_FUNCTION_PROTOTYPE(TYPE)            \
	EC_LIST_APPEND_FUNCTION_PROTOTYPE(TYPE)             \
	EC_LIST_INSERT_FUNCTION_PROTOTYPE(TYPE)             \
	EC_LIST_MOVE_FUNCTION_PROTOTYPE(TYPE)               \
	EC_LIST_EXCHANGE_FUNCTION_PROTOTYPE(TYPE)           \
	EC_LIST_REPLACE_FUNCTION_PROTOTYPE(TYPE)            \
	EC_LIST_COPY_FUNCTION_PROTOTYPE(TYPE)               \
	EC_LIST_VAR_DROP_FUNCTION_PROTOTYPE(TYPE)


/*---------------------------*/
/* Macro Generated Functions */
/*---------------------------*/

#ifdef EC_DEV // EC_LIST_VAR_EXISTANCE_FUNCTION

#define EC_LIST_VAR_EXISTANCE(TYPE, list, ref, var)                         \
    if (EC_LIST_VAR_EXISTANCE_FUNCTION_NAME(TYPE)(list, ref, var) != true)  \
        return;

#define EC_LIST_VAR_EXISTANCE_FUNCTION(TYPE)                            \
bool                                                                    \
EC_LIST_VAR_EXISTANCE_FUNCTION_NAME(TYPE)                               \
(                                                                       \
    EC_LIST_STRUCT(TYPE)        *list,                                  \
    EC_LIST_VAR_STRUCT(TYPE)    *ref,                                   \
    EC_LIST_VAR_STRUCT(TYPE)    *var                                    \
)                                                                       \
{                                                                       \
    bool ref_exist = false;                                             \
    bool var_exist = false;                                             \
																		\
	TYPE *EC_CONCAT3(ec_, list, _var); 									\
    for_list(list, EC_CONCAT3(ec_, list, _var))                         \
    {                                                                   \
        if (list->list_var == ref || ref == NULL) ref_exist = true;     \
        if (list->list_var == var) var_exist = true;                    \
        if (ref_exist && var_exist) return true;                        \
    }                                                                   \
                                                                        \
    if (ref_exist != true)                                              \
    {                                                                   \
        EC_WARN_PRINT_MSG("list ref not exist in the list", "Warning")  \
    }                                                                   \
                                                                        \
    if (var_exist != true)                                              \
    {                                                                   \
        EC_WARN_PRINT_MSG("list var not exist in the list", "Warning")  \
    }                                                                   \
    return false;                                                       \
}

#else

#define EC_LIST_VAR_EXISTANCE_FUNCTION(TYPE)

#endif // EC_LIST_VAR_EXISTANCE_FUNCTION


/******* list free functions not finished yet */
#define EC_LIST_FREE_FUNCTION(TYPE)                                 \
void                                                                \
EC_LIST_FREE_FUNCTION_NAME(TYPE)                                    \
(                                                                   \
    void *list                                                      \
)                                                                   \
{                                                                   \
    EC_LIST_STRUCT(TYPE) *l = (EC_LIST_STRUCT(TYPE) *) list;        \
}


#define EC_LIST_NEW_FUNCTION(TYPE)                                  \
EC_LIST_STRUCT(TYPE) *                                              \
EC_LIST_NEW_FUNCTION_NAME(TYPE)                                     \
(void)                                                              \
{                                                                   \
    EC_VAR_CREATE(EC_LIST_STRUCT(TYPE), new_list, __LINE__)         /* This macro in ec_var.h*/\
                                                                    \
    return new_list;                                                \
}


/* New List Variable Function */
#define EC_LIST_NEW_VAR_FUNCTION(TYPE)                              \
EC_LIST_VAR_STRUCT (TYPE) *                                         \
EC_LIST_VAR_FUNCTION_NAME(TYPE)                                     \
(                                                                   \
    EC_LIST_STRUCT(TYPE)    *list,                                  \
    TYPE                    *var                                    \
)                                                                   \
{                                                                   \
    EC_LIST_APPEND_FUNCTION_NAME(TYPE) (list, var);                 /* TYPE *var is in this macro in ec_var.h */\
                                                                    \
    return list->list_var;                                          \
}


/* List Append Function */
#define EC_LIST_APPEND_FUNCTION(TYPE)                               \
void                                                                \
EC_LIST_APPEND_FUNCTION_NAME(TYPE)                                  \
(                                                                   \
    EC_LIST_STRUCT(TYPE)        *list,                              \
    TYPE                        *var                                \
)                                                                   \
{                                                                   \
    EC_VAR_CREATE(EC_LIST_VAR_STRUCT(TYPE), list_var, __LINE__);    \
    list_var->var = var;                                            \
                                                                    \
    list_var->next = NULL;                                          \
                                                                    \
    if (list->first != NULL)                                        /* List not empty */\
    {                                                               \
        list_var->previous = list->last;                            \
        list->last->next = list_var;                                \
    }                                                               \
    else                                                            /* empty list */\
    {                                                               \
        list_var->previous = NULL;                                  \
        list->first = list_var;                                     \
    }                                                               \
                                                                    \
    list->last = list_var;                                          \
}


/* List Insert After Function */
#define EC_LIST_INSERT_FUNCTION(TYPE)                               \
void                                                                \
EC_LIST_INSERT_FUNCTION_NAME(TYPE)                                  \
(                                                                   \
    EC_LIST_STRUCT(TYPE)        *list,                              \
    EC_LIST_VAR_STRUCT(TYPE)    *ref,                               \
    TYPE                        *var                                \
)                                                                   \
{                                                                   \
    EC_VAR_CREATE(EC_LIST_VAR_STRUCT(TYPE), list_var_new, __LINE__) /* This macro in ec_var.h*/\
    list_var_new->var = var;                                        \
                                                                    \
    if (ref == NULL)                                                \
    {                                                               \
        if (list->first != NULL)                                    \
        {                                                           \
            list_var_new->previous = NULL;                          \
            list_var_new->next = list->first;                       \
            list->first->previous = list_var_new;                   \
            list->first = list_var_new;                             \
        }                                                           \
        else                                                        \
        {                                                           \
            list_var_new->next = NULL;                              \
            list_var_new->previous = NULL;                          \
            list->first = list_var_new;                             \
            list->last = list_var_new;                              \
        }                                                           \
    }                                                               \
    else if (ref == list->first)                                    /* ref is the first list var */\
    {                                                               \
        if (ref == list->last)                                      /* ref var is the first and also the last list var */ \
        {                                                           \
            list_var_new->previous = list->first;                   \
            list_var_new->next = NULL;                              \
            list->first->next = list_var_new;                       \
            list->last = list_var_new;                              \
        }                                                           \
        else                                                        /* ref var is the first list var but not the last */ \
        {                                                           \
            list_var_new->previous = ref;                           \
            list_var_new->next = ref->next;                         \
            ref->next->previous = list_var_new;                     \
            ref->next = list_var_new;                               \
        }                                                           \
    }                                                               \
    else if (ref == list->last)                                     /* ref var is the last list var */\
    {                                                               \
        list_var_new->previous = ref;                               \
        list_var_new->next = NULL;                                  \
        ref->next = list_var_new;                                   \
        list->last = list_var_new;                                  \
    }                                                               \
    else                                                            \
    {                                                               \
        list_var_new->previous = ref;                               \
        list_var_new->next = ref->next;                             \
        ref->next->previous = list_var_new;                         \
        ref->next = list_var_new;                                   \
    }                                                               \
}


/* Move up function */
#define EC_LIST_MOVE_FUNCTION(TYPE)                                 \
void                                                                \
EC_LIST_MOVE_FUNCTION_NAME(TYPE)                                    \
(                                                                   \
    EC_LIST_STRUCT(TYPE)        *list,                              \
    EC_LIST_VAR_STRUCT(TYPE)    *ref,                               \
    EC_LIST_VAR_STRUCT(TYPE)    *var                                \
)                                                                   \
{                                                                   \
    EC_LIST_VAR_EXISTANCE(TYPE, list, ref, var);  /**** only when EC_DEV */\
                                                                    \
    if (var->previous == ref)                                       \
    {                                                               \
       return;                                                      \
    }                                                               \
                                                                    \
    if (var == list->first)                                         \
    {                                                               \
        if (ref != NULL)                                            \
        {                                                           \
            if (ref == list->last)                                  \
            {                                                       \
                var->next->previous = NULL;                         \
                list->first = var->next;                            \
                var->next = ref->next;                              \
                ref->next = var;                                    \
                var->previous = ref;                                \
                list->last = var;                                   \
            }                                                       \
            else                                                    \
            {                                                       \
                var->next->previous = NULL;                         \
                list->first = var->next;                            \
                var->next = ref->next;                              \
                var->previous = ref;                                \
                ref->next->previous = var;                          \
                ref->next = var;                                    \
            }                                                       \
        }                                                           \
    }                                                               \
    else if (var == list->last)                                     \
    {                                                               \
        if (ref != list->last)                                      \
        {                                                           \
            if (ref == NULL)                                        \
            {                                                       \
                var->previous->next = NULL;                         \
                list->last = var->previous;                         \
                var->next = list->first;                            \
                var->previous = NULL;                               \
                list->first->previous = var;                        \
                list->first = var;                                  \
            }                                                       \
            else                                                    \
            {                                                       \
                var->previous->next = NULL;                         \
                list->last = var->previous;                         \
                var->next = ref->next;                              \
                var->previous = ref;                                \
                ref->next->previous = var;                          \
                ref->next = var;                                    \
            }                                                       \
        }                                                           \
    }                                                               \
    else                                                            \
    {                                                               \
        if (ref == NULL)                                            \
        {                                                           \
            var->previous->next = var->next;                        \
            var->next->previous = var->previous;                    \
            var->next = list->first;                                \
            var->previous = NULL;                                   \
            list->first->previous = var;                            \
            list->first = var;                                      \
        }                                                           \
        else if (ref == list->last)                                 \
        {                                                           \
            var->previous->next = var->next;                        \
            var->next->previous = var->previous;                    \
            ref->next = var;                                        \
            var->next = NULL;                                       \
            var->previous = ref;                                    \
            list->last = var;                                       \
        }                                                           \
        else                                                        \
        {                                                           \
            var->previous->next = var->next;                        \
            var->next->previous = var->previous;                    \
            var->next = ref->next;                                  \
            var->previous = ref;                                    \
            ref->next->previous = var;                              \
            ref->next = var;                                        \
        }                                                           \
    }                                                               \
}


#define EC_LIST_EXCHANGE_FUNCTION(TYPE)         \
void                                            \
EC_LIST_EXCHANGE_FUNCTION_NAME(TYPE)            \
(                                               \
    EC_LIST_VAR_STRUCT(TYPE)    *var1,          \
    EC_LIST_VAR_STRUCT(TYPE)    *var2           \
)                                               \
{                                               \
    TYPE  *temp_var;                            \
    temp_var = var1->var;                       \
    var1->var = var2->var;                      \
    var2->var = temp_var;                       \
}


    //if (rep->previous != NULL) printf ("rp %d\n", rep->previous->no);\
/* List Replace Function */
#define EC_LIST_REPLACE_FUNCTION(TYPE)          \
void                                            \
EC_LIST_REPLACE_FUNCTION_NAME(TYPE)             \
(                                               \
    EC_LIST_STRUCT(TYPE)        *list,          \
    EC_LIST_VAR_STRUCT(TYPE)    *ref,           /* replaced ref */\
    EC_LIST_VAR_STRUCT(TYPE)    *var            /* replaced by var*/\
)                                               \
{                                               \
    ref->var = var->var;                        \
                                                \
    if (var == list->first)                     \
    {                                           \
        var->next->previous = NULL;             \
        list->first = var->next;                \
    }                                           \
    else if (var == list->last)                 \
    {                                           \
        var->previous->next = NULL;             \
        list->last = var->previous;             \
    }                                           \
    else                                        \
    {                                           \
        var->previous->next = var->next;        \
        var->next->previous = var->previous;    \
    }                                           \
}


// Copy array
#define EC_LIST_COPY_FUNCTION(TYPE)                                         		\
EC_LIST_STRUCT(TYPE) *                                                      		\
EC_LIST_COPY_FUNCTION_NAME(TYPE)                                            		\
(                                                                           		\
    EC_LIST_STRUCT(TYPE) *list                                              		\
)                                                                           		\
{                                                                           		\
    EC_LIST_STRUCT(TYPE) *list_copy = EC_LIST_NEW_FUNCTION_NAME(TYPE)();    		\
                                                                            		\
	TYPE *EC_CONCAT3(ec_, list, _var); 												\
    for_list(list, EC_CONCAT3(ec_, list, _var))                             		\
    {                                                                       		\
        EC_LIST_APPEND_FUNCTION_NAME(TYPE)(list_copy, EC_CONCAT3(ec_, list, _var)); \
    }                                                                       		\
                                                                            		\
    return list_copy;                                                       		\
}


#define EC_LIST_VAR_DROP_FUNCTION(TYPE)                     \
void                                                        \
EC_LIST_VAR_DROP_FUNCTION_NAME(TYPE)                        \
(                                                           \
    EC_LIST_STRUCT(TYPE)        *list,                      \
    EC_LIST_VAR_STRUCT(TYPE)    *var                        \
)                                                           \
{                                                           \
    if (var == list->first && var == list->last)            \
    {                                                       \
        list->first = NULL;                                 \
        list->last = NULL;                                  \
    }                                                       \
    else if (var == list->first)                            \
    {                                                       \
        var->next->previous = NULL;                         \
        list->first = var->next;                            \
    }                                                       \
    else if (var == list->last)                             \
    {                                                       \
        var->previous->next = NULL;                         \
        list->last = var->previous;                         \
    }                                                       \
    else                                                    \
    {                                                       \
        var->previous->next = var->next;                    \
        var->next->previous = var->previous;                \
    }                                                       \
}


#define EC_LIST_C(TYPE)             		\
    EC_LIST_VAR_EXISTANCE_FUNCTION(TYPE)    \
    EC_LIST_FREE_FUNCTION(TYPE)             \
    EC_LIST_NEW_FUNCTION(TYPE)              \
    EC_LIST_NEW_VAR_FUNCTION(TYPE)          \
    EC_LIST_APPEND_FUNCTION(TYPE)           \
    EC_LIST_INSERT_FUNCTION(TYPE)           \
    EC_LIST_MOVE_FUNCTION(TYPE)             \
    EC_LIST_EXCHANGE_FUNCTION(TYPE)         \
    EC_LIST_REPLACE_FUNCTION(TYPE)          \
    EC_LIST_COPY_FUNCTION(TYPE)             \
    EC_LIST_VAR_DROP_FUNCTION(TYPE)


#define EC_LIST(TYPE) 		\
	EC_LIST_H(TYPE) 		\
	EC_LIST_C(TYPE)


#endif // __EC_LIST_H__
