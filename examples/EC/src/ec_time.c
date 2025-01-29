#include "ec_time.h"


int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

EC_Time *
Set_Time(EC_Time *time, int hour, int min, int sec)
{
    if(time == NULL) {
        time = (EC_Time *) malloc(sizeof(EC_Time));
        printf ("time\n");
    }

    time->hour = hour;
    time->min = min;
    time->sec = sec;

    return time;
}


EC_Date *
Set_Date(EC_Date *date, int year, int month, int day)
{
    if(date == NULL) {
        date = (EC_Date *) malloc(sizeof(EC_Date));
        printf ("date\n");
    }

    date->year = year;
    date->month = month;
    date->day = day;

    return date;
}


char *
Date_To_Str(int year, int month, int day)
{
    char *date_str = (char *) malloc(sizeof(char) * 32);

    if (month < 10 && day < 10) {
        sprintf(date_str, "%d-0%d-0%d", year, month, day);
    }
    else if(month < 10)
        sprintf(date_str, "%d-0%d-%d", year, month, day);
    else if (day < 10) {
        sprintf(date_str, "%d-%d-0%d", year, month, day);
    }
    else {
        sprintf(date_str, "%d-%d-%d", year, month, day);
    }

    return date_str;
}


EC_Date *
Str_To_Date(EC_Date *date, char *date_str, const char *seperator)
{
    if(date == NULL) {
        date = (EC_Date *) malloc(sizeof(EC_Date));
    }

    char str_date[11];
    memcpy (str_date, date_str, 11);

    char *token = strtok(str_date, seperator);
    date->year = atoi(token); 
    token = strtok(NULL, seperator);
    date->month = atoi(token); 
    token = strtok(NULL, seperator);
    date->day = atoi(token); 

    return date;
}


struct tm *
EC_Time_Difference(struct tm *begin, struct tm *end)
{
    long int total_begin = 0;
    long int total_end = 0;
    long int difference = 0;
    long int year_difference = 0;
    long int day_difference = 0;

    struct tm *tm_diff;

    // time difference
    total_begin = begin->tm_hour * 3600 + begin->tm_min * 60 + begin->tm_sec;
    total_end = end->tm_hour * 3600 + end->tm_min * 60 + end->tm_sec;

    if (total_end >= total_begin) {
        difference = total_end - total_begin;
    }
    else {
        difference = 24 * 3600 - total_begin + total_end;
        if(end->tm_yday >= 1)
            end->tm_yday -= 1;
        else if (end->tm_yday == 0) {
            if (end->tm_year % 4 == 0) {
                end->tm_yday = 365;
                end->tm_year -= 1;
            }
            else {
                end->tm_yday = 364;
                end->tm_year -= 1;
            }
        }
    }
    
    tm_diff->tm_hour = difference / 3600;
    tm_diff->tm_min = difference % 3600 / 60;
    tm_diff->tm_sec = (difference % 3600) % 60;

    // day difference
    if (begin->tm_yday <= end->tm_yday) {
        day_difference = end->tm_yday - begin->tm_yday;   
        year_difference = end->tm_year - begin->tm_year;
    }
    else {
        if (begin->tm_year % 4 == 0) { // long year
            day_difference = 366 - begin->tm_yday + end->tm_yday;
        }
        else {
            day_difference = 365 - begin->tm_yday + end->tm_yday;
        }

        if(begin->tm_year < end->tm_year)
            year_difference = end->tm_year - begin->tm_year - 1;
    }

    tm_diff->tm_yday = day_difference;
    tm_diff->tm_year = year_difference;
    
    return tm_diff;
}


EC_Date *
EC_Date_Difference(EC_Date *date_diff, EC_Date *old, EC_Date *new)
{
    int days_per_month;

    // days
    if (old->day <= new->day) {
        date_diff->day = new->day - old->day;   
    }
    else {
        days_per_month = month_days[old->month];

        if(old->month == 1 && old->year % 4 == 0)
            days_per_month++;

        date_diff->day = days_per_month - old->day + new->day;
    }

    // months
    if (new->month >= old->month) {
        date_diff->month = new->month - old->month;
    }
    else {
        new->month += 12; 
        date_diff->month = new->month - old->month;
        if (new->year > 0)
            new->year--;
    }

    //years
    if(old->year < new->year)
        date_diff->year = new->year - old->year;

    return date_diff;
}


char *
EC_Age(EC_Date *age, char *date_str)
{
    time_t t;

    EC_Date date;
    EC_Date today;
    struct tm *dt;

    Str_To_Date(&date, date_str, "-");

    dt = localtime(&t);

    today.year = dt->tm_year;
    today.month = dt->tm_mon;
    today.day = dt->tm_mday;
}




char *
EC_Version(char *f_release)
{
    char release[10];
    memcpy(&release, f_release, 10);
}
