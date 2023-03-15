#include "kernel.h"

void kernel_main() {
    clear_screen();
    isr_setup();
    asm volatile("sti");
    init_timer(10);/*comment to hide tick of the clock*/
    init_keyboard();
    kprint("Loading Kernel of FluffOS..\n");
    kprint("Booting into kernel.\n");
    kprint("Done!\n");
}
