#include "kernel.h"

void kernel_main() {
    clear_screen();
    kprint("Loading Kernel of FluffOS..\n");
    kprint("Booting into kernel.\n");
    isr_setup();
    asm volatile("sti");
    init_timer(10);/*kprint in the callbask will be soon removed */
    init_keyboard();
    kprint("\nWelcome into FluffOs!\n");
}
