#ifndef __EC_ARRAY_H__ 
#define __EC_ARRAY_H__

#include "ec.h"


#define NELEMS(x) (sizeof(x) / sizeof((x)[0]))


#define for_array(ec_array, aptr)                               \
    aptr = ec_array->var;                                       \
    for (int EC_CONCAT(aptr, _i) = 0;                           \
         EC_CONCAT(aptr, _i) < ec_array->length;                \
         aptr = ec_array->var + ++EC_CONCAT(aptr, _i))


#define Static_Array(type, array, len)      \
    type EC_CONCAT(ec_c_, array)[len];      \
    EC_CONCAT(type, Array) ec_array;        \
    ec_array.var = EC_CONCAT(ec_c_, array); \
    ec_array.length = len;                  \
    EC_CONCAT(type, Array) * const array = &ec_array;

   
/*
#define EC_ARRAY_FIND_FUNCTION_NAME(T, F) EC_CONCAT3(Find_, T, F)
#define EC_ARRAY_RESIZE_FUNCTION_NAME(TYPE) EC_CONCAT2(Resize_, T)
*/

/* Function name macros */
#define EC_ARRAY_FREE_FUNCTION_NAME(TYPE)           EC_CONCAT2(TYPE, _Array_Free) // memory Free
#define EC_ARRAY_FREE_VAR_FUNCTION_NAME(TYPE)       EC_CONCAT2(TYPE, _Array_Free_Func)
#define EC_ARRAY_UNLOCK_FUNCTION_NAME(TYPE)         EC_CONCAT2(TYPE, _Array_Unlock)
#define EC_ARRAY_NEW_FUNCTION_NAME(TYPE)            EC_CONCAT2(TYPE, _Array)
#define EC_ARRAY_COPY_FUNCTION_NAME(TYPE)           EC_CONCAT2(TYPE, _Array_Clone)
#define EC_ARRAY_REVERSE_FUNCTION_NAME(TYPE)        EC_CONCAT3(TYPE, _Array, _Reverse)
#define EC_ARRAY_SORT_FUNCTION_NAME(TYPE, SW)       EC_CONCAT3(TYPE, _Array_Sort_With_, SW)
#define EC_ARRAY_INT_FUNCTION_NAME(TYPE, SW)        EC_CONCAT3(TYPE, _Array_Int_, SW)
#define EC_ARRAY_STR_FUNCTION_NAME(TYPE, SW)        EC_CONCAT3(TYPE, _Array_Str_, SW)
#define EC_ARRAY_MAX_FUNCTION_NAME(TYPE, SW)        EC_CONCAT3(TYPE, _Array_Max_, SW)
#define EC_ARRAY_MIN_FUNCTION_NAME(TYPE, SW)        EC_CONCAT3(TYPE, _Array_Min_, SW)

/* Structure macros */
// defined in ec_memory.h
#define EC_ARRAY_STRUCT(TYPE)           EC_CONCAT2(TYPE, Array)


/* Function prototype macros */

#define EC_ARRAY_FREE_FUNCTION_PROTOTYPE(TYPE)          \
void                                                    \
EC_ARRAY_FREE_FUNCTION_NAME(TYPE)                       \
(                                                       \
    void *var                                           \
);


#define EC_ARRAY_FREE_VAR_FUNCTION_PROTOTYPE(TYPE)      \
void                                                    \
EC_ARRAY_FREE_VAR_FUNCTION_NAME(TYPE)                   \
(                                                       \
    void *var                                           \
);


#define EC_ARRAY_UNLOCK_FUNCTION_PROTOTYPE(TYPE)        \
void                                                    \
EC_ARRAY_UNLOCK_FUNCTION_NAME(TYPE)                     \
(                                                       \
    void *var                                           \
);


#define EC_ARRAY_NEW_FUNCTION_PROTOTYPE(TYPE)           \
EC_ARRAY_STRUCT(TYPE) *                                 \
EC_ARRAY_NEW_FUNCTION_NAME(TYPE)                        \
(                                                       \
    int length                                          \
);


