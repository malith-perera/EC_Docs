#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ec_string.h"


void
EC_Char_Substitute (char *str, char str_from, char str_to)
{
    while (*str == str_from)
        *str++ = str_to;
}


void
EC_Flush()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) ;
}

#if 0

void
EC_Simplize(char word[])
{
    for(int i = 0; i < strlen(word); i++)
    {
        if (word[i] >= 'A'  && word[i] <= 'Z')
            word[i] = word[i] + 32;
    }

}


void
EC_Capitalize(char word[])
{
    for(int i = 0; i < strlen(word); i++)
    {
        if (word[i] >= 'a'  && word[i] <= 'z')
            word[i] = word[i] - 32;
    }
}


char*
toLower(char* s) {
  for(char *p=s; *p; p++) *p=tolower(*p);
  return s;
}


char*
toUpper(char* s) {
  for(char *p=s; *p; p++) *p=toupper(*p);
  return s;
}





void
EC_Fgets(char str[], int n) {
    fgets(str, strlen(str), stdin);
}

void
EC_Option ()
{
    char option;

    do {
        option = getchar();
        while(getchar() != '\n'); // Discard line feed
    } while (option != 'q');
}









CharListPtr
Char_List (char string[])
{
  CharListPtr objPtr = NULL;
  init (&objPtr, string);
  return objPtr;
}


void
init (CharListPtr *sPtr, char string[])
{
  size_t size = strlen (string);
  CharListPtr newPtr;
  CharListPtr previousPtr;
  CharListPtr currentPtr;
  int i = 1;

  for (i = 0; i < size; i++)
  {
    newPtr = malloc (sizeof (CharList));

    if (newPtr != NULL )
    {
      newPtr->charactor = string[i];
      newPtr->nextPtr = NULL;

      previousPtr = NULL;
      currentPtr = *sPtr;

      while (currentPtr != NULL)
      {
        previousPtr = currentPtr;
        currentPtr = previousPtr->nextPtr;
      }

      if (previousPtr == NULL)
      {
        newPtr->nextPtr = *sPtr;
        *sPtr = newPtr;
      }
      else
      {
        previousPtr->nextPtr = newPtr;
        newPtr->nextPtr = currentPtr;
      }
    }
    else
    {
      printf ("No available memory\n");
    }
  }
}


void
insert_char (CharListPtr *sPtr, char charactor, int char_pos)
{
  CharListPtr newPtr;
  CharListPtr previousPtr;
  CharListPtr currentPtr;
  int pos = 1;

  newPtr = malloc (sizeof (CharList));

  if (newPtr != NULL )
  {
    newPtr->charactor = charactor;
    newPtr->nextPtr = NULL;

    previousPtr = NULL;
    currentPtr = *sPtr;

    while (currentPtr != NULL && pos != char_pos)
    {
      previousPtr = currentPtr;
      currentPtr = previousPtr->nextPtr;
      pos++;
    }

    if (previousPtr == NULL)
    {
      newPtr->nextPtr = *sPtr;
      *sPtr = newPtr;
    }
    else
    {
      previousPtr->nextPtr = newPtr;
      newPtr->nextPtr = currentPtr;
    }

  }
  else
  {
    printf ("No available memory\n");
  }
}


void
print_char_list (CharListPtr currentPtr)
{
  if (currentPtr == NULL)
  {
    printf ("list is empty\n");
  }
  else
  {
    while (currentPtr != NULL)
    {
      printf ("%c\n", (currentPtr)->charactor);
      currentPtr = (currentPtr)->nextPtr;
    }
  }
}


void print_list (StrListPtr currentPtr) {
  if (currentPtr == NULL)
  {
    printf ("list is empty\n");
  }
  else
  {
    while (currentPtr != NULL)
    {
      printf ("%s\n", currentPtr->line);
      currentPtr = currentPtr->nextPtr;
    }
  }
}


void
print_char (CharListPtr currentPtr, int char_pos)
{
  int pos = 1;

  if (currentPtr == NULL)
  {
    printf ("list is emptya\n");
  }
  else
  {
    while (currentPtr != NULL && pos < char_pos)
    {
      currentPtr = currentPtr->nextPtr;
      pos++;
    }
    printf ("%c\n", currentPtr->charactor);
  }
}

struct strlist
{
  char *line;
  struct strlist *nextPtr;
};

typedef struct strlist StrList;
typedef StrList * StrListPtr;


int insert_line (StrListPtr *sPtr, char *line,  int line_no)
{
  StrListPtr newPtr;
  StrListPtr previousPtr;
  StrListPtr currentPtr;
  int current_line = 1;

  newPtr = malloc (sizeof (StrList));

  if (newPtr != NULL )
  {
    newPtr->line = line;
    newPtr->nextPtr = NULL;

    previousPtr = NULL;
    currentPtr = *sPtr;

    while (currentPtr != NULL && current_line != line_no)
    {
      previousPtr = currentPtr;
      currentPtr = previousPtr->nextPtr;
      current_line++;
    }

    if (previousPtr == NULL)
    {
      newPtr->nextPtr = *sPtr;
      *sPtr = newPtr;
    }
    else
    {
      previousPtr->nextPtr = newPtr;
      newPtr->nextPtr = currentPtr;
    }

  }
  else
  {
    printf ("No available memory\n");
  }
}


void print_line (StrListPtr currentPtr, int line) {
  int current_line = 1;

  if (currentPtr == NULL)
  {
    printf ("list is empty\n");
  }
  else
  {
    while (currentPtr != NULL && current_line < line)
    {
      currentPtr = currentPtr->nextPtr;
      current_line++;
    }
    printf ("%s\n", currentPtr->line);
  }
}

void
sort_word ()
{
    int i, j;
    char str[10][50], temp[50];

    printf("Enter 10 words:\n");

    for(i=0; i<10; ++i)
        scanf("%s[^\n]",str[i]);


    for(i=0; i<9; ++i)
        for(j=i+1; j<10 ; ++j)
        {
            if(strcmp(str[i], str[j])>0)
            {
                strcpy(temp, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], temp);
            }
        }

    printf("\nIn lexicographical order: \n");
    for(i=0; i<10; ++i)
    {
        puts(str[i]);
    }
}

void SplitStringsInPlace
(
  char c,
  char* pString,
  char** pSplitStarts,
  int maxSplits
)
{
      assert( maxSplits > 1 && pSplitStarts != NULL && pString != NULL && c != '\0' );

      while ( maxSplits-- > 1 ) // 1, because we need space for the terminator
      {
        *pSplitStarts++ = pString;
        while ( *pString != '\0' )
        {
           if ( *pString == c )
           {
               *pString++ = '\0';
               break;
           }
           pString++;
        }

        if (*pString == '\0')
          break;
      }

      *pSplitStarts = NULL;
    }

int main()
{
  char a[] = "one";
  char *b = "three";
  char *c = "two";
  char *d = "zero";
  char *e = "five";
  char *f = "six";
  char *g = "four";



  StrListPtr list = NULL;

  insert_line (&list, a, 1);
  insert_line (&list, b, 2);
  insert_line (&list, c, 2);
  insert_line (&list, d, 1);
  insert_line (&list, e, 5);
  insert_line (&list, f, 6);
  insert_line (&list, g, 5);

  print_list (list);

  print_line (list, 6);

  return 0;
}

#endif
