#include "ec.h"


#ifndef __EC_MEMORY_H__
#define __EC_MEMORY_H__

typedef struct Memory {
    void *ptr;
    struct Memory *next;
} Memory;


extern Memory *memory;

void EC_Memory_Add(void *ptr);
void Clean();
void Free(void *ptr);


#ifdef EC_MEMORY
#define EC_MEMORY_REF       \
    Memory *ec_mem;
#else
#define EC_MEMORY_REF
#endif //EC_MEMORY

#endif // __EC_MEMORY_H__
