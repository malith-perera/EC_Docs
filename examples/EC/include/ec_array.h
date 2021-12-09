#ifndef EC_ARRAY_H
#define EC_ARRAY_H

#include "ec.h"

#define foreach_array(array)                                                                        \
  array->i = 0;                                                                                     \
  for (array->var = array->index; array->i < array->count; array->var = array->index + ++array->i)

/*

#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))

#define EC_ARRAY_FIND_FUNCTION_NAME(T, F) EC_CONCAT(Find_, T, F)
#define EC_ARRAY_RESIZE_FUNCTION_NAME(TYPE) EC_CONCAT(Resize_, T,)

*/

/* Function name macros */
#define EC_ARRAY_NEW_FUNCTION_NAME(TYPE)                            EC_CONCAT(TYPE, _Array,)
#define EC_ARRAY_FREE_FUNCTION_NAME(TYPE)                           EC_CONCAT(Free_, TYPE,) // memory Free
#define EC_ARRAY_SORT_FUNCTION_NAME(TYPE, SORT_WITH)                EC_CONCAT(TYPE, _Array_Sort_, SORT_WITH)
#define EC_ARRAY_REVERSE_FUNCTION_NAME(TYPE)                        EC_CONCAT(TYPE, _Array, _Reverse)
#define EC_ARRAY_SEARCH_FUNCTION_NAME(TYPE, SORT_WITH)              EC_CONCAT(TYPE, _Sorted_Search_, SORT_WITH)
#define EC_ARRAY_SEARCH_MAX_FUNCTION_NAME(TYPE, SORT_WITH)          EC_CONCAT(TYPE, _Max_, SORT_WITH)
#define EC_ARRAY_SEARCH_MIN_FUNCTION_NAME(TYPE, SORT_WITH)          EC_CONCAT(TYPE, _Min_, SORT_WITH)


/* Structure macros */
// defined in ec_memory.h
#define EC_ARRAY_STRUCT(TYPE) EC_CONCAT(TYPE, Array,)

#define EC_ARRAY(TYPE, VAR)                             \
typedef struct EC_ARRAY_STRUCT(TYPE) {                  \
    TYPE*   index;                                      \
    int     count;                                      \
    int     i;                                          \
    TYPE*   var;                                        \
    EC_MEMORY_REF                                       \
} EC_ARRAY_STRUCT(TYPE);


/* Function prototype macros */

#define EC_ARRAY_FREE_FUNCTION_PROTOTYPE(TYPE)          \
void                                                    \
EC_ARRAY_FREE_FUNCTION_NAME(EC_ARRAY_STRUCT(TYPE))      \
(                                                       \
    void* var                                           \
);


#define EC_ARRAY_NEW_FUNCTION_PROTOTYPE(TYPE)           \
EC_ARRAY_STRUCT(TYPE)*                                  \
EC_ARRAY_NEW_FUNCTION_NAME(TYPE)                        \
(                                                       \
    int count                                           \
);


#define EC_ARRAY_REVERSE_FUNCTION_PROTOTYPE(TYPE)       \
void                                                    \
EC_ARRAY_REVERSE_FUNCTION_NAME(TYPE)                    \
(                                                       \
    EC_ARRAY_STRUCT(TYPE)* array                        \
);


#define EC_ARRAY_FUNCTION_PROTOTYPES(TYPE)              \
    EC_ARRAY_FREE_FUNCTION_PROTOTYPE(TYPE)              \
    EC_ARRAY_NEW_FUNCTION_PROTOTYPE(TYPE)               \
    EC_ARRAY_REVERSE_FUNCTION_PROTOTYPE(TYPE)


#define EC_ARRAY_SORT_FUNCTION_PROTOTYPE(TYPE, SORT_WITH)       \
void                                                            \
EC_ARRAY_SORT_FUNCTION_NAME(TYPE, SORT_WITH)                    \
(                                                               \
    EC_ARRAY_STRUCT(TYPE)* array                                \
);


#define EC_ARRAY_SEARCH_FUNCTION_PROTOTYPE(TYPE, SEARCH_WITH)       \
int                                                                 \
EC_ARRAY_SEARCH_FUNCTION_NAME(TYPE, SEARCH_WITH)                    \
(                                                                   \
    EC_ARRAY_STRUCT(TYPE)*  array,                                  \
    int                     search_value                            \
);


#define EC_ARRAY_SEARCH_MAX_FUNCTION_PROTOTYPE(TYPE, SEARCH_WITH)           \
TYPE*                                                                       \
EC_ARRAY_SEARCH_MAX_FUNCTION_NAME(TYPE, SEARCH_WITH)                        \
(                                                                           \
    EC_ARRAY_STRUCT(TYPE)* array                                            \
);


#define EC_ARRAY_SEARCH_MIN_FUNCTION_PROTOTYPE(TYPE, SEARCH_WITH)           \
TYPE*                                                                       \
EC_ARRAY_SEARCH_MIN_FUNCTION_NAME(TYPE, SEARCH_WITH)                        \
(                                                                           \
    EC_ARRAY_STRUCT(TYPE)* array                                            \
);


