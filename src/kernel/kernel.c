#include "kernel.h"

void kernel_main() {
    clear_screen();
    kprint("Loading Kernel of FluffOS..\n");
    kprint("Booting into kernel..\n");
    char *str = (char *)get_cursor_offset();
    int_to_ascii((int)(100 * cos((float)1, 500)), str);
    kprint(str);
}
