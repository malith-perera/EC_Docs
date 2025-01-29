#ifdef _WIN32
#include <windows.h>    // for win32 API functions
#include <io.h>         // for _get_osfhandle()
#else
#ifndef _POSIX_SOURCE
#define _POSIX_SOURCE   // enable POSIX extensions in standard library headers
#endif
#include <unistd.h>     // for isatty()
#endif

#include <stdlib.h>
#include <stdio.h>

#include "ec_text_color.h"

#ifdef _WIN32

void EC_Set_Text_Color(FILE *stream, TextColor color)
{
    int outfd = fileno(stream);
    HANDLE out = (HANDLE)_get_osfhandle(outfd);
    DWORD outType = GetFileType(out);
    DWORD mode;
    if (outType == FILE_TYPE_CHAR && GetConsoleMode(out, &mode))
    {
        // we're directly outputting to a win32 console if the file type
        // is FILE_TYPE_CHAR and GetConsoleMode() returns success

        SetConsoleTextAttribute(out, color);
        // the enum constants are defined to the same values
        // SetConsoleTextAttribute() uses, so just pass on.
    }
}

#else

static const char
*ansiColorSequences[] = {
    "\x1B[0;30m",
    "\x1B[0;34m",
    "\x1B[0;32m",
    "\x1B[0;36m",
    "\x1B[0;31m",
    "\x1B[0;35m",
    "\x1B[0;33m",
    "\x1B[0;37m",
    "\x1B[1;30m",
    "\x1B[1;34m",
    "\x1B[1;32m",
    "\x1B[1;36m",
    "\x1B[1;31m",
    "\x1B[1;35m",
    "\x1B[1;33m",
    "\x1B[1;37m",
};

static const char
*ansiColorTerms[] = {
    "xterm",
    "rxvt",
    "vt100",
    "linux",
    "screen",
    0
    // there are probably missing a few others
};

// get current terminal and check whether it's in our list of terminals
// supporting ANSI colors:
static int isAnsiColorTerm(void)
{
    char *term = getenv("TERM");
    for (const char **ansiTerm = &ansiColorTerms[0]; *ansiTerm; ++ansiTerm)
    {
        int match = 1;
        const char *t = term;
        const char *a = *ansiTerm;
        while (*a && *t)
        {
            if (*a++ != *t++)
            {
                match = 0;
                break;
            }
        }
        if (match) return 1;
    }
    return 0;
}

void EC_Set_Text_Color(FILE *stream, TextColor color)
{
    int outfd = fileno(stream);
    if (isatty(outfd) && isAnsiColorTerm())
    {
        // we're directly outputting to a terminal supporting ANSI colors,
        // so send the appropriate sequence:
        fputs(ansiColorSequences[color], stream);
    }
}

void Reset_Text_Color ()
{
    printf("\033[0m");
}


void print_colors ()
{
    printf("\x1B[0;30m 0;30m color \033[0m\n");
    printf("\x1B[0;31m 0;31m color \033[0m\n");
    printf("\x1B[0;32m 0;32m color \033[0m\n");
    printf("\x1B[0;33m 0;33m color \033[0m\n");
    printf("\x1B[0;34m 0;34m color \033[0m\n");
    printf("\x1B[0;35m 0;35m color \033[0m\n");
    printf("\x1B[0;36m 0;36m color \033[0m\n");
    printf("\x1B[0;37m 0;37m color \033[0m\n");
    printf("\x1B[1;30m 1;30m color \033[0m\n");
    printf("\x1B[1;31m 1;31m color \033[0m\n");
    printf("\x1B[1;32m 1;32m color \033[0m\n");
    printf("\x1B[1;33m 1;33m color \033[0m\n");
    printf("\x1B[1;34m 1;34m color \033[0m\n");
    printf("\x1B[1;35m 1;35m color \033[0m\n");
    printf("\x1B[1;36m 1;36m color \033[0m\n");
    printf("\x1B[1;37m 1;37m color \033[0m\n");
}

#endif

/*int main(void)*/
/*{*/
    /*puts("Color test.");*/
    /*EC_Set_Text_Color(stdout, EC_YELLOW);*/
    /*puts("This is green!\n");*/
    /*printf ("This also may\n");*/
    /*EC_Set_Text_Color(stdout, EC_LIGHTGRAY);*/
    /*puts("back to normal.");*/
    /*return EXIT_SUCCESS;*/
/*}*/
