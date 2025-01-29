#ifndef EC_VERSION_H
#define EC_VERSION_H

#include "ec.h"

#define EC_VERSION_YEARS 0
#define EC_VERSION_MONTHS 0
#define EC_VERSION_ADD_FIX 0

void
EC_Version_Change
(
    char    *argv[],
    char    *path,
    int     years,
    int     months,
    int     days
);

void
EC_Version_Update(char *argv[], char *path);


#endif // EC_VERSION_H
