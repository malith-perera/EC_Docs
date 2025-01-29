#include "ec_memory.h"

#define DEBUG_EC_MEMORY 1

Memory *memory;


void EC_Memory_Add(void *ptr)
{
    Memory *temp;

    Memory *m = (Memory *) malloc (sizeof(Memory));
    m->ptr = ptr;

    m->next = memory;
    memory = m;
}


void Clean()
{
    Memory *temp = NULL;
    Memory *current = NULL;

    current = memory;

    while (current != NULL) {
        temp = current;
        current = current->next;

        if (temp != NULL) {
            free(temp->ptr);
            free(temp);

            temp = NULL;
            temp->ptr == NULL;
        }
    }

    memory = NULL;
}


void
Free(void *ptr)
{
    Memory *current = memory, *previous;

    // If ptr is the first item
    if (current != NULL && current->ptr == ptr) {
        memory = current->next;
        free(current->ptr);
        free(current);
        current->ptr = NULL;
        current = NULL;
        return;
    }

    // Search till find ptr
    while (current != NULL && current->ptr != ptr) {
        previous = current;
        current = current->next;
    }

    // If ptr is not in the list
    if (current == NULL) return;

    // Free 
    previous->next = current->next;
    free(current->ptr);
    free(current);
    current->ptr = NULL;
    current = NULL;
}
