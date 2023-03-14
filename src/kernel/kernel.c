#include "kernel.h"

void kernel_main() {
    clear_screen();
    isr_setup();
    int sec = 0;
    kprint("Loading Kernel of FluffOS..\n");
    kprint("Booting into kernel.\n");
    while (sec != 6) {
        char *str = (char *) get_cursor_offset();
        int_to_ascii(sec, str);
        kprint(str);
        kprint(" seconds passed\n");
        sleep(1000);
        sec++;
    }
    kprint("Done!\n");
}
