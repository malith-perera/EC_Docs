#ifndef EC_MEMORY_H
#define EC_MEMORY_H

#include "ec_list.h"
#include "ec.h"

#ifdef EC_MEMORY
#define EC_MEMORY_REF     \
    ECMemory* mem_ref;    \
    bool lock;
#else
#define EC_MEMORY_REF
#endif //EC_MEMORY


#define EC_MEM_VARS                             \
    ECType              type;                   \
    void*               var;                    \
    void*               memory;                 \
    void                (*Free_Func) (void*);   \
    bool                lock;


EC_LIST(ECMemory, EC_MEM_VARS)
EC_LIST_FUNCTION_PROTOTYPES(ECMemory)

void
EC_Clean ();


#define ec_unlock(EC_VAR)       \
    EC_VAR->lock = false;       \
    EC_VAR->mem-lock = false;


#define ec_arrary_free(EC_VAR)      \
    free(EC_VAR->index);


#define ec_memory_free(EC_VAR)                              \
    EC_VAR->mem_ref->previous = EC_VAR->mem_ref->next;      \
    free(EC_VAR->mem_ref);                                  \
    free(EC_VAR);


#endif // EC_MEMORY_H
