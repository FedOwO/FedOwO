#ifndef screen_h
    #define screen_h
    #define WHITE_ON_BLACK 0x0f
    #define RED_ON_WHITE 0xf4

    #define VIDEO_ADDRESS (char*) 0xb8000
    #define MAX_ROWS 25
    #define MAX_COLS 80

    #define REG_SCREEN_CTRL 0x3d4
    #define REG_SCREEN_DATA 0x3d5

    #include "../ports/ports.h"

void clear_screen();
int get_cursor_offset();
void kprint(char *message);
int get_offset_row(int offset);
int get_offset_col(int offset);
int get_offset(int col, int row);
void set_cursor_offset(int offset);
void kprint_at(char *message, int col, int row);
int print_char(char c, int col, int row, char attr);

#endif
