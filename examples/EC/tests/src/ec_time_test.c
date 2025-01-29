#include "ec_time_test.h"

void
Test_Set_Time()
{
    EC_Time time;
    Set_Time(&time, 12, 30, 10);

    assert(time.hour == 12);
    assert(time.min == 30);
    assert(time.sec == 10);
}


void
Test_Set_Date()
{
    EC_Date *date = Set_Date(NULL, 2024, 5, 10);

    assert(date->year == 2024);
    assert(date->month == 5);
    assert(date->day == 10);
}


void
Test_Str_To_Date()
{
    EC_Date date;
    Str_To_Date(&date, "1981-02-8", "-");

    assert(date.year == 1981);
    assert(date.month == 2);
    assert(date.day == 8);

    EC_Date *date2 = Str_To_Date(NULL, "2011-09-23", "-");
    assert(date2->year == 2011);
    assert(date2->month == 9);
    assert(date2->day == 23);
}


void
EC_Time_Assign(struct tm *dtm, long int year, long int yday, long int hour, long int min, long int sec)
{
    dtm->tm_year = year;
    dtm->tm_yday = yday;
    dtm->tm_hour = hour;
    dtm->tm_min = min;
    dtm->tm_sec = sec;
}


void
Test_EC_Time_Difference()
{
    struct tm *difference, begin, end;

    // Check for same date time
    EC_Time_Assign(&begin, 2024, 200, 16, 30, 20);
    EC_Time_Assign(&end, 2024, 200, 16, 30, 20);

    difference = EC_Time_Difference(&begin, &end);
    assert(difference->tm_year == 0);
    assert(difference->tm_yday == 0);
    assert(difference->tm_hour == 0);
    assert(difference->tm_min == 0);
    assert(difference->tm_sec == 0);

    // Increase end tm_year
    EC_Time_Assign(&end, 2025, 200, 16, 30, 20);
    difference = EC_Time_Difference(&begin, &end);
    assert (difference->tm_year == 1);

    // Increase end tm_yday than begin tm_yday 
    EC_Time_Assign(&end, 2025, 250, 16, 30, 20);
    difference = EC_Time_Difference(&begin, &end);
    assert (difference->tm_year == 1);

    // decrease end tm_yday than begin tm_yday 
    EC_Time_Assign(&end, 2025, 100, 16, 30, 20);
    difference = EC_Time_Difference(&begin, &end);
    assert (difference->tm_year == 0);

    // Increase end tm_hour than begin tm_hour
    EC_Time_Assign(&end, 2025, 200, 18, 30, 20);
    difference = EC_Time_Difference(&begin, &end);
    assert (difference->tm_hour == 2);

    // Decrease end tm_hour than begin tm_hour
    EC_Time_Assign(&end, 2025, 200, 15, 30, 20);
    difference = EC_Time_Difference(&begin, &end);
    assert (difference->tm_hour == 23);

    // Increase end tm_min than begin tm_min
    EC_Time_Assign(&end, 2025, 200, 16, 40, 20);
    difference = EC_Time_Difference(&begin, &end);
    assert (difference->tm_min == 10);

    // Decrease end tm_min than begin tm_min
    EC_Time_Assign(&end, 2025, 200, 16, 20, 20);
    difference = EC_Time_Difference(&begin, &end);
    assert (difference->tm_min == 50);
    
    // Increase end tm_sec than begin tm_sec
    EC_Time_Assign(&end, 2025, 200, 16, 30, 30);
    difference = EC_Time_Difference(&begin, &end);
    assert (difference->tm_sec == 10);

    // Decrease end tm_sec than begin tm_sec
    EC_Time_Assign(&end, 2025, 100, 16, 30, 10);
    difference = EC_Time_Difference(&begin, &end);
    assert(difference->tm_sec == 50);
    assert(difference->tm_min == 59);
    assert(difference->tm_hour == 23);
    assert(difference->tm_yday == 265);
    assert(difference->tm_year == 0);

    // Increase end tm_year than begin
    EC_Time_Assign(&end, 2028, 100, 16, 30, 10);
    difference = EC_Time_Difference(&begin, &end);
    assert(difference->tm_sec == 50);
    assert(difference->tm_min == 59);
    assert(difference->tm_hour == 23);
    assert(difference->tm_yday == 265);
    assert(difference->tm_year == 3);

    // Increase end tm_year and tm_yday than begin
    EC_Time_Assign(&end, 2028, 210, 16, 30, 10);
    difference = EC_Time_Difference(&begin, &end);
    assert(difference->tm_sec == 50);
    assert(difference->tm_min == 59);
    assert(difference->tm_hour == 23);
    assert(difference->tm_yday == 9);
    assert(difference->tm_year == 4);
}

void
Test_EC_Age()
{
    EC_Date age;
    EC_Age(&age, "1981-02-08");
}


void
Run_Time_Test()
{
    Test_Set_Time();
    printf("\n");

    Test_Set_Date();
    printf("\n");

    Test_Str_To_Date();
    printf("\n");

    Test_EC_Time_Difference();
    printf("\n");
}
