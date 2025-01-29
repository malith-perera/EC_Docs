#ifndef EC_FILE_H
#define EC_FILE_H


#define EC_Line(...) \
    printf ("%s:%d In function '%s':%s\n", __FILE__, __LINE__, __func__, ARG1(__VA_ARGS__));


typedef struct _ECLine {
	char *text;
	struct ECLine * nextPtr;
} ECLine;

typedef ECLine * ECLinePtr;


struct _ECFile {
	char *name;
	ECLinePtr lines;
	struct _ECFile * nextPtr;
};

typedef struct _ECFile ECFile;
typedef ECFile * ECFilePtr;


void ecfile_ECFile_init ( ECFilePtr ec_file, char *file_name );
void ecfile_ECFile_parse ( ECFilePtr ec_file );


#define NUM_LINES 4000

/* Statement types */
typedef enum BlockType
{
  FILE_OBJECT,
  OBJECT,
  FUNCTION,
  METHOD
} BlockType;


/* EcWord */
typedef struct EcWord
{
  int type;
  char *text;
} EcWord;


/* EcBlock */
typedef struct EcBlock
{
  BlockType type;
  char *name;
  int level;
  EcWord words[100];
} EcBlock;


/* EC_FileLine */
typedef struct EC_FileLine
{
  int number;
  char text[200];
} EC_FileLine;


/* ECFile */
typedef struct EC_File
{
  char *name;
  char *type;
  EC_FileLine lines[NUM_LINES];
  EcBlock blocks[];
} EC_File;

void
EC_Read (EC_File *ec_file);

typedef enum {
    EMPTY,
    NONE_EMPTY,
    CODE_LINE,
    FIRST_SLASH,
    SINGLE_LINE,
    MULTI_LINE_IN,
    MULTI_LINE_IN_END,
    MULTI_LINE
} LineType;


void
EC_Lines_Of_Code (char* filename);


void
EC_Total_Lines_Of_Code(char *directory, char filetype);

#endif // EC_FILE_H