#define EC_ARRAY_COPY_FUNCTION_PROTOTYPE(TYPE)          \
EC_ARRAY_STRUCT(TYPE) *                                 \
EC_ARRAY_COPY_FUNCTION_NAME(TYPE)                       \
(                                                       \
    EC_ARRAY_STRUCT(TYPE) *array                        \
);


#define EC_ARRAY_REVERSE_FUNCTION_PROTOTYPE(TYPE)       \
void                                                    \
EC_ARRAY_REVERSE_FUNCTION_NAME(TYPE)                    \
(                                                       \
    EC_ARRAY_STRUCT(TYPE) *array                        \
);


#define EC_ARRAY_H(TYPE)          \
typedef struct EC_ARRAY_STRUCT(TYPE) {              \
	TYPE            *var;                           \
	int             length;                         \
	EC_MEMORY_REF                                   \
} EC_ARRAY_STRUCT(TYPE); 							\
EC_ARRAY_FREE_FUNCTION_PROTOTYPE(TYPE)              \
EC_ARRAY_FREE_VAR_FUNCTION_PROTOTYPE(TYPE)          \
EC_ARRAY_UNLOCK_FUNCTION_PROTOTYPE(TYPE)            \
EC_ARRAY_NEW_FUNCTION_PROTOTYPE(TYPE)               \
EC_ARRAY_COPY_FUNCTION_PROTOTYPE(TYPE)              \
EC_ARRAY_REVERSE_FUNCTION_PROTOTYPE(TYPE)


#define EC_ARRAY_SORT_FUNCTION_PROTOTYPE(TYPE, SW)      \
void                                                    \
EC_ARRAY_SORT_FUNCTION_NAME(TYPE, SW)                   \
(                                                       \
    EC_ARRAY_STRUCT(TYPE)   *array                      \
);


#define EC_ARRAY_INT_FUNCTION_PROTOTYPE(TYPE, SW)       \
int                                                     \
EC_ARRAY_INT_FUNCTION_NAME(TYPE, SW)                    \
(                                                       \
    EC_ARRAY_STRUCT(TYPE)   *array,                     \
    int                     search_value                \
);


#define EC_ARRAY_STR_FUNCTION_PROTOTYPE(TYPE, SW)       \
int                                                     \
EC_ARRAY_STR_FUNCTION_NAME(TYPE, SW)                    \
(                                                       \
    EC_ARRAY_STRUCT(TYPE)   *array,                     \
    char                    *search_value               \
);


#define EC_ARRAY_MAX_FUNCTION_PROTOTYPE(TYPE, SW)       \
TYPE *                                                  \
EC_ARRAY_MAX_FUNCTION_NAME(TYPE, SW)                    \
(                                                       \
    EC_ARRAY_STRUCT(TYPE) *array                        \
);


#define EC_ARRAY_MIN_FUNCTION_PROTOTYPE(TYPE, SW)       \
TYPE *                                                  \
EC_ARRAY_MIN_FUNCTION_NAME(TYPE, SW)                    \
(                                                       \
    EC_ARRAY_STRUCT(TYPE) *array                        \
);


#define EC_ARRAY_SW_FUNCTION_PROTOTYPES(TYPE, SW)       /* SW for Search With or Sort With */\
    EC_ARRAY_SORT_FUNCTION_PROTOTYPE(TYPE, SW)          \
    EC_ARRAY_INT_FUNCTION_PROTOTYPE(TYPE, SW)           \
    EC_ARRAY_STR_FUNCTION_PROTOTYPE(TYPE, SW)           \
    EC_ARRAY_MAX_FUNCTION_PROTOTYPE(TYPE, SW)           \
    EC_ARRAY_MIN_FUNCTION_PROTOTYPE(TYPE, SW)


/* reverse int array */
void
Int_Array_Reverse
(
    int *array,
    int array_length
);


int*
Int_Array_Search
(
    int *array,
    int array_length,
    int search_value, // search search_value
    int search_times  // how much times search
);