/* reverse int array */
void
Int_Array_Reverse
(
    int* array,
    int  array_count
);


int*
Int_Array_Search
(
    int* array,
    int  array_count,
    int  search_value, // search search_value
    int  search_times  // how much times search
);


int
Int_Sorted_Array_Search
(
    int* array,
    int  array_count,
    int  search_value
);


/* find maximum number in an integer array */
int
Int_Array_Max
(
    int* array,
    int  array_count
);


/* find minimum number in an integer array */
int
Int_Array_Min
(
    int* array,
    int  array_count
);


/* Function macros */

#define EC_ARRAY_FREE_FUNCTION(TYPE)                                \
void                                                                \
EC_ARRAY_FREE_FUNCTION_NAME(EC_ARRAY_STRUCT(TYPE))                  \
(                                                                   \
    void* var                                                       \
)                                                                   \
{                                                                   \
    EC_ARRAY_STRUCT(TYPE)* p = (EC_ARRAY_STRUCT(TYPE)*) var;        \
    free (p->index);                                                \
    free (p);                                                       \
}


#define EC_ARRAY_NEW_FUNCTION(TYPE)                                                                         \
EC_ARRAY_STRUCT(TYPE)*                                                                                      \
EC_ARRAY_NEW_FUNCTION_NAME(TYPE)                                                                            \
(                                                                                                           \
    int count                                                                                               \
)                                                                                                           \
{                                                                                                           \
    EC_ARRAY_STRUCT(TYPE)* var = (EC_ARRAY_STRUCT(TYPE)*) malloc (sizeof (EC_ARRAY_STRUCT(TYPE)));          \
                                                                                                            \
    if (var == NULL)                                                                                        \
    {                                                                                                       \
        EC_ERROR_MEM_ALLOC()                                                                                \
        return NULL;                                                                                        \
    }                                                                                                       \
                                                                                                            \
    TYPE* array = (TYPE*) malloc (sizeof (TYPE) * count);                                                   \
                                                                                                            \
    if (var == NULL)                                                                                        \
    {                                                                                                       \
        EC_ERROR_MEM_ALLOC()                                                                                \
        return NULL;                                                                                        \
    }                                                                                                       \
                                                                                                            \
    var->count = count;                                                                                     \
    var->index = array;                                                                                     \
                                                                                                            \
    if (EC_MEMORY)                                                                                          \
    {                                                                                                       \
        ECMemory* ec_memory_new = (ECMemory*) malloc (sizeof(ECMemory));                                    \
                                                                                                            \
        ec_memory_new->type = EC_ARRAY_TYPE;                                                                \
        ec_memory_new->var = var;                                                                           \
        ec_memory_new->memory = NULL;                                                                       \
        ec_memory_new->Free_Func = EC_ARRAY_FREE_FUNCTION_NAME (EC_ARRAY_STRUCT(TYPE));                     \
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
    }                                                                                                       \
                                                                                                            \
    return var;                                                                                             \
}


/* EC_Array_Sort */

#define EC_ARRAY_SORT_FUNCTION(TYPE, SORT_WITH)                                 \
void                                                                            \
EC_ARRAY_SORT_FUNCTION_NAME(TYPE, SORT_WITH)                                    \
(                                                                               \
    EC_ARRAY_STRUCT(TYPE)* array                                                \
)                                                                               \
{                                                                               \
    TYPE* min_ref;                                                              \
    TYPE temp;                                                                  \
                                                                                \
    int j = 0;                                                                  \
    int i = 0;                                                                  \
                                                                                \
    for (i; i < array->count - 1; i++)                                          \
    {                                                                           \
        min_ref = &array->index[i];                                             \
                                                                                \
        for (j = i + 1; j < array->count; j++)                                  \
        {                                                                       \
            if (array->index[j].SORT_WITH < min_ref->SORT_WITH)                 \
            {                                                                   \
                min_ref = &array->index[j];                                     \
            }                                                                   \
        }                                                                       \
                                                                                \
        temp = array->index[i];                                                 \
        array->index[i] = *min_ref;                                             \
        *min_ref = temp;                                                        \
    }                                                                           \
}


#define EC_ARRAY_REVERSE_FUNCTION(TYPE)                                 \
void                                                                    \
EC_ARRAY_REVERSE_FUNCTION_NAME(TYPE)                                    \
(                                                                       \
    EC_ARRAY_STRUCT(TYPE)* array                                        \
)                                                                       \
{                                                                       \
    TYPE temp;                                                          \
                                                                        \
    for (int i = 0; i < (array->count) / 2; i++)                        \
    {                                                                   \
        temp = array->index[i];                                         \
        array->index[i] = array->index[array->count - (1 + i)];         \
        array->index[array->count - 1 - i] = temp;                      \
    }                                                                   \
}


/* Array Search */

