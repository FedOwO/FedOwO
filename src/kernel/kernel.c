#include "kernel.h"

void kernel_main() {
    clear_screen();

    char* video_memory = VIDEO_ADDRESS;

    for (int i = 0; i < 10; i++) {
        char* num = NULL;
        char *Owos = "OWOS (Operating Working Operating System)";
        for (int i = 0; Owos[i]; i++) {
            video_memory[i * 2] = Owos[i];
            video_memory[i * 2 + 1] = WHITE_ON_BLACK;
        }

        int_to_ascii(i, num);
        for (int j = 0; j < strlen(num); j++) {
            video_memory[MAX_COLS + i * 2] = num[j];
            video_memory[MAX_COLS + i * 2 + 1] = WHITE_ON_BLACK;
        }
    }
}
