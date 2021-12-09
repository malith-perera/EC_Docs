#ifndef EC_ERROR_H
#define EC_ERROR_H

#include "ec.h"

void
EC_Print_Error
(
  char *test,
  char *result
);

#define EC_ERROR_MEM_ALLOC()   \
    fprintf(stderr, "Error: Cannot allocate memory in file:%s: %d\n", __FILE__, __LINE__);


#endif // EC_ERROR_H
