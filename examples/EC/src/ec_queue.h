#ifndef __EC_QUEUE_H__
#define __EC_QUEUE_H__

#include "ec.h"

#define for_queue(queue)                                                                                                                                \
    for (queue->queue_var = queue->first, queue->var = queue->queue_var != NULL ? queue->queue_var->var: NULL;                                          \
         queue->queue_var != NULL;                                                                                                                      \
         queue->queue_var = queue->queue_var != NULL ? queue->queue_var->next: NULL, queue->var = queue->queue_var != NULL ? queue->queue_var->var: NULL)

#define EC_QUEUE_VAR_FREE_FUNCTION_NAME(TYPE)       EC_CONCAT2(TYPE, _Queue_Var_Free)
#define EC_QUEUE_FREE_FUNCTION_NAME(TYPE)           EC_CONCAT2(TYPE, _Queue_Free)
#define EC_QUEUE_NEW_FUNCTION_NAME(TYPE)            EC_CONCAT2(TYPE, _Queue)
#define EC_QUEUE_NEW_VAR_FUNCTION_NAME(TYPE)        EC_CONCAT2(TYPE, _Queue_Var)
#define EC_QUEUE_COPY_FUNCTION_NAME(TYPE)           EC_CONCAT2(TYPE, _Queue_Copy)

#define EC_QUEUE_DROP_FUNCTION_NAME(TYPE)           EC_CONCAT2(Drop_, TYPE)
#define EC_QUEUE_ENQUEUE_FUNCTION_NAME(TYPE)        EC_CONCAT2(TYPE, _Enqueue)
#define EC_QUEUE_DEQUEUE_FUNCTION_NAME(TYPE)        EC_CONCAT2(TYPE, _Dequeue)


/* Structure macros */
// defined in ec_memory.h
#define EC_QUEUE_STRUCT(TYPE)                       EC_CONCAT2(TYPE, Queue)
#define EC_QUEUE_VAR_STRUCT(TYPE)                   EC_CONCAT2(TYPE, QueueVar)


#define EC_QUEUE_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)          \
void                                                        \
EC_QUEUE_VAR_FREE_FUNCTION_NAME(TYPE)                       \
(                                                           \
    EC_QUEUE_STRUCT(TYPE) *queue                            \
);


#define EC_QUEUE_FREE_FUNCTION_PROTOTYPE(TYPE)              \
void                                                        \
EC_QUEUE_FREE_FUNCTION_NAME(TYPE)                           \
(                                                           \
    void *var                                               \
);


#define EC_QUEUE_NEW_FUNCTION_PROTOTYPE(TYPE)               \
EC_QUEUE_STRUCT(TYPE) *                                     \
EC_QUEUE_NEW_FUNCTION_NAME(TYPE)                            \
();


#define EC_QUEUE_NEW_VAR_FUNCTION_PROTOTYPE(TYPE)           \
EC_QUEUE_VAR_STRUCT (TYPE) *                                \
EC_QUEUE_NEW_VAR_FUNCTION_NAME(TYPE)                        \
();


#define EC_QUEUE_ENQUEUE_FUNCTION_PROTOTYPE(TYPE)           \
void                                                        \
EC_QUEUE_ENQUEUE_FUNCTION_NAME(TYPE)                        \
(                                                           \
    EC_QUEUE_STRUCT(TYPE)   *queue,                         \
    TYPE                    *var                            \
);


#define EC_QUEUE_DEQUEUE_FUNCTION_PROTOTYPE(TYPE)           \
EC_QUEUE_VAR_STRUCT(TYPE) *                                 \
EC_QUEUE_DEQUEUE_FUNCTION_NAME(TYPE)                        \
(                                                           \
    EC_QUEUE_STRUCT(TYPE) *queue                            \
);


#define EC_QUEUE_COPY_FUNCTION_PROTOTYPE(TYPE)              \
EC_QUEUE_STRUCT(TYPE) *                                     \
EC_QUEUE_COPY_FUNCTION_NAME(TYPE)                           \
(                                                           \
    EC_QUEUE_STRUCT(TYPE) *queue                            \
);


#define EC_QUEUE_H(TYPE)                            \
    typedef struct EC_QUEUE_VAR_STRUCT(TYPE){       \
        TYPE                             *var;      \
        struct EC_QUEUE_VAR_STRUCT(TYPE) *next;     \
    } EC_QUEUE_VAR_STRUCT(TYPE);                    \
                                                    \
    typedef struct EC_QUEUE_STRUCT(TYPE){           \
        EC_QUEUE_VAR_STRUCT(TYPE)   *first;         \
        EC_QUEUE_VAR_STRUCT(TYPE)   *last;          \
        TYPE                        *var;           \
        EC_QUEUE_VAR_STRUCT(TYPE)   *queue_var;     \
        EC_MEMORY_REF                               \
    } EC_QUEUE_STRUCT(TYPE);                        \
                                                    \
    EC_QUEUE_VAR_FREE_FUNCTION_PROTOTYPE(TYPE)      \
    EC_QUEUE_FREE_FUNCTION_PROTOTYPE(TYPE)          \
    EC_QUEUE_NEW_FUNCTION_PROTOTYPE(TYPE)           \
    EC_QUEUE_NEW_VAR_FUNCTION_PROTOTYPE(TYPE)       \
    EC_QUEUE_ENQUEUE_FUNCTION_PROTOTYPE(TYPE)       \
    EC_QUEUE_DEQUEUE_FUNCTION_PROTOTYPE(TYPE)       \
    EC_QUEUE_COPY_FUNCTION_PROTOTYPE(TYPE)


