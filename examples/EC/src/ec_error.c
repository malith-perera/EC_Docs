#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include "ec_error.h"


void
EC_Error_Print_Msg (char *msg, char *result)
{
    printf ("%-50s %s\n", msg, result);
}


void
EC_Print_Error (char *msg, void *adrs)
{
    printf ("%-50s %p\n", msg, adrs);
}

// EC_Error_Mem_Alloc (__FILE__, __LINE__);
// EC_ERROR_MEM_ALLOC() relative macro is available
void
EC_Error_Mem_Alloc (char* file, int line)
{
    fprintf(stderr, "Error: Cannot allocate memory in file:%s: %d\n", file, line);
}

#if 0

void
ec_file_open_error ()
{
  FILE *fptr;

  fptr = fopen("nofile", "r");

  printf("Value of errno: %d\n", errno);
  printf("Error opening the file: %s\n", strerror(errno));
  perror("Error printed by perror");
}

#endif
