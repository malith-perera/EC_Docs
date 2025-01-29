#include "ec_version.h"

void
EC_Version_Change
(
    char    *argv[],
    char    *path,
    int     years,
    int     months,
    int     days
)
{
    char sentence[256];
    char version_h_path[256];

	sprintf(sentence, 
		"#ifndef %s_VERSION_H\n"
		"#define %s_VERSION_H\n\n"
		"#define %s_VERSION_YEARS %d\n"
		"#define %s_VERSION_MONTHS %d\n"
		"#define %s_VERSION_ADD_FIX %d\n\n"
		"#endif // %s_VERSION_H\n", argv[2], argv[2], argv[2], years, argv[2], months, argv[2], days, argv[2]);
    
    //printf ("version.h lenght %ld", strlen(sentence));

    sprintf(version_h_path, "%s%s%s%s", path, "/src/", argv[2], "_version.h");

    // creating file pointer to work with files
    FILE *fptr;

    // opening file in writing mode
    fptr = fopen(version_h_path, "w");

    // exiting program 
    if (fptr == NULL) {
        printf("Error: app lib version.h cannot be created\n");
        exit(1);
    }

    fprintf(fptr, "%s", sentence);
    fclose(fptr);
}


void
EC_Version_Update(char *argv[], char *path)
{
    // *** Get the updated version number
    EC_Version_Change(argv, path, 0, 0, 0);
}