#define EC_ARRAY_SEARCH_FUNCTION(TYPE, SEARCH_WITH)                                 \
int                                                                                 \
EC_ARRAY_SEARCH_FUNCTION_NAME(TYPE, SEARCH_WITH)                                    \
(                                                                                   \
    EC_ARRAY_STRUCT(TYPE)*  array,                                                  \
    int                     search_value                                            \
)                                                                                   \
{                                                                                   \
    int lei, uei, mi;                                                               /* lei = lower end index, uei = upper end index, mi = mid index */\
                                                                                    \
    lei = 0;                                                                        \
    uei = array->count - 1;                                                         \
    mi = (lei + uei) / 2;                                                           \
                                                                                    \
    if (search_value < array->index[lei].SEARCH_WITH)                               \
    {                                                                               \
        printf ("Search value is lower than minimum value\n");                      \
        return -1;                                                                  \
    }                                                                               \
    else if (search_value > array->index[uei].SEARCH_WITH)                          \
    {                                                                               \
        printf ("Search value is grater than maximum value\n");                     \
        return -1;                                                                  \
    }                                                                               \
                                                                                    \
    while (1)                                                                       \
    {                                                                               \
        printf ("lei %d uei %d mi %d\n", lei, uei, mi);                             \
                                                                                    \
        if (search_value == array->index[mi].SEARCH_WITH)                           \
        {                                                                           \
            printf ("mi %d\n", mi);                                                 \
            return mi;                                                              \
        }                                                                           \
        else if (search_value == array->index[lei].SEARCH_WITH)                     \
        {                                                                           \
            printf ("lei %d\n", lei);                                               \
            return lei;                                                             \
        }                                                                           \
        else if (search_value == array->index[uei].SEARCH_WITH)                     \
        {                                                                           \
            printf ("uei %d\n", uei);                                               \
            return uei;                                                             \
        }                                                                           \
        else if (search_value > array->index[mi].SEARCH_WITH)                       \
        {                                                                           \
            printf ("v > mi\n");                                                    \
            lei = mi + 1;                                                           \
            uei = uei - 1;                                                          \
            mi = (lei + uei) / 2;                                                   \
        }                                                                           \
        else                                                                        \
        {                                                                           \
            printf ("v < mi\n");                                                    \
            uei = mi - 1;                                                           \
            lei = lei + 1;                                                          \
            mi = (lei + uei) / 2;                                                   \
        }                                                                           \
                                                                                    \
        if (lei == uei)                                                             \
        {                                                                           \
            if (search_value == array->index[lei].SEARCH_WITH)                      \
            {                                                                       \
                printf ("lei = uei %d\n", lei);                                     \
                return lei;                                                         \
            }                                                                       \
            else                                                                    \
            {                                                                       \
                printf ("No search result found lei %d uei %d\n", lei, uei);        \
                return -1;                                                          \
            }                                                                       \
        }                                                                           \
    }                                                                               \
}

/* Search maximum var according to var attribute SEARCH_WITH */

#define EC_ARRAY_SEARCH_MAX_FUNCTION(TYPE, SEARCH_WITH)                     \
TYPE*                                                                       \
EC_ARRAY_SEARCH_MAX_FUNCTION_NAME(TYPE, SEARCH_WITH)                        \
(                                                                           \
    EC_ARRAY_STRUCT(TYPE)* array                                            \
)                                                                           \
{                                                                           \
    TYPE* max = &array->index[0];                                           \
                                                                            \
    for (int i = 1; i < array->count; i++)                                  \
    {                                                                       \
        if (array->index[i].SEARCH_WITH > max->SEARCH_WITH)                 \
        {                                                                   \
            max = &array->index[i];                                         \
        }                                                                   \
    }                                                                       \
                                                                            \
    return max;                                                             \
}


/* Search minimum var according to var attribute SEARCH_WITH */

#define EC_ARRAY_SEARCH_MIN_FUNCTION(TYPE, SEARCH_WITH)                     \
TYPE*                                                                       \
EC_ARRAY_SEARCH_MIN_FUNCTION_NAME(TYPE, SEARCH_WITH)                        \
(                                                                           \
    EC_ARRAY_STRUCT(TYPE)* array                                            \
)                                                                           \
{                                                                           \
    TYPE* min = &array->index[0];                                           \
                                                                            \
    for (int i = 1; i < array->count; i++)                                  \
    {                                                                       \
        if (array->index[i].SEARCH_WITH < min->SEARCH_WITH)                 \
        {                                                                   \
            min = &array->index[i];                                         \
        }                                                                   \
    }                                                                       \
                                                                            \
    return min;                                                             \
}


#define EC_ARRAY_FUNCTIONS(TYPE)    \
    EC_ARRAY_FREE_FUNCTION(TYPE)    \
    EC_ARRAY_NEW_FUNCTION(TYPE)

#endif // EC_ARRAY_H


/*
EC_ARRAY_RESIZE**
EC_ARRAY_RESIZE_FUNCTION_NAME(EC_ARRAY_RESIZE)
(
    EC_ARRAY_RESIZE** var,
    int* current_size,
    int new_size
)
{
    EC_ARRAY_RESIZE* arr = (EC_ARRAY_RESIZE* ) realloc (*var, sizeof (EC_ARRAY_RESIZE)*  new_size);

    *current_size = new_size;

    if (arr != NULL)
    {
        *var = arr;
        return var;
    }


    printf ("Cannot resize array\n");
    return NULL;
}

*/
