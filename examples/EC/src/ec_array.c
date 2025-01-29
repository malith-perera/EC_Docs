#include "ec_array.h"

/* Todo
 * binary search
 * reverse array
 * resize array
 * sort array
 */

/* reverse int array */

void
Int_Array_Reverse
(
    int  *array,
    int  array_count
)
{
    int temp;

    for (int i = 0; i < array_count / 2; i++)
    {
        temp = array[i];
        array[i] = array[array_count - 1 - i];
        array[array_count - 1 - i] = temp;
    }
}


/* Search integer array */
// return array index if found else NULL if not found

/* Search int array
 * count = 0 -> find all.
 * count = 1,2,3,.. from begin to end.
 * count = -1, -2, -3, from end to begin */


// ********* reverse search is a good idea


int*
Int_Array_Search
(
    int *array,
    int  array_count,
    int  search_value, // search search_value
    int  search_times  // how much times search
)
{
    int array_index[search_times]; // ***** use list here

    int counter = 0;

    for (int i = 0; i < array_count; i++)
    {
        if (array[i] == search_value)
        {
            array_index[counter] = i;
            counter++;

            if (search_times == counter)
            {
                //return array_index;
            }
        }
    }

    return NULL;  // if not search value found
}


/* Binary search sorted integer array */
// return array index if found else return -1 if not found

int
Int_Sorted_Array_Search
(
    int  *array,
    int  array_count,
    int  search_value
)
{
    int lei, uei, mi;  // lei = lower end index, uei = upper end index, mi = mid index

    lei = 0;
    uei = array_count - 1;
    mi = (lei + uei) / 2;

    if (search_value < array[lei] )
    {
        printf ("Search value is lower than minimum value\n");
        return -1;
    }
    else if (search_value > array[uei])
    {
        printf ("Search value is grater than maximum value\n");
        return -1;
    }

    while (1)
    {
        printf ("lei %d uei %d mi %d\n", lei, uei, mi);

        if (search_value == array[mi])
        {
            printf ("mi %d\n", mi);
            return mi;
        }
        else if (search_value == array[lei])
        {
            printf ("lei %d\n", lei);
            return lei;
        }
        else if (search_value == array[uei])
        {
            printf ("uei %d\n", uei);
            return uei;
        }
        else if (search_value > array[mi])
        {
            printf ("search_value > mi\n");
            lei = mi + 1;
            uei = uei - 1;
            mi = (lei + uei) / 2;
        }
        else
        {
            printf ("search_value < mi\n");
            uei = mi - 1;
            lei = lei + 1;
            mi = (lei + uei) / 2;
        }

        if (lei == uei)
        {
            if (search_value == array[lei])
            {
                printf ("lei = uei %d\n", lei);
                return lei;
            }
            else
            {
                printf ("No search result found lei %d uei %d\n", lei, uei);
                return -1;
            }
        }
    }
}


/* Find maximum number in an integer array */
int
Int_Array_Max
(
    int  *array,
    int  array_count
)
{
    int max = array[0];

    for (int i = 1; i < array_count; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    return max;
}


/* Find minimum number in an integer array */
int
Int_Array_Min
(
    int  *array,
    int  array_count
)
{
    int min = array[0];

    for (int i = 1; i < array_count; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }

    return min;
}
