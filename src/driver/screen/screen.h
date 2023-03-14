#ifndef screen_h
    #define screen_h
    #define VIDEO_ADDRESS (char*) 0xb8000
    #define WHITE_ON_BLACK 0x0f
    #define MAX_ROWS 25
    #define MAX_COLS 160

void clear_screen();

#endif
