#ifndef EC_STRING
#define EC_STRING

#include "ec.h"
#include "ec_list.h"

void
EC_Char_Substitute (char *str, char str_from, char str_to);


void
EC_Flush();


#endif // EC_STRING


#if 0
// Change all capital letters in to simple in an array
void
EC_Simplize(char word[]);

void
EC_Capitalize(char word[]);

struct _StrList
{
  char *line;
  struct _StrList *nextPtr;
};

typedef struct _StrList StrList;
typedef StrList * StrListPtr;

void
insert_line (StrListPtr *sPtr, char *line,  int line_no);

void
print_line (StrListPtr currentPtr, int line);

void
print_list (StrListPtr currentPtr);



#endif