int
Int_Sorted_Array_Search
(
    int *array,
    int array_length,
    int search_value
);


/* find maximum number in an integer array */
int
Int_Array_Max
(
    int *array,
    int array_length
);


/* find minimum number in an integer array */
int
Int_Array_Min
(
    int *array,
    int array_length
);


/* Function macros */

#define EC_ARRAY_FREE_VAR_FUNCTION(TYPE)                            \
void                                                                \
EC_ARRAY_FREE_VAR_FUNCTION_NAME(TYPE)                               \
(                                                                   \
    void *var                                                       \
)                                                                   \
{                                                                   \
    EC_ARRAY_STRUCT(TYPE) *v = (EC_ARRAY_STRUCT(TYPE) *) var;       \
    free (v->var);                                                  \
    v->var = NULL;                                                  \
    free (v);                                                       \
    v = NULL;                                                       \
}


#define EC_ARRAY_FREE_FUNCTION(TYPE)                                \
void                                                                \
EC_ARRAY_FREE_FUNCTION_NAME(TYPE)                                   \
(                                                                   \
    void *array                                                     \
)                                                                   \
{                                                                   \
    EC_ARRAY_STRUCT(TYPE) *a = (EC_ARRAY_STRUCT(TYPE) *) array;     \
    free (a->var);                                                  \
    a->var = NULL;                                                  \
    free (a);                                                       \
}


//#define EC_ARRAY_UNLOCK_FUNCTION(TYPE)                              \
//void                                                                \
//EC_ARRAY_UNLOCK_FUNCTION_NAME(TYPE)                                 \
//(                                                                   \
//    void *var                                                       \
//)                                                                   \
//{                                                                   \
//    EC_ARRAY_STRUCT(TYPE) *v = (EC_ARRAY_STRUCT(TYPE) *) var;       \
//    v->ec_mem->lock = EC_UNLOCK;                                    \
//}


#define EC_ARRAY_NEW_FUNCTION(TYPE)                                     \
EC_ARRAY_STRUCT(TYPE) *                                                 \
EC_ARRAY_NEW_FUNCTION_NAME(TYPE)                                        \
(                                                                       \
    int length                                                          \
)                                                                       \
{                                                                       \
    EC_VAR_CREATE(EC_ARRAY_STRUCT(TYPE), ec_array, __LINE__)            \
                                                                        \
    TYPE *array = (TYPE *) malloc (sizeof (TYPE) * length);             \
                                                                        \
    if (array == NULL)                                                  \
    {                                                                   \
        EC_Error_Mem_Alloc (__FILE__, __LINE__);                        \
        return NULL;                                                    \
    }                                                                   \
                                                                        \
    ec_array->length = length;                                          \
    ec_array->var = array;                                              \
																		\
	EC_Memory_Add(array); 												\
                                                                        \
    return ec_array;                                                    \
}


/* Array_Clone
 * This function return exact clone of ec array.
 * But there is no inter connection between original and the clone */
#define EC_ARRAY_COPY_FUNCTION(TYPE)                                                        \
EC_ARRAY_STRUCT(TYPE) *                                                                     \
EC_ARRAY_COPY_FUNCTION_NAME(TYPE)                                                           \
(                                                                                           \
    EC_ARRAY_STRUCT(TYPE) *array                                                            \
)                                                                                           \
{                                                                                           \
    EC_ARRAY_STRUCT(TYPE) *array_clone = EC_ARRAY_NEW_FUNCTION_NAME(TYPE) (array->length);  \
                                                                                            \
    memcpy (array_clone->var, array->var, sizeof(TYPE) * array->length);                    \
                                                                                            \
    array_clone->length = array->length;                                                    \
                                                                                            \
    return array_clone;                                                                     \
}