/* Function macros */

#define EC_QUEUE_VAR_FREE_FUNCTION(TYPE)                    \
void                                                        \
EC_QUEUE_VAR_FREE_FUNCTION_NAME(TYPE)                       \
(                                                           \
    EC_QUEUE_STRUCT(TYPE) *queue                            \
)                                                           \
{                                                           \
    EC_QUEUE_VAR_STRUCT(TYPE) *temp = NULL;                 \
    if (queue->first != NULL)                               \
    {                                                       \
        temp = queue->first;                                \
        if (queue->first->next != NULL)                     /* not the last one */\
        {                                                   \
            queue->first = queue->first->next;              \
        }                                                   \
        else                                                /* last one */\
        {                                                   \
            queue = NULL;                                   \
            queue->first = NULL;                            \
            queue->last = NULL;                             \
        }                                                   \
                                                            \
        free (temp);                                        \
    }                                                       \
}


#define EC_QUEUE_FREE_FUNCTION(TYPE)                            \
void                                                            \
EC_QUEUE_FREE_FUNCTION_NAME(TYPE)                               \
(                                                               \
    void *var                                                   \
)                                                               \
{                                                               \
    EC_QUEUE_STRUCT(TYPE) *v = (EC_QUEUE_STRUCT(TYPE)*) var;    \
}


#define EC_QUEUE_NEW_FUNCTION(TYPE)                                     \
EC_QUEUE_STRUCT(TYPE) *                                                 \
EC_QUEUE_NEW_FUNCTION_NAME(TYPE)                                        \
()                                                                      \
{                                                                       \
    EC_VAR_CREATE(EC_QUEUE_STRUCT(TYPE), new_queue, __LINE__);          /* TYPE *var is in this macro in ec_var.h*/ \
                                                                        \
    return new_queue;                                                   \
}


/* New Queue Variable Function */

#define EC_QUEUE_NEW_VAR_FUNCTION(TYPE)                                 \
EC_QUEUE_VAR_STRUCT(TYPE) *                                             \
EC_QUEUE_NEW_VAR_FUNCTION_NAME(TYPE)                                    \
()                                                                      \
{                                                                       \
}


/* Queue Functions */

#define EC_QUEUE_ENQUEUE_FUNCTION(TYPE)         \
void                                            \
EC_QUEUE_ENQUEUE_FUNCTION_NAME(TYPE)            \
(                                               \
    EC_QUEUE_STRUCT(TYPE)   *queue,             \
    TYPE                    *var                \
)                                               \
{                                               \
    EC_VAR_CREATE(EC_QUEUE_VAR_STRUCT(TYPE), queue_var, __LINE__);    \
    queue_var->var = var;                       \
                                                \
    if (queue->first != NULL)                   \
    {                                           \
        queue->last->next = queue_var;          \
        queue->last = queue_var;                \
    }                                           \
    else                                        /* no vars in queue */ \
    {                                           \
        queue->first = queue_var;               \
        queue->last = queue_var;                \
    }                                           \
}


#define EC_QUEUE_DEQUEUE_FUNCTION(TYPE)                     \
EC_QUEUE_VAR_STRUCT(TYPE) *                                 \
EC_QUEUE_DEQUEUE_FUNCTION_NAME(TYPE)                        \
(                                                           \
    EC_QUEUE_STRUCT(TYPE) *queue                            \
)                                                           \
{                                                           \
    EC_QUEUE_VAR_STRUCT(TYPE) *queued_var = NULL;           \
                                                            \
    if (queue->first != NULL)                               \
    {                                                       \
        queued_var = queue->first;                          \
        queue->first = queue->first->next;                  \
        if (queue->first == NULL) queue->last = NULL;       \
                                                            \
        return queued_var;                                  \
        /* should do something to free var after use */     \
    }                                                       \
    else                                                    \
    {                                                       \
        return NULL;                                        \
    }                                                       \
}


// Copy queue
#define EC_QUEUE_COPY_FUNCTION(TYPE)                                        \
EC_QUEUE_STRUCT(TYPE) *                                                     \
EC_QUEUE_COPY_FUNCTION_NAME(TYPE)                                           \
(                                                                           \
    EC_QUEUE_STRUCT(TYPE) *queue                                            \
)                                                                           \
{                                                                           \
    EC_QUEUE_STRUCT(TYPE) *queue_copy = EC_QUEUE_NEW_FUNCTION_NAME(TYPE)(); \
                                                                            \
    EC_QUEUE_VAR_STRUCT(TYPE) *var;                                         \
                                                                            \
    for_queue(queue)                                                        \
    {                                                                       \
        EC_QUEUE_ENQUEUE_FUNCTION_NAME(TYPE)(queue_copy, queue->var);       \
    }                                                                       \
                                                                            \
    return queue_copy;                                                      \
}


#define EC_QUEUE_C(TYPE)                \
    EC_QUEUE_VAR_FREE_FUNCTION(TYPE)    \
    EC_QUEUE_FREE_FUNCTION(TYPE)        \
    EC_QUEUE_NEW_FUNCTION(TYPE)         \
    EC_QUEUE_NEW_VAR_FUNCTION(TYPE)     \
    EC_QUEUE_ENQUEUE_FUNCTION(TYPE)     \
    EC_QUEUE_DEQUEUE_FUNCTION(TYPE)     \
    EC_QUEUE_COPY_FUNCTION(TYPE)


#define EC_QUEUE(TYPE) 		\
	EC_QUEUE_H(TYPE) 		\
	EC_QUEUE_C(TYPE)


#endif // __EC_QUEUE_H__
