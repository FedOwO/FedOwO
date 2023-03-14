#include "screen.h"

int get_offset(int col, int row) {
    return 2 * (row * MAX_COLS + col);
}
int get_offset_row(int offset) {
    return offset / (2 * MAX_COLS);
}
int get_offset_col(int offset) {
    return (offset - (get_offset_row(offset)*2*MAX_COLS))/2;
}
