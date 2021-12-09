#ifndef EC_FILE_H
#define EC_FILE_H


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


void ecfile_ECFile_init ( ECFilePtr obj, char *file_name );
void ecfile_ECFile_parse ( ECFilePtr obj );






#define NUM_LINES 4000

/* Statement types */
enum _BlockType
{
  FILE_OBJECT,
  OBJECT,
  FUNCTION,
  METHOD
};

typedef enum _BlockType BlockType;

/* EcWord */
struct _EcWord
{
  int type;
  char *text;
};

typedef struct _EcWord EcWord;

/* EcBlock */
struct _EcBlock
{
  BlockType type;
  char *name;
  int level;
  EcWord words[100];
};

typedef struct _EcBlock EcBlock;

/* EcFileLine */
struct _EcFileLine
{
  int number;
  char text[200];
};

typedef struct _EcFileLine EcFileLine;

/* ECFile */
struct _EcFile
{
  char *name;
  char *type;
  EcFileLine lines[NUM_LINES];
  EcBlock blocks[];
};

typedef struct _EcFile EcFile;

void
ec_read (EcFile *obj, char *file_name);

#endif // EC_FILE_H
