#ifndef __EC_TIME_H__
#define __EC_TIME_H__

#include "ec.h"
#include <time.h>

extern int month_days[12];

typedef struct EC_Date {
    int year;
    int month;
    int day;
} EC_Date;


typedef struct EC_Time {
    int hour;
    int min;
    int sec;
} EC_Time;


EC_Time *
Set_Time(EC_Time *time, int hour, int min, int sec);

EC_Date *
Set_Date(EC_Date *date, int year, int month, int day);

char *
Date_To_Str(int year, int month, int day);

EC_Date *
Str_To_Date(EC_Date *date, char *date_str, const char *seperator);

struct tm *
EC_Time_Difference(struct tm *begin, struct tm *end);

char *
EC_Age(EC_Date *age, char *date_str);

char *
EC_Version(char *f_release);

#endif // __EC_TIME_H__
