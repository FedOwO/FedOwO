#include "screen.h"

void clear_screen() {
    int i;
    int screen_size = MAX_COLS * MAX_ROWS;
    int *screen = (int*) VIDEO_ADDRESS;

    for (i = 0; i < screen_size; i++) {
        screen[i * 2] = ' ';
        screen[i * 2 + 1] = WHITE_ON_BLACK;
    }
    set_cursor_offset(0);
}
