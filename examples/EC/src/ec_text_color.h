#ifndef EC_TEXT_COLOR_H
#define EC_TEXT_COLOR_H

#include "ec.h"

// use an enum for platform-independent interface:
typedef enum TextColor
{
    EC_BLACK = 0,
    EC_BLUE = 1,
    EC_GREEN = 2,
    EC_CYAN = 3,
    EC_RED = 4,
    EC_MAGENTA = 5,
    EC_BROWN = 6,
    EC_LIGHTGRAY = 7,
    EC_DARKGRAY = 8,
    EC_LIGHTBLUE = 9,
    EC_LIGHTGREEN = 10,
    EC_LIGHTCYAN = 11,
    EC_LIGHTRED = 12,
    EC_LIGHTMAGENTA = 13,
    EC_YELLOW = 14,
    EC_WHITE = 15
} TextColor;


// set output color on the given stream:
void EC_Set_Text_Color(FILE *stream, TextColor color);

void Reset_Text_Color ();

#endif // EC_TEXT_COLOR_H