#define EC_ARRAY_REVERSE_FUNCTION(TYPE)                             \
void                                                                \
EC_ARRAY_REVERSE_FUNCTION_NAME(TYPE)                                \
(                                                                   \
    EC_ARRAY_STRUCT(TYPE) *array                                    \
)                                                                   \
{                                                                   \
    TYPE temp;                                                      \
                                                                    \
    for (int i = 0; i < (array->length) / 2; i++)                   \
    {                                                               \
        temp = array->var[i];                                       \
        array->var[i] = array->var[array->length - (1 + i)];        \
        array->var[array->length - 1 - i] = temp;                   \
    }                                                               \
}


#define EC_ARRAY_C(TYPE)        		\
    EC_ARRAY_FREE_FUNCTION(TYPE)        \
    EC_ARRAY_FREE_VAR_FUNCTION(TYPE)    \
    EC_ARRAY_NEW_FUNCTION(TYPE)         \
    EC_ARRAY_COPY_FUNCTION(TYPE)        \
    EC_ARRAY_REVERSE_FUNCTION(TYPE)


/* EC_Array_Sort */

#define EC_ARRAY_SORT_FUNCTION(TYPE, SW)                            \
void                                                                \
EC_ARRAY_SORT_FUNCTION_NAME(TYPE, SW)                               \
(                                                                   \
    EC_ARRAY_STRUCT(TYPE) *array                                    \
)                                                                   \
{                                                                   \
    TYPE *min_ref;                                                  \
    TYPE temp;                                                      \
                                                                    \
    int j = 0;                                                      \
    int i = 0;                                                      \
                                                                    \
    for (i; i < array->length - 1; i++)                             \
    {                                                               \
        min_ref = &array->var[i];                                   \
                                                                    \
        for (j = i + 1; j < array->length; j++)                     \
        {                                                           \
            if (array->var[j].SW < min_ref->SW)                     \
            {                                                       \
                min_ref = &array->var[j];                           \
            }                                                       \
        }                                                           \
                                                                    \
        temp = array->var[i];                                       \
        array->var[i] = *min_ref;                                   \
        *min_ref = temp;                                            \
    }                                                               \
}


/* Array Search */

#define EC_ARRAY_INT_FUNCTION(TYPE, SW)                             \
int                                                                 \
EC_ARRAY_INT_FUNCTION_NAME(TYPE, SW)                                \
(                                                                   \
    EC_ARRAY_STRUCT(TYPE)   *array,                                 \
    int                     search_value                            \
)                                                                   \
{                                                                   \
    TYPE *a;                                                        \
    for_array (array, a)                                            \
    {                                                               \
        if (a->SW == search_value)                                  \
        {                                                           \
            return EC_CONCAT(a, _i);                                \
        }                                                           \
    }                                                               \
                                                                    \
    return -1;                                                      \
}


#define EC_ARRAY_STR_FUNCTION(TYPE, SW)                             \
int                                                                 \
EC_ARRAY_STR_FUNCTION_NAME(TYPE, SW)                                \
(                                                                   \
    EC_ARRAY_STRUCT(TYPE)   *array,                                 \
    char                    *search_value                           \
)                                                                   \
{                                                                   \
    TYPE *a;                                                        \
    for_array (array, a)                                            \
    {                                                               \
        if (strcmp(a->SW, search_value) == 0)                       \
        {                                                           \
            return EC_CONCAT(a, _i);                                \
        }                                                           \
    }                                                               \
                                                                    \
    return -1;                                                      \
}


