#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <dirent.h>
#include "ec_file.h"
#include "ec_error.h"

#define DEBUG 0

typedef struct ecfile {
	char *name;
	char *type;
	char *lines[];
} ecfile;


void ecfile_ECFile_init ( ECFilePtr ec_file, char *file_name )
{
	ec_file->name = file_name;
}

// lines of code
char *line_type_name[] = {
    "EMPTY",
    "NONE_EMPTY",
    "CODE_LINE",
    "FIRST_SLASH",
    "SINGLE_LINE",
    "MULTI_LINE_IN",
    "MULTI_LINE_IN_END",
    "MULTI_LINE"
};



void ecfile_ECFile_parse ( ECFilePtr ec_file )
{
	FILE *fPtr;
	char c;
	int counter = 0;

	if ( ( fPtr = fopen ( ec_file->name, "r" ) ) == NULL ) {
     		printf ( "File opening Error: %s file not found\n", ec_file->name );
		exit ( EXIT_SUCCESS );
	}
	else {
		while ( ( c = fgetc(fPtr ) ) != EOF ) {
			switch ( c ) {
				case '\n':
					printf ( "\n%d\n", counter );
					counter = 0;
			}
			printf ( "%c", c );
			counter++;
		}
#if 0
    while (fgets (line, sizeof (line), file) != NULL ) /* read a line */
    {
      fputs (line, stdout); /* write the line */

      /* get the first token */
      token = strtok (line, " ");

      col = 0;
      /* walk through other tokens */
      while (token != NULL) {
//        printf (" %s\n", token);
        map [row][col] =  atoi (token);
        token = strtok (NULL, " ");
        col++;
      }

      row++;
    }
#endif

		fclose(fPtr);
	}

}


void split ()
{
}


// ECFile Methods

int line_counter = 0;

void
EC_Read (EC_File *ec_file)
{
    FILE *fPtr;
    char c;
    int line_char = 0;

    if ((fPtr = fopen (ec_file->name, "r")) == NULL) {
        //ec_error (FILE_ERROR, ec_file->name , 0, 0, "");
    }
    else {
        while ((c = fgetc(fPtr)) != EOF) {
            switch (c) {
                case '\n':
                    ec_file->lines[line_counter].text[line_char] = '\0';
                    ec_file->lines[line_counter].number = line_counter++;
                    line_char = 0;
                    break;
                default:
                    ec_file->lines[line_counter].text[line_char] = c;
                    line_char++;
            }
        }
        fclose (fPtr);
    }
}


void
ec_block (EC_File *ec_file) {
  int i = 0;
  int j = 0;
  int const indent;
  unsigned long pos;

  BlockType block = FILE_OBJECT;

  for (i = 0; i < line_counter; i++) {
    for (pos = 0; pos < (unsigned long) sizeof(ec_file->lines[i].text); pos++) {
      printf("%c", ec_file->lines[i].text[pos]);

   }
  }
}


// printf ("%c", ec_file->lines[i].text[j]);
/*      if (block == FILE_OBJECT && ec_file->lines[i].text[j] == '\n' && i == 0 && i == 0)
        break;

      if (block == FILE_OBJECT && isspace(ec_file->lines[i].text[j]))
        continue;
*/


void
EC_Lines_Of_Code (char* filename)
{
    FILE* f = fopen(filename, "r");

    static int total_lines = 0;
    static int total_code_lines = 0;

    if (f != NULL)
    {
        char        c;
        int         lines           = 0;
        int         comment_lines   = 0;
        int         empty_lines     = 0;
        int         file_lines     = 0;
        LineType    line_type       = EMPTY;


        while ((c = fgetc(f)) != EOF)
        {
            if (DEBUG)
            {
                if (c != '\n')
                    printf ("%c", c);
            }

            if (c != '\n')
            {
                if (line_type == EMPTY)
                {
                    if  (!(c == ' ' || c == '{' || c == '}'))
                    {
                        if (c == '/')
                        {
                            line_type = FIRST_SLASH;
                        }
                        else
                        {
                            line_type = CODE_LINE;
                        }

                        continue;
                    }

                }

                if (line_type == FIRST_SLASH && c == '/')
                {
                    line_type = SINGLE_LINE;
                }
                else if (line_type == FIRST_SLASH && c == '*')
                {
                    line_type = MULTI_LINE_IN;
                }
                else if (line_type == FIRST_SLASH && c != '/')
                {
                    line_type = CODE_LINE;
                }
                else if (line_type == FIRST_SLASH && c != '*')
                {
                    line_type = EMPTY;
                }
                else if (line_type == MULTI_LINE_IN && c == '*')
                {
                    line_type = MULTI_LINE_IN_END;
                }
                else if (line_type == MULTI_LINE_IN_END && c != '/')
                {
                    line_type = MULTI_LINE_IN;
                }
                else if (line_type == MULTI_LINE_IN_END && c == '/')
                {
                    line_type = MULTI_LINE;
                }
            }
            else
            {
                if (DEBUG)
                {
                    printf (" <%s>\n", line_type_name[line_type]);
                }

                if (line_type == EMPTY)
                {
                    empty_lines++;
                }

                if (line_type == CODE_LINE)
                {
                    lines++;
                    line_type = EMPTY;
                }

                if (line_type == SINGLE_LINE)
                {
                    comment_lines++;
                    line_type = EMPTY;
                }
                else if (line_type == MULTI_LINE_IN)
                {
                    comment_lines++;
                }
                else if (line_type == MULTI_LINE_IN_END)
                {
                    comment_lines++;
                    line_type = MULTI_LINE_IN;
                }
                else if (line_type == MULTI_LINE)
                {
                    comment_lines++;
                    line_type = EMPTY;
                }

                file_lines++;
            }
        }

        total_code_lines += lines;
        total_lines += file_lines;

        printf("File            : %s\n", filename);
        printf("Code lines      : %d\n", lines);
        printf("Comment lines   : %d\n", comment_lines);
        printf("Empty lines     : %d\n", empty_lines);
        printf("All lines       : %d\n", file_lines);
        printf("\n");
        printf("Total Code lines: %d\n", total_code_lines);
        printf("Total lines     : %d\n\n", total_lines);

        fclose(f);
    }
    else
    {
        fprintf(stderr, "file not found\n");
    }
}

void
EC_Total_Lines_Of_Code(char *directory, char filetype)
{
    DIR *dir;
    struct dirent *dn;
    char file_name[512];

    dir = opendir(directory);

    if (dir) {
        while ((dn = readdir(dir)) != NULL) {
            for(int i = 0; i < strlen(dn->d_name); i++) { 
                if (dn->d_name[i] == '.') {
                    if(dn->d_name[i + 1] == filetype && dn->d_name[i + 2] == '\0') {
                        sprintf(file_name, "%s/%s", directory, dn->d_name);
                        EC_Lines_Of_Code(file_name);
                        break;
                    }
                }
            }
        }
        closedir(dir);
    }
}
