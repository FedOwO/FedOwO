#include "kernel.h"

void kernel_main() {
    clear_screen();
    kprint("Loading Kernel of FluffOS..\n");
    kprint("Booting into kernel.\n");
    while (1) {
        kprint("1 second passed\n");
        sleep(1000);
    }

}
