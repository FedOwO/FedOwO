void kernel_main() {
    char* video_memory = (char*) 0xb8000;
    for (int i = 0; i < 256; i++)
    {
        *video_memory++;
        *video_memory = i;
    }
}