/* do it with internal refference sort array and keep it in global */
#define EC_ARRAY_SORTED_INT_FUNCTION(TYPE, SW)                      \
int                                                                 \
EC_ARRAY_SORTED_INT_FUNCTION_NAME(TYPE, SW)                         \
(                                                                   \
    EC_ARRAY_STRUCT(TYPE)   *array,                                 \
    int                     search_value                            \
)                                                                   \
{                                                                   \
    int lei, uei, mi;                                               /* lei = lower end index, uei = upper end index, mi = mid index */\
                                                                    \
    lei = 0;                                                        \
    uei = array->length - 1;                                        \
    mi = (lei + uei) / 2;                                           \
                                                                    \
    if (search_value < array->var[lei].SW)                        /* Search value is lower than minimum value */ \
    {                                                               \
        return -1;                                                  \
    }                                                               \
    else if (search_value > array->var[uei].SW)                   /* Search value is grater than maximum value */ \
    {                                                               \
        return -1;                                                  \
    }                                                               \
                                                                    \
    while (1)                                                       \
    {                                                               \
        printf ("lei %d uei %d mi %d\n", lei, uei, mi);             \
                                                                    \
        if (search_value == array->var[mi].SW)                      \
        {                                                           \
            printf ("mi %d\n", mi);                                 \
            return mi;                                              \
        }                                                           \
        else if (search_value == array->var[lei].SW)                \
        {                                                           \
            printf ("lei %d\n", lei);                               \
            return lei;                                             \
        }                                                           \
        else if (search_value == array->var[uei].SW)                \
        {                                                           \
            printf ("uei %d\n", uei);                               \
            return uei;                                             \
        }                                                           \
        else if (search_value > array->var[mi].SW)                  \
        {                                                           \
            printf ("v > mi\n");                                    \
            lei = mi + 1;                                           \
            uei = uei - 1;                                          \
            mi = (lei + uei) / 2;                                   \
        }                                                           \
        else                                                        \
        {                                                           \
            printf ("v < mi\n");                                    \
            uei = mi - 1;                                           \
            lei = lei + 1;                                          \
            mi = (lei + uei) / 2;                                   \
        }                                                           \
                                                                    \
        if (lei == uei)                                             \
        {                                                           \
            if (search_value == array->var[lei].SW)                 \
            {                                                       \
                printf ("lei = uei %d\n", lei);                     \
                return lei;                                         \
            }                                                       \
            else                                                    \
            {                                                       \
                printf ("No search result found lei %d uei %d\n",   \
                        lei, uei);                                  \
                return -1;                                          \
            }                                                       \
        }                                                           \
    }                                                               \
}


/* Search maximum var according to var attribute SW */

#define EC_ARRAY_MAX_FUNCTION(TYPE, SW)             \
TYPE *                                              \
EC_ARRAY_MAX_FUNCTION_NAME(TYPE, SW)                \
(                                                   \
    EC_ARRAY_STRUCT(TYPE)   *array                  \
)                                                   \
{                                                   \
    TYPE *max = &array->var[0];                     \
                                                    \
    for (int i = 1; i < array->length; i++)         \
    {                                               \
        if (array->var[i].SW > max->SW)             \
        {                                           \
            max = &array->var[i];                   \
        }                                           \
    }                                               \
                                                    \
    return max;                                     \
}


/* Search minimum var according to var attribute SW */

#define EC_ARRAY_MIN_FUNCTION(TYPE, SW)             \
TYPE *                                              \
EC_ARRAY_MIN_FUNCTION_NAME(TYPE, SW)                \
(                                                   \
    EC_ARRAY_STRUCT(TYPE) *array                    \
)                                                   \
{                                                   \
    TYPE *min = &array->var[0];                     \
                                                    \
    for (int i = 1; i < array->length; i++)         \
    {                                               \
        if (array->var[i].SW < min->SW)             \
        {                                           \
            min = &array->var[i];                   \
        }                                           \
    }                                               \
                                                    \
    return min;                                     \
}


#define EC_ARRAY_SW_FUNCTIONS(TYPE, SW)             /* SW for Search With or Sort With */ \
    EC_ARRAY_SORT_FUNCTION(TYPE, SW)                \
    EC_ARRAY_INT_FUNCTION(TYPE, SW)                 \
    EC_ARRAY_MAX_FUNCTION(TYPE, SW)                 \
    EC_ARRAY_MIN_FUNCTION(TYPE, SW)


#define EC_ARRAY(TYPE) 					\
	EC_ARRAY_H(TYPE)					\
	EC_ARRAY_C(TYPE)

#endif // __EC_ARRAY_H__
